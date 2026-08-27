# Copyright 2024 NWChemEx-Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import unittest

import numpy as np
import simde
from chemist import Electron, Nuclei, PointD, ShellType
from chemist.basis_set import AOBasisSetD, AtomicBasisSetD, ContractedGaussianD
from chemist.braket import BraKet
from chemist.qm_operator import (
    CoreHamiltonian,
    Coulomb,
    Fock,
    Hamiltonian,
    Identity,
    Kinetic,
)
from chemist.wavefunction import AOs, CMOs, DeterminantCMOs
from tensorwrapper import Tensor


def h2_aos():
    coefs = [0.1543289673, 0.5353281423, 0.4446345422]
    exps = [3.425250914, 0.6239137298, 0.1688554040]
    rv = AOBasisSetD()
    for z in (0.0, 1.3983972315):
        center = PointD(0.0, 0.0, z)
        atom = AtomicBasisSetD("STO-3G", 1, center)
        cg = ContractedGaussianD(coefs, exps, center)
        atom.add_shell(ShellType.cartesian, 0, cg)
        rv.add_center(atom)
    return AOs(rv)


def h2_determinant():
    aos = h2_aos()
    transform = Tensor(np.array([[1.0, 1.0], [1.0, -1.0]]))
    cmos = CMOs(Tensor(np.array([-0.5, 0.5])), aos, transform)
    return DeterminantCMOs([0], cmos)


class TestBraKetRoundTrip(unittest.TestCase):
    """Checks that a Python BraKet survives PluginPlay's input pipeline.

    Chemist exports a single, erased BraKet class; the C++ instantiation each
    EvaluateBraKet property type wants is resolved at conversion time. That
    conversion happens inside PluginPlay: wrap_inputs stores the Python object
    as an opaque PythonWrapper, and unwrap_inputs casts it to the field's
    declared C++ type. These tests drive exactly that pair, which is what a
    module sees when it is handed a BraKet from Python. Without a matching
    Chemist BraKet export, unwrap_inputs here raises.
    """

    def setUp(self):
        self.aos = h2_aos()
        self.aos2 = (self.aos, self.aos)
        self.psi = h2_determinant()
        self.t_e = Kinetic(Electron())
        self.v_ee = Coulomb(Electron(), Electron())

    def _round_trip(self, pt, bra, op, ket):
        braket = BraKet(bra, op, ket)
        inputs = pt.wrap_inputs(pt.inputs(), braket)
        (unwrapped,) = pt.unwrap_inputs(inputs)
        self.assertEqual(unwrapped.bra, bra)
        self.assertEqual(unwrapped.op, op)
        self.assertEqual(unwrapped.ket, ket)

    def test_one_electron_property_types(self):
        cases = [
            (simde.aos_s_e_aos(), Identity()),
            (simde.aos_t_e_aos(), self.t_e),
            (
                simde.aos_v_en_aos(),
                Coulomb(Electron(), Nuclei()),
            ),
            (simde.aos_h_e_aos(), CoreHamiltonian()),
            (simde.aos_f_e_aos(), Fock()),
        ]
        for pt, op in cases:
            with self.subTest(pt=type(pt).__name__):
                self._round_trip(pt, self.aos, op, self.aos)

    def test_electron_repulsion_integrals(self):
        self._round_trip(simde.ERI2(), self.aos, self.v_ee, self.aos)
        self._round_trip(simde.ERI3(), self.aos, self.v_ee, self.aos2)
        self._round_trip(simde.ERI4(), self.aos2, self.v_ee, self.aos2)

    def test_scf_energy(self):
        self._round_trip(simde.ESCF_CMOs(), self.psi, Hamiltonian(), self.psi)

    def test_erased_operator_property_type(self):
        """aos_op_base_aos is the entry point the AO integral drivers use.

        Its BraKet's operator type is the abstract OperatorBase, so any
        operator has to widen into it.
        """
        for op in (Identity(), self.t_e, self.v_ee, Fock(), CoreHamiltonian()):
            with self.subTest(op=type(op).__name__):
                braket = BraKet(self.aos, op, self.aos)
                pt = simde.aos_op_base_aos()
                inputs = pt.wrap_inputs(pt.inputs(), braket)
                (unwrapped,) = pt.unwrap_inputs(inputs)
                self.assertTrue(unwrapped.op.are_equal(op))

    def test_wrong_property_type_is_rejected(self):
        """A BraKet the property type does not want fails the bounds check.

        ModuleInput type-checks on the way in, so this is caught at
        wrap_inputs rather than being deferred to the module's unwrap.
        """
        braket = BraKet(self.aos, self.t_e, self.aos)
        pt = simde.ERI2()
        with self.assertRaises(ValueError):
            pt.wrap_inputs(pt.inputs(), braket)

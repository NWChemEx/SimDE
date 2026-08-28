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
import parallelzone as pz
import pluginplay as pp
import simde
from chemist import Electron
from chemist.braket import BraKet
from chemist.qm_operator import Kinetic
from tensorwrapper import Tensor

from .test_braket_round_trip import h2_aos


class KineticStub(pp.ModuleBase):
    """A module that takes a BraKet and reports what it received.

    The point is not the math, it is the plumbing: a BraKet built in Python
    has to travel through ModuleManager.run_as, be stored type-erased inside
    PluginPlay, and come back out here as the C++
    BraKet<AOs, Kinetic<Electron>, AOs> that simde.aos_t_e_aos declares.
    """

    seen = None

    def __init__(self):
        pp.ModuleBase.__init__(self)
        self.description("Records the BraKet it is given")
        self.satisfies_property_type(simde.aos_t_e_aos())

    def run_(self, inputs, submods):
        pt = simde.aos_t_e_aos()
        (braket,) = pt.unwrap_inputs(inputs)
        KineticStub.seen = (braket.bra, braket.op, braket.ket)
        n = braket.bra.size()
        return pt.wrap_results(self.results(), Tensor(np.zeros((n, n))))


class TestBraKetThroughAModule(unittest.TestCase):
    def setUp(self):
        KineticStub.seen = None
        self.mm = pp.ModuleManager(pz.runtime.RuntimeView())
        self.mm.add_module("Kinetic Stub", KineticStub())
        self.aos = h2_aos()
        self.t_e = Kinetic(Electron())

    def test_run_as_with_a_python_braket(self):
        braket = BraKet(self.aos, self.t_e, self.aos)
        rv = self.mm.run_as(simde.aos_t_e_aos(), "Kinetic Stub", braket)

        # The module got the right pieces back out...
        bra, op, ket = KineticStub.seen
        self.assertEqual(bra, self.aos)
        self.assertEqual(op, self.t_e)
        self.assertEqual(ket, self.aos)

        # ...and used them: h2 has two AOs, so the result is 2 by 2.
        self.assertEqual(rv, Tensor(np.zeros((2, 2))))

    def test_run_as_with_the_wrong_braket(self):
        braket = BraKet(self.aos, self.t_e, (self.aos, self.aos))
        with self.assertRaises(ValueError):
            self.mm.run_as(simde.aos_t_e_aos(), "Kinetic Stub", braket)
        self.assertIsNone(KineticStub.seen)

# Copyright 2023 NWChemEx-Project
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

import simde
from test_property_type import BaseTestPropertyType


class TestAtomicBasisSetFromZ(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.AtomicBasisSetFromZ()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Atomic Basis Set']


class TestAtomicBasisSetFromSym(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.AtomicBasisSetFromSym()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Atomic Basis Set']


class TestMolecularBasisSet(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.MolecularBasisSet()
        self.input_labels = ['Molecule']
        self.result_labels = ['Molecular Basis Set']

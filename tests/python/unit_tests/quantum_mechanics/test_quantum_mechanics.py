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

import simde
from test_property_type import BaseTestPropertyType


class TestFockOperator_e_density(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.FockOperator_e_density()
        self.input_labels = ["Hamiltonian", "Density"]
        self.result_labels = ["Fock operator"]


class TestFockOperator_decomposable_e_density(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.FockOperator_decomposable_e_density()
        self.input_labels = ["Hamiltonian", "Density"]
        self.result_labels = ["Fock operator"]


class TestRSCFGuess(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.RSCFGuess()
        self.input_labels = ["Hamiltonian", "AOs"]
        self.result_labels = ["Initial Wavefunction"]


class TestUpdateRSCFGuess(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.UpdateRSCFGuess()
        self.input_labels = ["New Fock Operator", "Old guess"]
        self.result_labels = ["New guess"]

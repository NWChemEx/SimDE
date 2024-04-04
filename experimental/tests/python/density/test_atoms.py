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


class TestSCFDensity(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.SCFDensity()
        self.input_labels = ['Phi0']
        self.result_labels = ['Density']


class TestInitialDensity(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.InitialDensity()
        self.input_labels = ['Hamiltonian']
        self.result_labels = ['Density']


class TestSCFGuessDensity(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.SCFGuessDensity()
        self.input_labels = ['Hamiltonian', 'Input Space']
        self.result_labels = ['Output Density']


class TestSCFDensityStep(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.SCFDensityStep()
        self.input_labels = ['Hamiltonian', 'Input Space']
        self.result_labels = ['Output Density']

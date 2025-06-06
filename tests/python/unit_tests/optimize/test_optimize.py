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

inp_desc = 'Object to optimize the objective function with respect to'
out_desc = 'Object that optimizes the objective function'


class TestOptimizeRSCFEnergyWRTRSCFWavefunction(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.OptimizeRSCFEnergyWRTRSCFWavefunction()
        self.input_labels = ['BraKet', inp_desc]
        self.result_labels = ['tensor representation', out_desc]


class TestTotalEnergyNuclearOptimization(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.TotalEnergyNuclearOptimization()
        self.input_labels = ['Chemical System', inp_desc]
        self.result_labels = ['Energy', out_desc]


class TestAOEnergyNuclearOptimization(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.AOEnergyNuclearOptimization()
        self.input_labels = ['Chemical System', 'AOs', inp_desc]
        self.result_labels = ['Energy', out_desc]

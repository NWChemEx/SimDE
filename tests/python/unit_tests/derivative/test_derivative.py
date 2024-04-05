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


class TestAOEnergyNuclearGradientD(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.provisional.AOEnergyNuclearGradientD()
        self.input_labels = ["AOs", "Chemical System", "Arg 1"]
        self.result_labels = ["Derivative"]


class TestAOEnergyNuclearHessianD(BaseTestPropertyType):

    def setUp(self):
        self.pt = simde.provisional.AOEnergyNuclearHessianD()
        self.input_labels = ["AOs", "Chemical System", "Arg 1", "Arg 2"]
        self.result_labels = ["Derivative"]

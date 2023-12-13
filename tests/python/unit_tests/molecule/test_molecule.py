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

class TestMoleculeFromString(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.MoleculeFromString()
        self.input_labels= ['String']
        self.result_labels = ['Molecule']

class TestMoleculeToMolecule(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.MoleculeToMolecule()
        self.input_labels= ['Initial molecule']
        self.result_labels = ['Final molecule']
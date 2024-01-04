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

import experimental_simde as simde
from test_property_type import BaseTestPropertyType

class TestAtomDenFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomDenFromZ()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Atomic Density']

class TestAtomDenFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomDenFromSym()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Atomic Density']

class TestElecConfigFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ElecConfigFromZ()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Electronic Configuration']

class TestElecConfigFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ElecConfigFromSym()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Electronic Configuration']

class TestFracConfigFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.FracConfigFromZ()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Electronic Configuration']

class TestFracConfigFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.FracConfigFromSym()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Electronic Configuration']

class TestFullConfigFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.FullConfigFromZ()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Electronic Configuration']

class TestFullConfigFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.FullConfigFromSym()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Electronic Configuration']

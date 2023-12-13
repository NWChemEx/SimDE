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

class TestAtomFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomFromZ()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Atom']

class TestAtomFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomFromSym()
        self.input_labels = ['Atom ID']
        self.result_labels = ['Atom']

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

class testSymbolFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.SymbolFromZ()
        self.input_labels = ['Z']
        self.result_labels = ['Symbol']

class testZFromSymbol(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ZFromSymbol()
        self.input_labels = ['Symbol']
        self.result_labels = ['Z']
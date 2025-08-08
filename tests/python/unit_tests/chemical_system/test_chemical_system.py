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
        self.input_labels = ["Atom ID"]
        self.result_labels = ["Atom"]


class TestAtomFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomFromSym()
        self.input_labels = ["Atom ID"]
        self.result_labels = ["Atom"]


class TestAtomicDensityMatrixFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomicDensityMatrixFromZ()
        self.input_labels = ["Atom ID"]
        self.result_labels = ["Atomic Density Matrix"]


class TestAtomicDensityMatrixFromSym(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.AtomicDensityMatrixFromSym()
        self.input_labels = ["Atom ID"]
        self.result_labels = ["Atomic Density Matrix"]


class testSymbolFromZ(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.SymbolFromZ()
        self.input_labels = ["Z"]
        self.result_labels = ["Symbol"]


class testZFromSymbol(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ZFromSymbol()
        self.input_labels = ["Symbol"]
        self.result_labels = ["Z"]

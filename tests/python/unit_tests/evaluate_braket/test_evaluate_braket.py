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


class Testaos_t_e_aos(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.aos_t_e_aos()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]


class Testaos_v_en_aos(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.aos_v_en_aos()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]


class Testaos_rho_e_cmos_aos(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.aos_rho_e_cmos_aos()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]


class TestERI2(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ERI2()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]


class TestERI3(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ERI3()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]


class TestERI4(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ERI4()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]


class TestESCF_CMOs(BaseTestPropertyType):
    def setUp(self):
        self.pt = simde.ESCF_CMOs()
        self.input_labels = ["BraKet"]
        self.result_labels = ["tensor representation"]

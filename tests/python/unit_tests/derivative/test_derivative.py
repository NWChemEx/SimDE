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
import pluginplay
import unittest

class TestEnergy(unittest.TestCase):
    def test_aoenergynucleargradient_pt(self):
        pt = simde.AOEnergyNuclearGradient()
        self.assertIn('AOs', pt.inputs())
        self.assertIn('Chemical System', pt.inputs())
        self.assertIn('Arg 1', pt.inputs())
        self.assertEqual(len(pt.inputs()), 3)
        self.assertIn('Derivative', pt.results())
        self.assertEqual(len(pt.results()), 1)

    def test_aoenergynuclearhessian_pt(self):
        pt = simde.AOEnergyNuclearHessian()
        self.assertIn('AOs', pt.inputs())
        self.assertIn('Chemical System', pt.inputs())
        self.assertIn('Arg 1', pt.inputs())
        self.assertIn('Arg 2', pt.inputs())
        self.assertEqual(len(pt.inputs()), 4)
        self.assertIn('Derivative', pt.results())
        self.assertEqual(len(pt.results()), 1)
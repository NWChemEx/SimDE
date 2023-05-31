import simde
import pluginplay
import unittest

class TestEnergy(unittest.TestCase):
    def test_energy_pt(self):
        pt = simde.Energy()
        self.assertIn('system', pt.inputs())
        self.assertIn('Energy', pt.results())

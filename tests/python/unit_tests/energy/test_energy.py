import simde
import pluginplay
import unittest

class TestEnergy(unittest.TestCase):
    def test_energy_pt(self):
        pt = simde.Energy()
        print(pt.inputs())

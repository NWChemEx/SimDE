#include "../test_property_type.hpp"
#include "simde/energy/ao_energy.hpp"

using namespace simde;

TEST_CASE("AOEnergy") { test_property_type<AOEnergy>({"system","AOs"}, {"Energy"}); }

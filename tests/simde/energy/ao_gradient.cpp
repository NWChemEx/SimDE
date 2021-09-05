#include "../test_property_type.hpp"
#include "simde/energy/ao_gradient.hpp"

using namespace simde;

TEST_CASE("AOGradient") {
    test_property_type<AOGradient>({"system", "AOs"}, {"Energy", "Gradient"});
}

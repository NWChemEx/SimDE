#include "test_property_type.hpp"
#include <property_types/energy.hpp>

using namespace simde;

TEST_CASE("Energy") {
    test_property_type<Energy<>>({"Molecule", "Derivative"}, {"Energy"});
}

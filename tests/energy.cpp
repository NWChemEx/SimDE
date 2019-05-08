#include "test_property_type.hpp"
#include <property_types/energy.hpp>

using namespace property_types;

TEST_CASE("Energy"){
    test_property_type<Energy<>>({"Molecule", "Derivative"},{"Energy"});
}

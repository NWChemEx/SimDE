#include "property_types/connectivity.hpp"
#include "test_property_type.hpp"

TEST_CASE("Connectivity") {
    test_property_type<property_types::Connectivity>({"Molecule"},
                                                     {"Connectivity Table"});
}

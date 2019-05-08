#include "test_property_type.hpp"
#include <property_types/aointegral.hpp>

TEST_CASE("AOIntegral"){
    test_property_type<property_types::AOIntegral<2>>(
      {"Molecule", "Basis Sets", "Derivative"},
      {"AO Integrals"}
    );
}

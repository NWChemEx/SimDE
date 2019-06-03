#include "test_property_type.hpp"
#include <property_types/lu.hpp>

TEST_CASE("LU"){
    test_property_type<property_types::LUFactorization<double>>(
      {"Input Matrix"},
      {"L", "U"}
    );
}


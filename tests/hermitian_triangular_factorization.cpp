#include "test_property_type.hpp"
#include <property_types/linear_algebra/hermitian_triangular_factorization.hpp>

TEST_CASE("BunchKaufman"){
    test_property_type<property_types::BunchKaufmanFactorization<double>>(
      {"Input Matrix", "Triangle"},
      {"Bunch Kaufman Factor", "D"}
    );
}


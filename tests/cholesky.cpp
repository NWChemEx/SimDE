#include "test_property_type.hpp"
#include <property_types/linear_algebra/cholesky.hpp>

TEST_CASE("Cholesky"){
    test_property_type<property_types::CholeskyFactorization<double>>(
      {"Input Matrix", "Triangle"},
      {"Cholesky Factor"}
    );
}


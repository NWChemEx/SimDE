#include "test_property_type.hpp"
#include <property_types/linear_algebra/positive_definite_triangular_factorization.hpp>

TEST_CASE("Cholesky"){
    test_property_type<property_types::CholeskyFactorization<double>>(
      {"Input Matrix", "Triangle"},
      {"Cholesky Factor"}
    );
}


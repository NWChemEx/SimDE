#include "test_property_type.hpp"
#include <property_types/matrix_inverse.hpp>

TEST_CASE("MatrixInverse"){
    test_property_type<property_types::MatrixInverse<double>>(
      {"Input Matrix"},
      {"Inverse"}
    );
}


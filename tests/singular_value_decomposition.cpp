#include "test_property_type.hpp"
#include <property_types/singular_value_decomposition.hpp>

TEST_CASE("SingularValueDecomposition") {
    test_property_type<property_types::SingularValueDecomposition<>>(
            {"Matrix"},
            {"S", "U", "V"});
}
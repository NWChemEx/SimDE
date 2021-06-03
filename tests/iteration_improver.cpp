#include "test_property_type.hpp"
#include <property_types/iteration_improver.hpp>

TEST_CASE("IterationImprover") {
    test_property_type<property_types::IterationImprover<>>(
      {"Initial Tensor", "Current Tensor", "Error Tensor"},
      {"Improved Tensor"});
}

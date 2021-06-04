#include "test_property_type.hpp"
#include <property_types/iteration_improver.hpp>

TEST_CASE("IterationImprover") {
    test_property_type<property_types::IterationImprover<>>(
      {"Initial Tensor", "Current Tensor", "Initial Error Tensor",
       "Current Error Tensor"},
      {"Improved Tensor"});
}

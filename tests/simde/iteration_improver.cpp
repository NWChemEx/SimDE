#include "simde/iteration_improver.hpp"
#include "test_property_type.hpp"

TEST_CASE("IterationImprover") {
    test_property_type<simde::IterationImprover<>>(
      {"Initial Tensor", "Current Tensor", "Initial Error Tensor",
       "Current Error Tensor"},
      {"Improved Tensor"});
}

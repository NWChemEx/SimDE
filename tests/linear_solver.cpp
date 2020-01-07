#include "test_property_type.hpp"
#include <property_types/linear_algebra/linear_solver.hpp>

TEST_CASE("LinearSolver"){
    test_property_type<property_types::LinearSolver<double,double,double>>(
      {"LHS", "RHS"},
      {"Solution"}
    );
}


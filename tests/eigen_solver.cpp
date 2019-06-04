#include "test_property_type.hpp"
#include <property_types/linear_algebra/eigen_solver.hpp>

TEST_CASE("SelfAdjointEigenSolver"){
    test_property_type<property_types::SelfAdjointEigenSolver<double,double>>(
      {"Input Matrix"},
      {"Eigenvalues","Eigenvectors"}
    );
}
TEST_CASE("GeneralizedSelfAdjointEigenSolver"){
    test_property_type<property_types::GeneralizedSelfAdjointEigenSolver<double,double,double>>(
      {"Input Matrix", "Input Metric"},
      {"Eigenvalues","Eigenvectors"}
    );
}


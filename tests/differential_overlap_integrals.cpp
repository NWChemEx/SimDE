#include "test_property_type.hpp"
#include <property_types/differential_overlap_integral.hpp>

TEST_CASE("DifferentialOverlapIntegral") {
    test_property_type<property_types::DifferentialOverlapIntegral<>>(
      {"Molecule", "Orbital Space 1", "Orbital Space 2"},
      {"Differential Overlap Integral"});
}

#include "tests/test_property_type.hpp"
#include <property_types/cauchy_schwarz_approximation.hpp>

TEST_CASE("CauchySchwarz") {
    test_property_type<property_types::CauchySchwarzApprox<>>(
            {"Basis1", "Basis2", "Derivative"},
            {"Screening Matrix"}
    );
}
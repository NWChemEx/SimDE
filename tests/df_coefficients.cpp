#include "test_property_type.hpp"
#include <property_types/df_coefficients.hpp>

TEST_CASE("DFCoefficients"){
    test_property_type<property_types::DFCoefficients<>>(
      {"Molecule", "Bra", "Ket", "Derivative"},
      {"DF Coefficients"}
    );
}

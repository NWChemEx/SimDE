#include "test_property_type.hpp"
#include <property_types/integrals/overlap.hpp>

TEST_CASE("Overlap Integrals") {
    test_property_type<property_types::integrals::Overlap<>>(
      {"Molecule", "Bra", "Ket", "Derivative"}, {"overlap matrix"});
}

#include "tests/test_property_type.hpp"
#include <property_types/ao_integrals/kinetic.hpp>

TEST_CASE("KineticIntegral"){
test_property_type<property_types::KineticIntegral<>>(
{"Molecule", "Bra", "Ket", "Derivative"},
{"Kinetic Integrals"}
);
}



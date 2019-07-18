#include "test_property_type.hpp"
#include <property_types/integrals/multipole.hpp>

TEST_CASE("DipoleIntegrals") {
    test_property_type<property_types::integrals::Multipole<1>>(
      {"Molecule", "Bra", "Ket", "Origin", "Derivative"}, {"multipole moment"});
}

TEST_CASE("Quadrupole Integrals") {
    test_property_type<property_types::integrals::Multipole<2>>(
      {"Molecule", "Bra", "Ket", "Origin", "Derivative"}, {"multipole moment"});
}

TEST_CASE("Octopole Integrals") {
    test_property_type<property_types::integrals::Multipole<3>>(
      {"Molecule", "Bra", "Ket", "Origin", "Derivative"}, {"multipole moment"});
}

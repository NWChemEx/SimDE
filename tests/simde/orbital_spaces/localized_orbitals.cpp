#include "test_property_type.hpp"
#include <property_types/localized_orbitals.hpp>

TEST_CASE("LocalizedOrbitals") {
    test_property_type<property_types::LocalizedOrbitals<>>(
      {"Molecule", "Orbitals"}, {"Local Orbitals"});
}

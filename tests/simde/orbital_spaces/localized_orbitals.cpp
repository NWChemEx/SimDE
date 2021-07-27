#include "../test_property_type.hpp"
#include "simde/orbital_spaces/localized_orbitals.hpp"

using namespace simde;

TEST_CASE("LocalizedOrbitals") {
    test_property_type<LocalizedOrbitals<type::canonical_space>>(
      {"Molecule", "Orbitals"}, {"Local Orbitals"});
}

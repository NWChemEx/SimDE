#include "../test_property_type.hpp"
#include "simde/density/update_density.hpp"

TEST_CASE("UpdateGuess") {
    test_property_type<simde::UpdateDensity>(
      {"Molecule", "Basis Set", "Fock Matrix"}, {"Molecular Orbitals"});
}

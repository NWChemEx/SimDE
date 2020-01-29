#include "test_property_type.hpp"
#include <property_types/scf_iteration.hpp>

TEST_CASE("SCFIteration") {
    test_property_type<property_types::SCFIteration<>>(
      {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
      {"Fock Matrix", "Electronic Energy"});
}

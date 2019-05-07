#include "test_property_type.hpp"
#include <property_types/coulomb_matrix.hpp>

TEST_CASE("CoulombMatrix"){
    test_property_type<property_types::CoulombMatrix<>>(
      {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
      {"Coulomb Matrix"}
    );
}

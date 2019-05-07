#include "test_property_type.hpp"
#include <property_types/fock_matrix.hpp>

TEST_CASE("FockMatrix"){
    test_property_type<property_types::FockMatrix<>>(
      {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
      {"Fock Matrix"}
    );
}

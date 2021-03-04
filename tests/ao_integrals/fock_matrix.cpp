#include "property_types/ao_integrals/fock_matrix.hpp"
#include "tests/test_property_type.hpp"

TEST_CASE("FockMatrix") {
    test_property_type<property_types::FockMatrix<>>(
      {"Molecule", "Molecular Orbitals", "bra", "ket"}, {"(m|f|n)"});
}

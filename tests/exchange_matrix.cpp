#include "test_property_type.hpp"
#include <property_types/exchange_matrix.hpp>

TEST_CASE("ExchangeMatrix") {
    test_property_type<property_types::ExchangeMatrix<>>(
      {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
      {"Exchange Matrix"});
}

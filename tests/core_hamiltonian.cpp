#include "test_property_type.hpp"
#include <property_types/core_hamiltonian.hpp>

TEST_CASE("CoreHamiltonian"){
    test_property_type<property_types::CoreHamiltonian<>>(
      {"Molecule", "Bra", "Ket", "Derivative"},
      {"Core Hamiltonian"}
    );
}

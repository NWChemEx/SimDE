#include "test_property_type.hpp"
#include <property_types/update_guess.hpp>

TEST_CASE("UpdateGuess"){
    test_property_type<property_types::UpdateGuess<>>(
        {"Molecule", "Basis Set", "Fock Matrix"},{"Orbital Space"}
    );
}

#include "test_property_type.hpp"
#include <property_types/xc_quantities.hpp>

TEST_CASE("XCQuantities"){
    test_property_type<property_types::XCQuantities<>>(
        {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
        {"VXC Matrix", "EXC Energy"}
    );
}


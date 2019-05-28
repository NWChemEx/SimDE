#include "test_property_type.hpp"
#include <property_types/xc_quantities.hpp>

TEST_CASE("PureXCQuantities"){
    test_property_type<property_types::PureXCQuantities<>>(
        {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
        {"VXC Matrix", "EXC Energy"}
    );
}
TEST_CASE("HybridXCQuantities"){
    test_property_type<property_types::HybridXCQuantities<>>(
        {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"},
        {"VXC Matrix", "EXC Energy", "xEXX"}
    );
}


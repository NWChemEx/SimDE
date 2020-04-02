#include "test_property_type.hpp"
#include <property_types/mo_charges.hpp>

TEST_CASE("MOCharges"){
    test_property_type<property_types::MOCharges<>>(
            {"Molecule", "Molecular Orbitals"},
            {"MO Charges"}
    );
}
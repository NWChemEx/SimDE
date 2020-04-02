#include "test_property_type.hpp"
#include <property_types/partial_charges.hpp>

TEST_CASE("PartialCharges"){
    test_property_type<property_types::PartialCharges<>>(
            {"Molecule", "Molecular Orbitals"},
            {"Partial Charges"}
    );
}
#include "test_property_type.hpp"
#include <property_types/atomic_charges.hpp>

TEST_CASE("AtomicCharges"){
    test_property_type<property_types::AtomicCharges<>>(
            {"Molecule", "Molecular Orbitals"},
            {"Partial Charges"}
    );
}
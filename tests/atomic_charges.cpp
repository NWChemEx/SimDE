#include "test_property_type.hpp"
#include <property_types/atomic_charges.hpp>

TEMPLATE_TEST_CASE("AtomicCharges", "", float, double){
    test_property_type<property_types::AtomicCharges<TestType>>(
            {"Molecule", "Molecular Orbitals"},
            {"Partial Charges"}
    );
}
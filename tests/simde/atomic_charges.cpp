#include "simde/atomic_charges.hpp"
#include "test_property_type.hpp"

TEMPLATE_TEST_CASE("AtomicCharges", "", float, double) {
    test_property_type<simde::AtomicCharges<TestType>>(
      {"Molecule", "Molecular Orbitals"}, {"Partial Charges"});
}

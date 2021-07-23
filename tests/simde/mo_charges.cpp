#include "simde/mo_charges.hpp"
#include "test_property_type.hpp"

using namespace simde;

TEST_CASE("MOCharges") {
    test_property_type<MOCharges<type::derived_space>>(
      {"Molecule", "Molecular Orbitals"}, {"MO Charges"});
}

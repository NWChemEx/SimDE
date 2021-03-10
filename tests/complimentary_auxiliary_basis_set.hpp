#include "property_types/complimentary_auxiliary_basis_set.hpp"
#include "test_property_type.hpp"

using namespace property_types;

TEST_CASE("CABS") {
    using mo_type  = type::canonical_mo_t<double>;
    using out_type = type::orbital_space_t<double>;
    using pt       = ComplimentaryAuxiliaryBasisSet<out_type, mo_type>;
    test_property_type<property_types::ComplimentaryAuxiliaryBasisSet<>>(
      {"orbital basis"}, {"CABS"});
}
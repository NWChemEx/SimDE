#include "../test_property_type.hpp"
#include "simde/orbital_spaces/complimentary_auxiliary_basis_set.hpp"
#include "simde/types.hpp"

using namespace simde;

TEST_CASE("CABS") {
    using mo_type  = type::canonical_space;
    using out_type = type::derived_space;
    using pt       = ComplimentaryAuxiliaryBasisSet<out_type, mo_type>;
    test_property_type<pt>({"orbital basis"}, {"CABS"});
}

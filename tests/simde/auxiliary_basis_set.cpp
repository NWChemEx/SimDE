#include "simde/auxiliary_basis_set.hpp"
#include "test_property_type.hpp"

TEST_CASE("AuxiliaryBasisSet") {
    test_property_type<simde::AuxiliaryBasisSet>({"AtomicBasisSet"},
                                                 {"AuxiliaryBasisSet"});
}
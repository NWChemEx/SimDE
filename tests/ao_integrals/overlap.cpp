#include "property_types/ao_integrals/overlap.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types::ao_integrals;

TEST_CASE("Overlap") {
    test_property_type<Overlap<double>>({"bra", "ket"}, {"(m|n)"});
}
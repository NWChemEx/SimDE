#include "property_types/ao_integrals/stg.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types::ao_integrals;

TEST_CASE("STG2C") {
    test_property_type<STG2C<double>>({"STG Exponent", "bra", "ket"},
                                      {"(p|O|q)"});
}

TEST_CASE("STG3C") {
    test_property_type<STG3C<double>>({"STG Exponent", "bra", "ket 1", "ket 2"},
                                      {"(p|O|qr)"});
}

TEST_CASE("STG4C") {
    test_property_type<STG4C<double>>(
      {"STG Exponent", "bra 1", "bra 2", "ket 1", "ket 2"}, {"(pq|O|rs)"});
}
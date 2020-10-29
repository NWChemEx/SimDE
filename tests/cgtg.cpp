#include "test_property_type.hpp"
#include "property_types/ao_integrals/cgtg.hpp"

using types = std::tuple<float, double>;

TEMPLATE_LIST_TEST_CASE("CGTGIntegral", "", types){
    using pt = property_types::CGTGIntegral<TestType>;
    test_property_type<pt>(
      {"Bra 1", "Bra 2", "Ket 1", "Ket 2", "Params"},
      {"Integrals"}
    );
}

TEMPLATE_LIST_TEST_CASE("CGTGTimesCoulombIntegral", "", types){
    using pt = property_types::CGTGTimesCoulombIntegral<TestType>;
    test_property_type<pt>(
      {"Bra 1", "Bra 2", "Ket 1", "Ket 2", "Params"},
      {"Integrals"}
    );
}

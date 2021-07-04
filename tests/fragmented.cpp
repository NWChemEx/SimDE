#include "property_types/fragmented.hpp"
#include "property_types/types.hpp"
#include "test_property_type.hpp"

using namespace property_types;

using tuple = std::tuple<type::molecule>;

TEMPLATE_LIST_TEST_CASE("Fragmented", "", tuple) {
    using T = TestType;
    test_property_type<Fragmented<T>>({"Object to Fragment"},
                                      {"Fragmented Object"});
}
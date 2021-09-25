#include "simde/tensor_representation/detail_/tensor_rep_traits.hpp"
#include <catch2/catch.hpp>

using namespace simde;

using spaces_type = std::tuple<type::ao_space, type::derived_space>;

TEMPLATE_LIST_TEST_CASE("TensorRepTraits", "", spaces_type) {
    using space_type      = TestType;
    using traits_type     = detail_::TensorRepTraits<space_type>;
    using mode_type       = typename traits_type::mode_type;
    using const_reference = typename traits_type::const_reference;
    using map_type        = typename traits_type::map_type;

    SECTION("mode_type") {
        using corr = unsigned int;
        STATIC_REQUIRE(std::is_same_v<corr, mode_type>);
    }

    SECTION("const_reference") {
        using corr = std::reference_wrapper<const space_type>;
        STATIC_REQUIRE(std::is_same_v<const_reference, corr>);
    }

    SECTION("map_type") {
        using corr = std::map<mode_type, const_reference>;
        STATIC_REQUIRE(std::is_same_v<map_type, corr>);
    }
}

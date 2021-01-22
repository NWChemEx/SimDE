#include "property_types/ao_integrals/ao_integrals.hpp"
#include "property_types/ao_integrals/type_traits.hpp"
#include <catch2/catch.hpp>

using namespace property_types::ao_integrals;

template<typename T>
using two_center =
  std::tuple<ERI2C<T>, EDipole<T>, EQuadrupole<T>, EOctopole<T>, Kinetic<T>,
             Nuclear<T>, Overlap<T>, STG2C<T>, Yukawa2C<T>>;

template<typename T>
using three_center = std::tuple<ERI3C<T>, STG3C<T>, Yukawa3C<T>>;
template<typename T>
using four_center = std::tuple<DOI<T>, ERI4C<T>, STG4C<T>, Yukawa4C<T>>;

using all_2c =
  decltype(std::tuple_cat(two_center<float>{}, two_center<double>{}));

using all_3c =
  decltype(std::tuple_cat(three_center<float>{}, three_center<double>{}));

using all_4c =
  decltype(std::tuple_cat(four_center<float>{}, four_center<double>{}));

TEMPLATE_LIST_TEST_CASE("detail_::IsTwoCentered", "", all_2c) {
    STATIC_REQUIRE(detail_::IsTwoCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsTwoCentered", "", all_3c) {
    STATIC_REQUIRE_FALSE(detail_::IsTwoCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsTwoCentered", "", all_4c) {
    STATIC_REQUIRE_FALSE(detail_::IsTwoCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsThreeCentered", "", all_3c) {
    STATIC_REQUIRE(detail_::IsThreeCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsThreeCentered", "", all_2c) {
    STATIC_REQUIRE_FALSE(detail_::IsThreeCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsThreeCentered", "", all_4c) {
    STATIC_REQUIRE_FALSE(detail_::IsThreeCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsFourCentered", "", all_4c) {
    STATIC_REQUIRE(detail_::IsFourCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsFourCentered", "", all_2c) {
    STATIC_REQUIRE_FALSE(detail_::IsFourCentered<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("detail_::IsFourCentered", "", all_3c) {
    STATIC_REQUIRE_FALSE(detail_::IsFourCentered<TestType>::value);
}

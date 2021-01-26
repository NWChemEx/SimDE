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

TEMPLATE_LIST_TEST_CASE("detail_::n_centers()", "", all_2c) {
    STATIC_REQUIRE(detail_::n_centers<TestType>() == 2);
}

TEMPLATE_LIST_TEST_CASE("detail_::n_centers()", "", all_3c) {
    STATIC_REQUIRE(detail_::n_centers<TestType>() == 3);
}

TEMPLATE_LIST_TEST_CASE("detail_::n_centers()", "", all_4c) {
    STATIC_REQUIRE(detail_::n_centers<TestType>() == 4);
}

TEMPLATE_TEST_CASE("detail_::IsDOI", "", float, double) {
    STATIC_REQUIRE(detail_::IsDOI<DOI<TestType>>::value);
    STATIC_REQUIRE_FALSE(detail_::IsDOI<ERI3C<TestType>>::value);
}

TEMPLATE_TEST_CASE("detail_::IsNuclear", "", float, double) {
    STATIC_REQUIRE(detail_::IsNuclear<Nuclear<TestType>>::value);
    STATIC_REQUIRE_FALSE(detail_::IsNuclear<ERI3C<TestType>>::value);
}

TEMPLATE_TEST_CASE("detail_::IsSTG", "", float, double) {
    STATIC_REQUIRE(detail_::IsSTG<STG<TestType>>::value);
    STATIC_REQUIRE_FALSE(detail_::IsSTG<ERI3C<TestType>>::value);
}

TEMPLATE_TEST_CASE("detail_::IsYukawa", "", float, double) {
    STATIC_REQUIRE(detail_::IsYukawa<Yukawa<TestType>>::value);
    STATIC_REQUIRE_FALSE(detail_::IsYukawa<ERI3C<TestType>>::value);
}

//------------------------------------------------------------------------------
//                  Public APIS
//------------------------------------------------------------------------------

TEMPLATE_LIST_TEST_CASE("n_centers_v", "", all_2c) {
    STATIC_REQUIRE(n_centers_v<TestType> == 2);
}

TEMPLATE_LIST_TEST_CASE("n_centers_v", "", all_3c) {
    STATIC_REQUIRE(n_centers_v<TestType> == 3);
}

TEMPLATE_LIST_TEST_CASE("n_centers_v", "", all_4c) {
    STATIC_REQUIRE(n_centers_v<TestType> == 4);
}

TEMPLATE_TEST_CASE("is_doi_v", "", float, double) {
    STATIC_REQUIRE(is_doi_v<DOI<TestType>>);
    STATIC_REQUIRE_FALSE(is_doi_v<ERI3C<TestType>>);
}

TEMPLATE_TEST_CASE("is_nuclear_v", "", float, double) {
    STATIC_REQUIRE(is_nuclear_v<Nuclear<TestType>>);
    STATIC_REQUIRE_FALSE(is_nuclear_v<ERI3C<TestType>>);
}

TEMPLATE_TEST_CASE("is_stg_v", "", float, double) {
    STATIC_REQUIRE(is_stg_v<STG<TestType>>);
    STATIC_REQUIRE_FALSE(is_stg_v<ERI3C<TestType>>);
}

TEMPLATE_TEST_CASE("is_yukawa_v", "", float, double) {
    STATIC_REQUIRE(is_yukawa_v<Yukawa<TestType>>);
    STATIC_REQUIRE_FALSE(is_yukawa_v<ERI3C<TestType>>);
}
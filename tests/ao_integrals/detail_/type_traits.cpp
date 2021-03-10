#include "../ao_integrals_test.hpp"
#include "property_types/ao_integrals/ao_integrals.hpp"
#include "property_types/ao_integrals/detail_/type_traits.hpp"
#include <catch2/catch.hpp>

using namespace property_types::ao_integrals;
using namespace property_types::ao_integrals::test;

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

TEMPLATE_LIST_TEST_CASE("HasFloatElements", "", two_center<float>) {
    STATIC_REQUIRE(detail_::HasFloatElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasFloatElements", "", two_center<double>) {
    STATIC_REQUIRE_FALSE(detail_::HasFloatElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasFloatElements", "", three_center<float>) {
    STATIC_REQUIRE(detail_::HasFloatElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasFloatElements", "", three_center<double>) {
    STATIC_REQUIRE_FALSE(detail_::HasFloatElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasFloatElements", "", four_center<float>) {
    STATIC_REQUIRE(detail_::HasFloatElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasFloatElements", "", four_center<double>) {
    STATIC_REQUIRE_FALSE(detail_::HasFloatElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasDoubleElements", "", two_center<float>) {
    STATIC_REQUIRE_FALSE(detail_::HasDoubleElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasDoubleElements", "", two_center<double>) {
    STATIC_REQUIRE(detail_::HasDoubleElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasDoubleElements", "", three_center<float>) {
    STATIC_REQUIRE_FALSE(detail_::HasDoubleElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasDoubleElements", "", three_center<double>) {
    STATIC_REQUIRE(detail_::HasDoubleElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasDoubleElements", "", four_center<float>) {
    STATIC_REQUIRE_FALSE(detail_::HasDoubleElements<TestType>::value);
}

TEMPLATE_LIST_TEST_CASE("HasDoubleElements", "", four_center<double>) {
    STATIC_REQUIRE(detail_::HasDoubleElements<TestType>::value);
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
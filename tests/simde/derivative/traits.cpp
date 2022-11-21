#include <catch2/catch.hpp>
#include <simde/derivative/derivative.hpp>

using namespace simde;

using not_deriv_t = std::tuple<int, double, std::string>;

using deriv_t = std::tuple<AOEnergyNuclearGradient, AOEnergyNuclearHessian>;

TEMPLATE_LIST_TEST_CASE("IsDerivative (not Derivative)", "", not_deriv_t) {
    STATIC_REQUIRE_FALSE(detail_::IsDerivative<TestType>::value);
    STATIC_REQUIRE_FALSE(is_derivative_v<TestType>);
}

TEMPLATE_LIST_TEST_CASE("IsDerivative (is Derivative)", "", deriv_t) {
    STATIC_REQUIRE(detail_::IsDerivative<TestType>::value);
    STATIC_REQUIRE(is_derivative_v<TestType>);
}

TEST_CASE("DerivativeOrder") {
    // Uncomment to check that this does not compile
    DerivativeOrder<int> x;

    STATIC_REQUIRE(DerivativeOrder<AOEnergyNuclearGradient>::value == 1);
    STATIC_REQUIRE(derivative_order_v<AOEnergyNuclearGradient> == 1);
    STATIC_REQUIRE(DerivativeOrder<AOEnergyNuclearHessian>::value == 2);
    STATIC_REQUIRE(derivative_order_v<AOEnergyNuclearHessian> == 2);
}

#include <catch2/catch.hpp>
#include <simde/derivative/derivative.hpp>

using namespace simde;

using not_deriv_t = std::tuple<int, double, std::string>;

using deriv_t = std::tuple<AOEnergyNuclearGradient, AOEnergyNuclearHessian>;

TEMPLATE_LIST_TEST_CASE("IsDerivative", "", not_deriv_t) {
    STATIC_REQUIRE_FALSE(IsDerivative<TestType>::value);
}

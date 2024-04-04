/*
 * Copyright 2023 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <catch2/catch.hpp>
#include <simde/derivative/derivative.hpp>

using namespace simde;
using namespace simde::detail_;

using Gradient = simde::AOEnergyNuclearGradient<std::vector<double>>;
using Hessian  = simde::AOEnergyNuclearHessian<std::vector<double>>;

using not_deriv_t = std::tuple<int, double, std::string>;

using deriv_t = std::tuple<Gradient, Hessian>;

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
    // DerivativeOrder<int> x;

    STATIC_REQUIRE(DerivativeOrder<Gradient>::value == 1);
    STATIC_REQUIRE(derivative_order_v<Gradient> == 1);
    STATIC_REQUIRE(DerivativeOrder<Hessian>::value == 2);
    STATIC_REQUIRE(derivative_order_v<Hessian> == 2);
}

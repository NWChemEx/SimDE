/*
 * Copyright 2022 NWChemEx-Project
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

#include "property_types/ao_integrals/f12/correlation_factor_squared.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types::ao_integrals::f12;

TEST_CASE("Correlation Factor Squared 2C") {
    test_property_type<CorrelationFactorSquared2C<double>>(
      {"bra", "ket"}, {"(m|f_12^2(r_12)|n)"});
}

TEST_CASE("Correlation Factor Squared 3C") {
    test_property_type<CorrelationFactorSquared3C<double>>(
      {"bra", "ket 1", "ket 2"}, {"(m|f_12^2(r_12)|nl)"});
}

TEST_CASE("Correlation Factor Squared 4C") {
    test_property_type<CorrelationFactorSquared4C<double>>(
      {"bra 1", "bra 2", "ket 1", "ket 2"}, {"(mn|f_12^2(r_12)|ls)"});
}
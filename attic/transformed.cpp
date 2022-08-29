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

#include "property_types/ao_integrals/electron_repulsion.hpp"
#include "property_types/transformed.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types;

TEMPLATE_TEST_CASE("Transformed<ERI2c>", "", double, float) {
    using pt = Transformed<ao_integrals::ERI2C<TestType>>;

    test_property_type<pt>({"final bra", "final ket", "bra", "ket"},
                           {"(m|r_12|n)"});
}

TEMPLATE_TEST_CASE("Transformed<ERI3c>", "", double, float) {
    using pt = Transformed<ao_integrals::ERI3C<TestType>>;

    test_property_type<pt>(
      {"final bra", "final ket 1", "final ket 2", "bra", "ket 1", "ket 2"},
      {"(m|r_12|nl)"});
}

TEMPLATE_TEST_CASE("Transformed<ERI4c>", "", double, float) {
    using pt = Transformed<ao_integrals::ERI4C<TestType>>;

    test_property_type<pt>({"final bra 1", "final bra 2", "final ket 1",
                            "final ket 2", "bra 1", "bra 2", "ket 1", "ket 2"},
                           {"(mn|r_12|ls)"});
}
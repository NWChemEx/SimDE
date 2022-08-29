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

#include "property_types/ao_integrals/f12/gr.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types::ao_integrals::f12;

TEST_CASE("GR 2C") {
    test_property_type<GR2C<double>>({"bra", "ket"}, {"(m|f_12(r_12)/r_12|n)"});
}

TEST_CASE("GR 3C") {
    test_property_type<GR3C<double>>({"bra", "ket 1", "ket 2"},
                                     {"(m|f_12(r_12)/r_12|nl)"});
}

TEST_CASE("GR 4C") {
    test_property_type<GR4C<double>>({"bra 1", "bra 2", "ket 1", "ket 2"},
                                     {"(mn|f_12(r_12)/r_12|ls)"});
}
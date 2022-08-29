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

#include "property_types/ao_integrals/ao_integrals.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types::ao_integrals;

TEMPLATE_TEST_CASE("EMultipole", "", double, float) {
    test_property_type<EMultipole<TestType, 0>>({"origin", "bra", "ket"},
                                                {"(m|r**0|n)"});
}

TEMPLATE_TEST_CASE("EDipole", "", double, float) {
    test_property_type<EDipole<TestType>>({"origin", "bra", "ket"},
                                          {"(m|r**1|n)"});
}

TEMPLATE_TEST_CASE("EQuadrupole", "", double, float) {
    test_property_type<EQuadrupole<TestType>>({"origin", "bra", "ket"},
                                              {"(m|r**2|n)"});
}

TEMPLATE_TEST_CASE("EOctopole", "", double, float) {
    test_property_type<EOctopole<TestType>>({"origin", "bra", "ket"},
                                            {"(m|r**3|n)"});
}
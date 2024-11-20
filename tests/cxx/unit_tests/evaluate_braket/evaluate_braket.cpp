/*
 * Copyright 2024 NWChemEx-Project
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

#include "../test_property_type.hpp"
#include <simde/evaluate_braket/evaluate_braket.hpp>

using namespace simde;

// N.b. BraKetType matters if we want to ensure all instantiations we care about
// compile

using types2test =
  std::tuple<aos_t_e_aos, aos_v_en_aos, ERI2, ERI3, ERI4, ESCF<type::cmos>>;

TEMPLATE_LIST_TEST_CASE("EvaluateBraKet", "", types2test) {
    using pt = TestType;
    test_property_type<pt>({"BraKet"}, {"tensor representation"});
}

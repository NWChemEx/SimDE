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
#include <simde/simde.hpp>

using namespace simde;

TEST_CASE("Optimize<ESCF, rscf_wf>") {
    using pt2opt  = ESCF<type::cmos>;
    using wrt     = type::rscf_wf;
    using pt      = Optimize<pt2opt, wrt>;
    auto inp_desc = "Object to optimize the objective function with respect to";
    auto out_desc = "Object that optimizes the objective function";
    test_property_type<pt>({"BraKet", inp_desc},
                           {"tensor representation", out_desc});
}

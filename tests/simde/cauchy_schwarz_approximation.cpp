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

#include "simde/cauchy_schwarz_approximation.hpp"
#include "test_property_type.hpp"

TEST_CASE("CauchySchwarz") {
    using op_t = simde::type::el_el_coulomb;
    op_t op;
    test_property_type<simde::ShellNorms<op_t>>({"bra", op.as_string(), "ket"},
                                                {"Screening Matrix"});
}

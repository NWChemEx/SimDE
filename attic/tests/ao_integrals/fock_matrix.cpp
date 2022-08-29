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

#include "property_types/ao_integrals/fock_matrix.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types;

TEMPLATE_TEST_CASE("FockMatrix", "", double, float) {
    using pt = FockMatrix<TestType, type::derived_space_t<TestType>>;
    test_property_type<pt>({"Molecule", "Molecular Orbitals", "bra", "ket"},
                           {"(m|f|n)"});
}

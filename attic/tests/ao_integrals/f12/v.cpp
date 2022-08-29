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

#include "property_types/ao_integrals/f12/v.hpp"
#include "property_types/types.hpp"
#include "tests/test_property_type.hpp"

using namespace property_types;
using namespace ao_integrals::f12;

TEST_CASE("F12 V value") {
    using mo_type = type::canonical_space_t<double>;
    test_property_type<V<mo_type, mo_type>>(
      {"Orbital space for occupied orbitals",
       "Orbital space for virtual orbitals"},
      {"V"});
}
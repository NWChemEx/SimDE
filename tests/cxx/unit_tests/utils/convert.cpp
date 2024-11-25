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
#include <simde/types.hpp>
#include <simde/utils/convert.hpp>

using namespace simde;

using to_from_pairs =
  std::tuple<std::pair<type::hamiltonian, type::chemical_system>>;

TEMPLATE_LIST_TEST_CASE("Convert", "", to_from_pairs) {
    using to_type   = std::tuple_element_t<0, TestType>;
    using from_type = std::tuple_element_t<1, TestType>;
    using pt        = Convert<to_type, from_type>;

    test_property_type<pt>({"Object to convert from"}, {"Converted object"});
}

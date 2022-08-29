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

#pragma once
#include "property_types/ao_integrals/type_traits.hpp"
#include <string>

namespace property_types::ao_integrals::detail_ {

/** @brief Makes the result key for a given operator.
 *
 *  This function wraps the making of a key for a property type that is an AO
 *  integral.
 *
 *  @tparam The property type we are making the result key for.
 *
 *  @param[in] op The string representation of the operator involved in the
 *                integral.
 *
 *  @return The string to use as the result key for the property type.
 */

template<typename BaseType>
auto make_key(const std::string& op) {
    auto middle = (op == "" ? "" : op + "|");
    if constexpr(n_centers_v<BaseType> == 2) {
        return "(m|" + middle + "n)";
    } else if constexpr(n_centers_v<BaseType> == 3) {
        return "(m|" + middle + "nl)";
    } else if constexpr(n_centers_v<BaseType> == 4) {
        return "(mn|" + middle + "ls)";
    } else {
        // Can't get here because n_centers_v won't compile
    }
}

} // namespace property_types::ao_integrals::detail_

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

#pragma once
#include <pluginplay/pluginplay.hpp>
#include <simde/types.hpp>

namespace simde {

template<typename GuessType>
DECLARE_TEMPLATED_PROPERTY_TYPE(UpdateGuess, GuessType);

template<typename GuessType>
TEMPLATED_PROPERTY_TYPE_INPUTS(UpdateGuess, GuessType) {
    using guess_type = const GuessType&;
    using fock_type  = const type::fock&;
    return pluginplay::declare_input()
      .template add_field<fock_type>("New Fock Operator")
      .template add_field<guess_type>("Old guess");
}

template<typename GuessType>
TEMPLATED_PROPERTY_TYPE_RESULTS(UpdateGuess, GuessType) {
    return pluginplay::declare_result().template add_field<GuessType>(
      "New guess");
}

} // namespace simde
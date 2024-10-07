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
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

template<typename BraKetType>
DECLARE_TEMPLATED_PROPERTY_TYPE(EvaluateBraKet, BraKetType);

template<typename BraKetType>
TEMPLATED_PROPERTY_TYPE_INPUTS(EvaluateBraKet, BraKetType) {
    using const_braket_t = const BraKetType;
    return pluginplay::declare_input().add_field<const_braket_t>("BraKet");
}

template<typename BraKetType>
TEMPLATED_PROPERTY_TYPE_RESULTS(EvaluateBraKet, BraKetType) {
    return pluginplay::declare_result().add_field<type::tensor>(
      "tensor representation");
}

} // namespace simde
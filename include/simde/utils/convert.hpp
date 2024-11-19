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

namespace simde {

template<typename ToType, typename FromType>
DECLARE_TEMPLATED_PROPERTY_TYPE(Convert, ToType, FromType);

template<typename ToType, typename FromType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Convert, ToType, FromType) {
    return PropertyType::inputs().template add_field<FromType>(
      "Object to convert from");
}

template<typename ToType, typename FromType>
TEMPLATED_PROPERTY_TYPE_Results(Convert, ToType, FromType) {
    return pluginplay::declare_result().template add_field<ToType>(
      "Converted object");
}

} // namespace simde
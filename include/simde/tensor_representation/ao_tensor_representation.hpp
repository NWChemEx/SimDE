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

template<std::size_t N, typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(AOTensorRepresentation, N, OperatorType);

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AOTensorRepresentation, N, OperatorType) {
    using const_ao_space_t = const simde::type::ao_space;
    if constexpr(N == 2) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>("operator")
          .template add_field<const_ao_space_t>("ket");
    } else if constexpr(N == 3) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>("operator")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else if constexpr(N == 4) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra 1")
          .template add_field<const_ao_space_t>("bra 2")
          .template add_field<const OperatorType&>("operator")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else {
        // N.B. if we get here we know N != 2, but we can't just hardcode false
        static_assert(N == 2, "Inputs not defined for N outside range [2, 4]");
    }
}

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AOTensorRepresentation, N, OperatorType) {
    return pluginplay::declare_result().add_field<type::tensor>(
      "tensor representation");
}

template<typename OperatorType>
using TwoCenterAOTensorRepresentation = AOTensorRepresentation<2, OperatorType>;

template<typename OperatorType>
using ThreeCenterAOTensorRepresentation =
  AOTensorRepresentation<3, OperatorType>;

template<typename OperatorType>
using FourCenterAOTensorRepresentation =
  AOTensorRepresentation<4, OperatorType>;

} // namespace simde

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

template<typename DensityType>
DECLARE_TEMPLATED_PROPERTY_TYPE(FockOperator, DensityType);

template<typename DensityType>
TEMPLATED_PROPERTY_TYPE_INPUTS(FockOperator, DensityType) {
    using hamiltonian_type = const type::hamiltonian&;
    return pluginplay::declare_input()
      .add_field<hamiltonian_type>("Hamiltonian")
      .template add_field<DensityType>("Density");
}

template<typename DensityType>
TEMPLATED_PROPERTY_TYPE_RESULTS(FockOperator, DensityType) {
    return pluginplay::declare_result().template add_field<type::fock>(
      "Fock operator");
}

} // namespace simde

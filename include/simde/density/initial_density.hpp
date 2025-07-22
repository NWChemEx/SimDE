/*
 * Copyright 2025 NWChemEx-Project
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
#include <pluginplay/pluginplay.hpp>

namespace simde {

/** @brief The property for a module that returns an initial Electronic density
 */
DECLARE_PROPERTY_TYPE(InitialDensity);

PROPERTY_TYPE_INPUTS(InitialDensity) {
    using hamiltonian_type = const type::hamiltonian&;
    return pluginplay::declare_input().template add_field<hamiltonian_type>(
      "Hamiltonian");
}

PROPERTY_TYPE_RESULTS(InitialDensity) {
    using density_type = simde::type::decomposable_e_density;
    return pluginplay::declare_result().add_field<density_type>("Density");
}

} // namespace simde

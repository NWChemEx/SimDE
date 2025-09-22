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
#include <chemist/grid/grid_class.hpp>
#include <pluginplay/property_type/property_type.hpp>
#include <simde/types.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(CollocationMatrix);

PROPERTY_TYPE_INPUTS(CollocationMatrix) {
    using grid_type     = chemist::Grid;
    using ao_basis_type = simde::type::ao_basis_set;
    return pluginplay::declare_input()
      .add_field<grid_type>("Grid")
      .add_field<const ao_basis_type&>("AO Basis Set");
}

PROPERTY_TYPE_RESULTS(CollocationMatrix) {
    using result_type = simde::type::tensor;
    return pluginplay::declare_result().add_field<result_type>(
      "Collocation Matrix");
}

} // namespace simde

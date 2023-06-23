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
#include <pluginplay/pluginplay.hpp>

namespace simde {

/** @brief API for modules which create densities from orbitals which can have
 * fractional occupations.
 *
 *  Modules which satisfy the `SCFDensityFractional` property type effectively
 *  have an API: `simde::type::el_density (const canonical_space&,
 * std::vector<double>&)`. For example, the `SCF::DensityFractional` will
 * compute the density by contracting the occupied orbitals together with their
 * occupations.
 */
DECLARE_DERIVED_PROPERTY_TYPE(SCFDensityFractional, SCFDensity);

PROPERTY_TYPE_INPUTS(SCFDensityFractional) {
    auto rv =
      pluginplay::declare_input().add_field<const std::vector<double>&>("occ");
    rv["occ"].set_description("vector of orbital occupations");
    return rv;
}

PROPERTY_TYPE_RESULTS(SCFDensityFractional) {
    return pluginplay::declare_result();
}

} // namespace simde
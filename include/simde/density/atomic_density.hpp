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

/** @brief API for modules which return atomic densities.
 *
 *  Modules which satisfy the `AtomicDensity` property type effectively have an
 *  API: `simde::type::atom_density_flat (const AtomicBasisSet<double>&)`.
 *  The AtomicBasisSet contains the center's atomic number, basis set name, and
 *  basis functions.
 */
DECLARE_PROPERTY_TYPE(AtomicDensity);

PROPERTY_TYPE_INPUTS(AtomicDensity) {
    using AtomicBasisD = chemist::AtomicBasisSet<double>;
    auto rv =
      pluginplay::declare_input().add_field<const AtomicBasisD&>("AtomicBasis");
    return rv;
}

PROPERTY_TYPE_RESULTS(AtomicDensity) {
    // using simde::type::atom_density_flat;
    // pluginplay::declare_result().add_field<atom_density_flat>("AtomDensity");
    auto rv = pluginplay::declare_result().add_field<std::vector<double>>(
      "AtomDensity");
    rv["AtomDensity"].set_description("Flattened atomic density in AO basis");
    return rv;
}

} // namespace simde
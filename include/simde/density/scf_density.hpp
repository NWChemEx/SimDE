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

/** @brief API for modules which create densities from occupied orbitals.
 *
 *  Modules which satisfy the `SCFDensity` property type effectively
 *  have an API: `simde::type::el_density (const canonical_space&)`.
 *  For example, the `SCF::Density` will compute the density by contracting
 *  the occupied orbitals together.
 */
DECLARE_PROPERTY_TYPE(SCFDensity);

PROPERTY_TYPE_INPUTS(SCFDensity) {
    using simde::type::canonical_space;
    auto rv =
      pluginplay::declare_input().add_field<const canonical_space&>("Phi0");
    return rv;
}

PROPERTY_TYPE_RESULTS(SCFDensity) {
    using simde::type::el_density;
    auto rv = pluginplay::declare_result().add_field<el_density>("Density");
    return rv;
}

DECLARE_PROPERTY_TYPE(InitialDensity);

PROPERTY_TYPE_INPUTS(InitialDensity) {
    using op = const type::els_hamiltonian&;
    auto rv  = pluginplay::declare_input().add_field<op>("Hamiltonian");
    return rv;
}

PROPERTY_TYPE_RESULTS(InitialDensity) {
    using type::el_density;
    auto rv = pluginplay::declare_result().add_field<el_density>("Density");
    return rv;
}

template<typename Input, typename OutputDensity>
DECLARE_TEMPLATED_PROPERTY_TYPE(SCFBaseDensity, Input, OutputDensity);

template<typename Input, typename OutputDensity>
TEMPLATED_PROPERTY_TYPE_INPUTS(SCFBaseDensity, Input, OutputDensity) {
    using op   = const type::els_hamiltonian&;
    using in_t = const Input&;

    auto rv = pluginplay::declare_input()
                .add_field<op>("Hamiltonian")
                .template add_field<in_t>("Input Space");
    return rv;
}

template<typename Input, typename OutputDensity>
TEMPLATED_PROPERTY_TYPE_RESULTS(SCFBaseDensity, Input, OutputDensity) {
    auto rv =
      pluginplay::declare_result().add_field<OutputDensity>("Output Density");

    return rv;
}

using SCFGuessDensity = SCFBaseDensity<type::ao_space, type::el_density>;
using SCFDensityStep  = SCFBaseDensity<type::el_density, type::el_density>;

} // namespace simde
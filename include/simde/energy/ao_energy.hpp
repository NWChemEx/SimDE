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
#include <pluginplay/property_type/property_type.hpp>
#include <simde/energy/total_energy.hpp>
#include <simde/types.hpp>

namespace simde {

DECLARE_DERIVED_PROPERTY_TYPE(AOEnergy, TotalEnergy);

PROPERTY_TYPE_INPUTS(AOEnergy) {
    using ao_basis = const type::ao_basis_set&;
    auto rv        = pluginplay::declare_input().add_field<ao_basis>("AOs");
    rv["AOs"].set_description("The atomic orbital basis set");
    return rv;
}

PROPERTY_TYPE_RESULTS(AOEnergy) { return pluginplay::declare_result(); }

} // namespace simde

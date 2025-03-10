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

/** @brief The property type for modules that compute the total energy of a
 *         chemical system.
 *
 *  Arguably one of the most important quantities in electronic structure theory
 *  is the total energy of the system. Modules that are capable of computing the
 *  total energy of a chemical system satisfy the TotalEnergy property type.
 *
 */
DECLARE_PROPERTY_TYPE(TotalEnergy);

//-------------------------------Implementations--------------------------------
PROPERTY_TYPE_INPUTS(TotalEnergy) {
    using chem_sys_t = const type::chemical_system&;
    auto rv =
      pluginplay::declare_input().add_field<chem_sys_t>("Chemical System");
    rv["Chemical System"].set_description("The chemical system");
    return rv;
}

PROPERTY_TYPE_RESULTS(TotalEnergy) {
    auto rv =
      pluginplay::declare_result().add_field<simde::type::tensor>("Energy");
    rv["Energy"].set_description("The computed energy");
    return rv;
}

} // namespace simde

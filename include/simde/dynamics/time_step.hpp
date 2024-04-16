/*
 * Copyright 2024 NWChemEx
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

#include <chemist/chemist.hpp>
#include <pluginplay/pluginplay.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(TimeStep);

PROPERTY_TYPE_INPUTS(TimeStep) {
    using chem_system_t = const chemist::ChemicalSystem&;
    auto rv =
      pluginplay::declare_input().add_field<chem_system_t>("Chemical System");

    rv["Chemical System"].set_description("The system at the current time");

    return rv;
}

PROPERTY_TYPE_RESULTS(TimeStep) {
    using chemical_system_t = chemist::ChemicalSystem;
    using momentum_t        = chemist::PointSet<double>;

    auto rv = pluginplay::declare_result()
                .add_field<chemical_system_t>("New Chemical System")
                .template add_field<momentum_t>("Momentum");
    rv["New Chemical System"].set_description(
      "The system at the next time step");
    rv["Momentum"].set_description("The momentum of the system");
    return rv;
}

} // namespace simde

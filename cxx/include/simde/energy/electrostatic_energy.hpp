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
#include <pluginplay/property_type/property_type.hpp>
#include <simde/types.hpp>

namespace simde {

template<typename ObjectType, typename PotentialType>
DECLARE_TEMPLATED_PROPERTY_TYPE(ElectrostaticEnergy, ObjectType, PotentialType);

template<typename ObjectType, typename PotentialType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ElectrostaticEnergy, ObjectType, PotentialType) {
    using object_type    = const ObjectType&;
    using potential_type = const PotentialType&;
    auto rv              = pluginplay::declare_input()
                .add_field<object_type>("Objects")
                .template add_field<potential_type>("Potential");
    rv["Objects"].set_description("The objects interacting with the potential");
    rv["Potential"].set_description(
      "The electrostatic potential (or the objects generating the potential)");
    return rv;
}

template<typename ObjectType, typename PotentialType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ElectrostaticEnergy, ObjectType,
                                PotentialType) {
    auto rv =
      pluginplay::declare_result().add_field<simde::type::tensor>("Energy");
    return rv;
}

using charge_charge_interaction =
  ElectrostaticEnergy<type::charges, type::charges>;

} // namespace simde

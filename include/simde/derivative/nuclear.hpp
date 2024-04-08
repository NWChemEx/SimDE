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
#include <simde/derivative/derivative_pt.hpp>
#include <simde/energy/ao_energy.hpp>

namespace simde {

template<typename PropertyType, typename TensorType>
using NuclearDerivative =
  Derivative<PropertyType, chemist::PointSet<double>, TensorType>;

template<typename TensorType>
using AOEnergyNuclearGradient = NuclearDerivative<AOEnergy, TensorType>;

template<typename TensorType>
using AOEnergyNuclearHessian =
  NuclearDerivative<AOEnergyNuclearGradient<TensorType>, TensorType>;

namespace provisional {

// These typedefs are not yet part of the official API and are subject to change
using AOEnergyNuclearGradientD = AOEnergyNuclearGradient<std::vector<double>>;
using AOEnergyNuclearHessianD  = AOEnergyNuclearHessian<std::vector<double>>;

/** @brief The property type for modules that compute an energy gradient for a
 *         chemical system.
 * 
 * Analogous interface as TotalEnergy
 */
template<typename TensorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(EnergyNuclearGradient, TensorType);

template<typename TensorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(EnergyNuclearGradient, TensorType) {
    using chem_sys_t = const type::chemical_system&;
    auto rv =
      pluginplay::declare_input().add_field<chem_sys_t>("Chemical System");
    rv["Chemical System"].set_description("The chemical system");
    return rv;
}

template<typename TensorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(EnergyNuclearGradient, TensorType) {
    auto rv = pluginplay::declare_result().template add_field<TensorType>(
      "Derivative");
    rv["Derivative"].set_description("The computed derivative");
    return rv;
}

using EnergyNuclearGradientD = EnergyNuclearGradient<std::vector<double>>;

} // namespace provisional

} // namespace simde

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
#include <simde/energy/total_energy.hpp>

namespace simde {

/** @brief Property type which computes the derivative with respect to nuclear
 *         positions.
 *
 *  @tparam PropertyType The property type we are taking the derivitive of.
 *  @tparam TensorType The type the gradient is returned as.
 */
template<typename PropertyType, typename TensorType>
using NuclearDerivative =
  Derivative<PropertyType, chemist::PointSet<double>, TensorType>;

/** @brief Specializes NuclearDerivative to when PropertyType == TotalEnergy
 *
 *  @tparam TensorType The type the gradient is returned as.
 */
template<typename TensorType>
using EnergyNuclearGradient = NuclearDerivative<TotalEnergy, TensorType>;

/** @brief Specializes NuclearDerivative to Hessians of TotalEnergy
 *
 *  @tparam TensorType The type the Hessian is returned as.
 */
template<typename TensorType>
using EnergyNuclearHessian =
  NuclearDerivative<EnergyNuclearGradient<TensorType>, TensorType>;

/** @brief Specializes NuclearDerivative to Gradients of AOEnergy
 *
 *  @tparam TensorType The type of the gradient
 */
template<typename TensorType>
using AOEnergyNuclearGradient = NuclearDerivative<AOEnergy, TensorType>;

/** @brief Specializes NuclearDerivative to Hessians of AOEnergy
 *
 *  @tparam TensorType The type of the gradient
 */
template<typename TensorType>
using AOEnergyNuclearHessian =
  NuclearDerivative<AOEnergyNuclearGradient<TensorType>, TensorType>;

// --  Assumes tensors are stored as std::vector objects
using EnergyNuclearGradientStdVectorD =
  EnergyNuclearGradient<std::vector<double>>;

using EnergyNuclearHessianStdVectorD =
  EnergyNuclearHessian<std::vector<double>>;
using AOEnergyNuclearGradientStdVectorD =
  AOEnergyNuclearGradient<std::vector<double>>;
using AOEnergyNuclearHessianStdVectorD =
  AOEnergyNuclearHessian<std::vector<double>>;

} // namespace simde

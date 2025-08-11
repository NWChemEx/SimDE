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
#include <chemist/chemist.hpp>
#include <simde/energy/energy.hpp>
#include <simde/optimize/optimize_pt.hpp>

namespace simde {

/** @brief Property type which optimizes another property type with respect to
 *         nuclear positions.
 *
 *  @tparam PropertyType The property type whose value is being optimized.
 */
template<typename PropertType>
using NuclearOptimization = Optimize<PropertType, chemist::PointSet<double>>;

/** @brief Property type which optimizes total energy with respect to nuclear
 *         positions.
 */
using TotalEnergyNuclearOptimization = NuclearOptimization<TotalEnergy>;

/** @brief Property type which optimizes AO energy with respect to nuclear
 *         positions.
 */
using AOEnergyNuclearOptimization = NuclearOptimization<AOEnergy>;

} // namespace simde

/*
 * Copyright 2023 NWChemEx-Project
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
#include <simde/energy/ao_energy.hpp>
#include <simde/optimize/optimize_pt.hpp>
#include <simde/types.hpp>

namespace simde {

/** @brief Type def of Optimize for when we want the optimize
 *         with respect to nuclear coordinates.
 *
 *  @tparam T The property type we are optimizing for.
 */
template<typename T>
using NuclearOptimize = Optimize<T, type::molecule>;

/// Type for the optimization of an AOEnergy w.r.t. nuclear coordinates.
using OptimizeCoordinates = NuclearOptimize<AOEnergy>;

} // namespace simde

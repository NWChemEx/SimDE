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
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/optimize/optimize.hpp>
#include <simde/types.hpp>

namespace simde {
inline void export_optimize(python_module_reference m) {
    using OptimizeRSCFEnergyWRTRSCFWavefunction =
      Optimize<ESCF<type::cmos>, type::rscf_wf>;

    EXPORT_PROPERTY_TYPE(OptimizeRSCFEnergyWRTRSCFWavefunction, m);
    EXPORT_PROPERTY_TYPE(TotalEnergyNuclearOptimization, m);
    EXPORT_PROPERTY_TYPE(AOEnergyNuclearOptimization, m);
}
} // namespace simde
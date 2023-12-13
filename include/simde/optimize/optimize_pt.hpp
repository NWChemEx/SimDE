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
#include <pluginplay/pluginplay.hpp>
#include <simde/types.hpp>

namespace simde {

/** @brief Declares the Optimize property type.
 *
 *  The Optimize template property type is templated on the quantity we are
 *  taking the Optimize of and the type we are taking the Optimize with
 *  respect to. For example:
 *
 *  ```.cpp
 *  Optimize<AOEnergy, Molecule>;
 *  ```
 *
 *  is the property type for a module which computes the optimized
 *  AOEnergy with respect to nuclear coordinates.
 *
 *
 *  @tparam PT2Optimize The property type being optimized.
 *  @tparam WithRespectTo The type we are optimizing with
 *                        respect to.
 */
template<typename PT2Optimize, typename WithRespectTo>
DECLARE_TEMPLATED_PROPERTY_TYPE(Optimize, PT2Optimize, WithRespectTo);

template<typename PT2Optimize, typename WithRespectTo>
TEMPLATED_PROPERTY_TYPE_INPUTS(Optimize, PT2Optimize, WithRespectTo) {
    auto label = "To be optimized";
    return PT2Optimize::inputs().template add_field<WithRespectTo>(label);
}

template<typename PT2Optimize, typename WithRespectTo>
TEMPLATED_PROPERTY_TYPE_RESULTS(Optimize, PT2Optimize, WithRespectTo) {
    return pluginplay::declare_result().template add_field<WithRespectTo>(
      "Optimized");
}

} // namespace simde

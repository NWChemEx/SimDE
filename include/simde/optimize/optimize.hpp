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
#include <pluginplay/pluginplay.hpp>

namespace simde {

/** @brief PT for algorithms which optimize quantities.
 *
 *  @tparam PropertyType The PT of the quantity being optimized. For a
 *                       conventional geometry optimization this would be
 *                       AOEnergy or TotalEnergy. For solving the SCF equations
 *                       it is something like ESCF<type::cmos>.
 *  @tparam WithRespectTo The type of the object being varied to optimize
 *                        @p PropertyType.
 *
 *  As the name implies, the Optimize property type is used by modules which
 *  optimize quantities. It is assumed that the quantity being optimized, i.e.,
 *  the objective function, can be computed by calling a submodule of property
 *  type @p PropertyType. The Optimize PT does NOT assume that quantity being
 *  optimized is a direct input to a module satisfying @p PropertyType, though
 *   it will be in many cases,
 */
template<typename PropertyType, typename WithRespectTo>
DECLARE_TEMPLATED_PROPERTY_TYPE(Optimize, PropertyType, WithRespectTo);

template<typename PropertyType, typename WithRespectTo>
TEMPLATED_PROPERTY_TYPE_INPUTS(Optimize, PropertyType, WithRespectTo) {
    using input_type = const WithRespectTo&;
    auto desc = "Object to optimize the objective function with respect to";
    return PropertyType::inputs().template add_field<input_type>((desc));
}

template<typename PropertyType, typename WithRespectTo>
TEMPLATED_PROPERTY_TYPE_RESULTS(Optimize, PropertyType, WithRespectTo) {
    auto desc = "Object that optimizes the objective function";
    return PropertyType::results().template add_field<WithRespectTo>(desc);
}

} // namespace simde
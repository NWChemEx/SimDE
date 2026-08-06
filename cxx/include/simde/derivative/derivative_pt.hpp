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
#include <simde/derivative/traits.hpp>

namespace simde {

/** @brief Declares the Derivative property type.
 *
 *  The Derivative template property type is templated on the quantity we are
 *  taking the derivative of, the type of the input we are taking the
 *  derivative with respect to, and the type of the resulting derivative.
 *  For example:
 *
 *  ```.cpp
 *  using nuclear_gradient = Derivative<AOEnergy, PointSet, eigen::VectorXd>;
 *  ```
 *
 *  is the property type for a module which computes the nuclear gradient of an
 *  AO-based energy (the use of PointSet makes it clear we don't want
 *  derivatives with respect to say nuclear charge in addition to coordinates)
 *  and returns the gradient as an ``eigen::VectorXd``.
 *
 *  The property types for higher order derivatives, e.g., Hessians, can
 *  be formed by nesting Derivative specializations. For example the Hessian
 *  of the total AO-based energy, with respect to nuclear coordinates, is:
 *
 *  ```.cpp
 *  using nuclear_hessian =
 *    Derivative<nuclear_gradient, PointSet, eigen::MatrixXd>;
 *  ```
 *
 *  It's up to the module developer ctually does nested derivative calls like
 *  the property type suggests or if it just returns the Hessian.
 *
 *  @tparam PropertyType The unqualified property type being differentiated.
 *  @tparam WithRespectTo The unqualified type we are taking the derivative with
 *                        respect to.
 *  @tparam ReturnType The type of the derivative.
 */
template<typename PropertyType, typename WithRespectTo, typename ReturnType>
DECLARE_TEMPLATED_PROPERTY_TYPE(Derivative, PropertyType, WithRespectTo,
                                ReturnType);

template<typename PropertyType, typename WithRespectTo, typename ReturnType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Derivative, PropertyType, WithRespectTo,
                               ReturnType) {
    using my_type = Derivative<PropertyType, WithRespectTo, ReturnType>;
    auto desc     = "Arg " + std::to_string(derivative_order_v<my_type>);
    return PropertyType::inputs().template add_field<WithRespectTo>(desc);
}

template<typename PropertyType, typename WithRespectTo, typename ReturnType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Derivative, PropertyType, WithRespectTo,
                                ReturnType) {
    return pluginplay::declare_result().template add_field<ReturnType>(
      "Derivative");
}

} // namespace simde

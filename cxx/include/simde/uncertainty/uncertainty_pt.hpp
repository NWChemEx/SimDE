/*
 * Copyright 2026 NWChemEx-Project
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

/** @brief Estimates the error of the quantity a property type computes.
 *
 *  Modules satisfying this property type are error models. They take the
 *  inputs of @p BasePT and the screening threshold, and return the error of
 *  the quantity @p BasePT computes, *e.g.*, the error of each ERI.
 *
 *  @tparam BasePT The property type whose quantity's error is estimated.
 */
template<typename BasePT>
DECLARE_TEMPLATED_PROPERTY_TYPE(Uncertainty, BasePT);

template<typename BasePT>
TEMPLATED_PROPERTY_TYPE_INPUTS(Uncertainty, BasePT) {
    auto rv  = BasePT::inputs();
    auto rv0 = rv.template add_field<double>("Tolerance");
    rv0["Tolerance"].set_description("The screening threshold");
    return rv0;
}

template<typename BasePT>
TEMPLATED_PROPERTY_TYPE_RESULTS(Uncertainty, BasePT) {
    return BasePT::results();
}

} // namespace simde

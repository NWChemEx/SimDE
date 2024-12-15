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

DECLARE_PROPERTY_TYPE(GeneralizedEigenSolve);

PROPERTY_TYPE_INPUTS(GeneralizedEigenSolve) {
    using input_type = const type::tensor&;
    auto rv          = pluginplay::declare_input()
                .add_field<input_type>("Matrix")
                .template add_field<input_type>("Metric");
    rv["Matrix"].set_description("The matrix to diagonalize.");
    rv["Metric"].set_description("Metric for the basis set of \"Matrix\".");
    return rv;
}

PROPERTY_TYPE_RESULTS(GeneralizedEigenSolve) {
    using result_type = type::tensor;
    auto rv           = pluginplay::declare_result()
                .add_field<result_type>("Eigen values")
                .template add_field<result_type>("Eigen vectors");
    return rv;
}

} // namespace simde
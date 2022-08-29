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
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {

/** @brief Property type for modules that perform SVD on a 2D matrix.
 *
 *  @tparam ElementType the type of the elements in the tensors
 */
template<typename ElementType = double>
struct SingularValueDecomposition
  : public sde::PropertyType<SingularValueDecomposition<ElementType>> {
    /// The type of the new tensors, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class UpdateMOs

//-------------------------------Implementations--------------------------------
template<typename ElementType>
auto SingularValueDecomposition<ElementType>::inputs_() {
    auto rv = sde::declare_input().add_field<const tensor_type&>("Matrix");
    rv["Matrix"].set_description("The matrix to be decomposed");
    return rv;
}

template<typename ElementType>
auto SingularValueDecomposition<ElementType>::results_() {
    auto rv = sde::declare_result()
                .add_field<std::vector<ElementType>>("S")
                .template add_field<tensor_type>("U")
                .template add_field<tensor_type>("V");
    rv["S"].set_description("The singular values");
    rv["U"].set_description("The left-singular vectors");
    rv["V"].set_description("The right-singular vectors");
    return rv;
}

extern template class SingularValueDecomposition<double>;
extern template class SingularValueDecomposition<float>;

} // namespace simde

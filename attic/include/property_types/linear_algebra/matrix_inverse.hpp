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

/** @brief The property type for modules that perform matrix inversion.
 *
 *  Modules that satisfy this property compute the matrix inverse
 *
 *  A(i,k) * Ainv(k,j) = Ainv(i,k) * A(k,j) = delta(i,j)
 *
 *  where A and Ainv are square rank-2 tensors with Ainv being the inverse of A
 *
 *  @tparam MatrixElementType The type of the elements of the input/output
 * tensors.
 */
template<typename MatrixElementType>
struct MatrixInverse
  : public sde::PropertyType<MatrixInverse<MatrixElementType>> {
    /// Type of the input / output  tensors that accounts for MatrixElementType
    using matrix_tensor_type = type::tensor<MatrixElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
};

//-------------------------------------Implementations--------------------------
template<typename MatrixElementType>
auto MatrixInverse<MatrixElementType>::inputs_() {
    auto rv =
      sde::declare_input().add_field<matrix_tensor_type>("Input Matrix");
    rv["Input Matrix"].set_description("The matrix to be inverted");
    return rv;
} // MatrixInverse<MatrixElementType>::inputs_

template<typename MatrixElementType>
auto MatrixInverse<MatrixElementType>::results_() {
    auto rv = sde::declare_result().add_field<matrix_tensor_type>("Inverse");
    rv["Inverse"].set_description("Inverse of the input matrix");
    return rv;
} // MatrixInverse<MatrixElementType>::results_

extern template class MatrixInverse<double>;
extern template class MatrixInverse<float>;
extern template class MatrixInverse<std::complex<double>>;
extern template class MatrixInverse<std::complex<float>>;

} // namespace simde

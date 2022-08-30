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
#include "simde/linear_algebra/matrix_properties.hpp"
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {

/** @brief The property type for modules that perform cholesky factorizations
 *  of positive definite, self-adjoint matrices, A.
 *
 *  Modules that satisfy this property compute the factorization
 *
 *  A(i,j) = L(i,k) * conj(L(j,k))
 *
 *               or
 *
 *  A(i,j) = conj(U(k,i)) * U(k,j)
 *
 *
 *  for positive definite (SPD/HPD), self-adjoint rank-2 tensors A(i,j) =
 * conj(A(j,i)). L (U) is a lower (upper) triangular rank-2 tensor.
 *
 *  @tparam MatrixElementType The type of the elements of the input/output
 * tensors.
 */
template<typename MatrixElementType>
struct CholeskyFactorization
  : public sde::PropertyType<CholeskyFactorization<MatrixElementType>> {
    /// Type of the input / output  tensors that accounts for MatrixElementType
    using matrix_tensor_type = type::tensor<MatrixElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
};

//-------------------------------------Implementations--------------------------

template<typename MatrixElementType>
auto CholeskyFactorization<MatrixElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<matrix_tensor_type>("Input Matrix")
                .template add_field<MatrixProperties::Triangle>("Triangle");
    rv["Input Matrix"].set_description("The matrix to be factorized");
    rv["Triangle"].set_description("Perform L or U Cholesky factorization");
    return rv;
} // CholeskyFactorization<MatrixElementType>::inputs_

template<typename MatrixElementType>
auto CholeskyFactorization<MatrixElementType>::results_() {
    auto rv =
      sde::declare_result().add_field<matrix_tensor_type>("Cholesky Factor");
    rv["Cholesky Factor"].set_description(
      "Upper or Lower Triangular Cholesky factor");
    return rv;
} // CholeskyFactorization<MatrixElementType>::results_

extern template class CholeskyFactorization<double>;
extern template class CholeskyFactorization<float>;
extern template class CholeskyFactorization<std::complex<double>>;
extern template class CholeskyFactorization<std::complex<float>>;

} // namespace simde

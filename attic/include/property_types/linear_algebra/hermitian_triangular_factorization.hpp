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

/** @brief The property type for modules that perform Bunch-Kaufman
 * factorizations of self-adjoint matrices, A.
 *
 *  Modules that satisfy this property compute the factorization
 *
 *  A(i,j) = L(i,k) * D(k) * conj(L(j,k))
 *
 *               or
 *
 *  A(i,j) = conj(U(k,i)) * D(k) * U(k,j)
 *
 *
 *  self-adjoint rank-2 tensors A(i,j) = conj(A(j,i)). L (U) is a lower (upper)
 * triangular rank-2 tensor and D is diagonal.
 *
 *  @tparam MatrixElementType The type of the elements of the input/output
 * tensors.
 */
template<typename MatrixElementType>
struct BunchKaufmanFactorization
  : public sde::PropertyType<BunchKaufmanFactorization<MatrixElementType>> {
    /// Type of the input / output  tensors that accounts for MatrixElementType
    using matrix_tensor_type = type::tensor<MatrixElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
};

//-------------------------------------Implementations--------------------------

template<typename MatrixElementType>
auto BunchKaufmanFactorization<MatrixElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<matrix_tensor_type>("Input Matrix")
                .template add_field<MatrixProperties::Triangle>("Triangle");
    rv["Input Matrix"].set_description("The matrix to be factorized");
    rv["Triangle"].set_description(
      "Perform L or U Bunch-Kaufman factorization");
    return rv;
} // BunchKaufmanFactorization<MatrixElementType>::inputs_

template<typename MatrixElementType>
auto BunchKaufmanFactorization<MatrixElementType>::results_() {
    auto rv = sde::declare_result()
                .add_field<matrix_tensor_type>("Bunch Kaufman Factor")
                .template add_field<matrix_tensor_type>("D");
    rv["Bunch Kaufman Factor"].set_description(
      "Upper or Lower Triangular Bunch-Kaufman factor");
    rv["D"].set_description("Diagonal Bunch-Kaudman factor");
    return rv;
} // BunchKaufmanFactorization<MatrixElementType>::results_

extern template class BunchKaufmanFactorization<double>;
extern template class BunchKaufmanFactorization<float>;
extern template class BunchKaufmanFactorization<std::complex<double>>;
extern template class BunchKaufmanFactorization<std::complex<float>>;

} // namespace simde

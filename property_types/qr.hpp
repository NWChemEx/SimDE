#pragma once
#include "property_types/types.hpp"
#include "property_types/matrix_properties.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief The property type for modules that perform QR factorizations
 *  of general matrices A = Q * R
 *
 *  Modules that satisfy this property compute the factorization
 *
 *  A(i,j) = Q(i,k) * R(k,j)
 *
 *  for general rank-2 tensors A. Q is a unitary matrix (Q(i,k) * conj(Q(j,k)) = delta(i,j))
 *  and R is upper triangular
 *
 *  @tparam MatrixElementType The type of the elements of the input/output tensors.
 */
template<typename MatrixElementType>
struct QRFactorization : public sde::PropertyType<QRFactorization<MatrixElementType>> {
    /// Type of the input / output  tensors that accounts for MatrixElementType
    using matrix_tensor_type = type::tensor<MatrixElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
};


//-------------------------------------Implementations--------------------------
  
template <typename MatrixElementType>
auto QRFactorization<MatrixElementType>::inputs_() {
  auto rv = sde::declare_input().add_field<matrix_tensor_type>("Input Matrix");
  rv["Input Matrix"].set_description("The matrix to be factorized");
  return rv;
} // QRFactorization<MatrixElementType>::inputs_

template <typename MatrixElementType>
auto QRFactorization<MatrixElementType>::results_() {
  auto rv = sde::declare_result().
              add_field<matrix_tensor_type>("Q").
              template add_field<matrix_tensor_type>("R");
  rv["Q"].set_description("Q of A = Q * R");
  rv["R"].set_description("R of A = Q * R");
  return rv;
} // QRFactorization<MatrixElementType>::results_

extern template class QRFactorization<double>;
extern template class QRFactorization<float>;
extern template class QRFactorization<std::complex<double>>;
extern template class QRFactorization<std::complex<float>>;

} // namespace property_types

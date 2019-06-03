#include "property_types/cholesky.hpp"

namespace property_types {

template class CholeskyFactorization<double>;
template class CholeskyFactorization<float>;
template class CholeskyFactorization<std::complex<double>>;
template class CholeskyFactorization<std::complex<float>>;

} // namespace property_types

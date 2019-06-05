#include "property_types/linear_algebra/hermitian_triangular_factorization.hpp"

namespace property_types {

template class BunchKaufmanFactorization<double>;
template class BunchKaufmanFactorization<float>;
template class BunchKaufmanFactorization<std::complex<double>>;
template class BunchKaufmanFactorization<std::complex<float>>;

} // namespace property_types

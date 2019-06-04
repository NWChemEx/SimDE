#include "property_types/linear_algebra/lu.hpp"

namespace property_types {

template class LUFactorization<double>;
template class LUFactorization<float>;
template class LUFactorization<std::complex<double>>;
template class LUFactorization<std::complex<float>>;

} // namespace property_types

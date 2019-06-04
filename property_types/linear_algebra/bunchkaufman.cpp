#include "property_types/linear_algebra/bunchkaufman.hpp"

namespace property_types {

template class BunchKaufmanFactorization<double>;
template class BunchKaufmanFactorization<float>;
template class BunchKaufmanFactorization<std::complex<double>>;
template class BunchKaufmanFactorization<std::complex<float>>;

} // namespace property_types

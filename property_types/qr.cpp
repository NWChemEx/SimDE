#include "property_types/qr.hpp"

namespace property_types {

template class QRFactorization<double>;
template class QRFactorization<float>;
template class QRFactorization<std::complex<double>>;
template class QRFactorization<std::complex<float>>;

} // namespace property_types

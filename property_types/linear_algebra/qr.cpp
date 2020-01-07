#include "property_types/linear_algebra/qr.hpp"

namespace property_types {

template class QRFactorization<double>;
template class QRFactorization<float>;
template class QRFactorization<std::complex<double>>;
template class QRFactorization<std::complex<float>>;

template class RankRevealingQRFactorization<double>;
template class RankRevealingQRFactorization<float>;
template class RankRevealingQRFactorization<std::complex<double>>;
template class RankRevealingQRFactorization<std::complex<float>>;

} // namespace property_types

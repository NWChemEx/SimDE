#include "property_types/exchange_matrix.hpp"

namespace property_types {

template class ExchangeMatrix<double>;
template class ExchangeMatrix<double, type::orthogonal_orbs<double>>;
template class ExchangeMatrix<double, type::canonical_mos<double>>;
template class ExchangeMatrix<float>;
template class ExchangeMatrix<float,  type::orthogonal_orbs<float>>;
template class ExchangeMatrix<float,  type::canonical_mos<float>>;

} // namespace property_types

#include "property_types/exchange_matrix.hpp"

namespace property_types {

template class ExchangeMatrix<double>;
template class ExchangeMatrix<double, type::derived_space_t<double>>;
template class ExchangeMatrix<double, type::canonical_space_t<double>>;
template class ExchangeMatrix<float>;
template class ExchangeMatrix<float, type::derived_space_t<float>>;
template class ExchangeMatrix<float, type::canonical_space_t<float>>;

} // namespace property_types

#include "property_types/ao_integrals/cgtg.hpp"

namespace property_types {

template class CGTGIntegral<float>;
template class CGTGIntegral<double>;
template class CGTGTimesCoulombIntegral<float>;
template class CGTGTimesCoulombIntegral<double>;

} // namespace property_types

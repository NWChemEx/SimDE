#include "property_types/ao_integrals/electron_repulsion.hpp"

namespace property_types {

template class ERI2CIntegral<double>;
template class ERI2CIntegral<float>;
template class ERI3CIntegral<double>;
template class ERI3CIntegral<float>;
template class ERI4CIntegral<double>;
template class ERI4CIntegral<float>;

} // namespace property_types

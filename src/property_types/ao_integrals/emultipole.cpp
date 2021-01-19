#include "property_types/ao_integrals/emultipole.hpp"

namespace property_types {

template class EDipoleIntegral<double>;
template class EDipoleIntegral<float>;
template class EQuadrupoleIntegral<double>;
template class EQuadrupoleIntegral<float>;
template class EOctopoleIntegral<double>;
template class EOctopoleIntegral<float>;

} // namespace property_types

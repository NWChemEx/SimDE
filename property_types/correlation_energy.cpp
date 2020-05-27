#include "property_types/correlation_energy.hpp"

namespace property_types {

    template class CorrelationEnergy<double>;
    template class CorrelationEnergy<double, type::orthogonal_orbs<double>>;
    template class CorrelationEnergy<double, type::canonical_mos<double>>;
    template class CorrelationEnergy<float>;
    template class CorrelationEnergy<float,  type::orthogonal_orbs<float>>;
    template class CorrelationEnergy<float,  type::canonical_mos<float>>;

} // namespace property_types

#include "property_types/reference_wavefunction.hpp"

namespace property_types {

template class ReferenceWavefunction<double>;
template class ReferenceWavefunction<double, type::derived_space_t<double>>;
template class ReferenceWavefunction<double, type::canonical_space_t<double>>;
template class ReferenceWavefunction<float>;
template class ReferenceWavefunction<float, type::derived_space_t<float>>;
template class ReferenceWavefunction<float, type::canonical_space_t<float>>;

} // namespace property_types

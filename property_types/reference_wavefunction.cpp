#include "property_types/reference_wavefunction.hpp"

namespace property_types {

template class ReferenceWavefunction<double>;
template class ReferenceWavefunction<double, type::orthogonal_orbs<double>>;
template class ReferenceWavefunction<double, type::canonical_mos<double>>;
template class ReferenceWavefunction<float>;
template class ReferenceWavefunction<float,  type::orthogonal_orbs<float>>;
template class ReferenceWavefunction<float,  type::canonical_mos<float>>;

} // namespace property_types

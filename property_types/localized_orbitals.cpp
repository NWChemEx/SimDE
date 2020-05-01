#include "property_types/localized_orbitals.hpp"

namespace property_types {

template class LocalizedOrbitals<type::orbitals<double>>;
template class LocalizedOrbitals<type::orthogonal_orbs<double>>;
template class LocalizedOrbitals<type::canonical_mos<double>>;
template class LocalizedOrbitals<type::orbitals<float>>;
template class LocalizedOrbitals<type::orthogonal_orbs<float>>;
template class LocalizedOrbitals<type::canonical_mos<float>>;

} // namespace property_types

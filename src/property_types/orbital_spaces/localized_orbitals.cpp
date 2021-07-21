#include "property_types/localized_orbitals.hpp"

namespace property_types {

template class LocalizedOrbitals<type::orbital_space_t<double>>;
template class LocalizedOrbitals<type::derived_space_t<double>>;
template class LocalizedOrbitals<type::canonical_space_t<double>>;
template class LocalizedOrbitals<type::orbital_space_t<float>>;
template class LocalizedOrbitals<type::derived_space_t<float>>;
template class LocalizedOrbitals<type::canonical_space_t<float>>;

} // namespace property_types

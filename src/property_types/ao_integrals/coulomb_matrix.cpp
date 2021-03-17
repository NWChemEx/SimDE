#include "property_types/ao_integrals/coulomb_matrix.hpp"

namespace property_types {

template class CoulombMatrix<double>;
template class CoulombMatrix<double, type::derived_space_t<double>>;
template class CoulombMatrix<double, type::canonical_space_t<double>>;
template class CoulombMatrix<float>;
template class CoulombMatrix<float, type::derived_space_t<float>>;
template class CoulombMatrix<float, type::canonical_space_t<float>>;

} // namespace property_types

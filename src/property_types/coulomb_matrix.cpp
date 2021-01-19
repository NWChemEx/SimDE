#include "property_types/coulomb_matrix.hpp"

namespace property_types {

template class CoulombMatrix<double>;
template class CoulombMatrix<double, type::orthogonal_orbs<double>>;
template class CoulombMatrix<double, type::canonical_mos<double>>;
template class CoulombMatrix<float>;
template class CoulombMatrix<float, type::orthogonal_orbs<float>>;
template class CoulombMatrix<float, type::canonical_mos<float>>;

} // namespace property_types

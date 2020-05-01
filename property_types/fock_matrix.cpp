#include "property_types/fock_matrix.hpp"

namespace property_types {

template class FockMatrix<double>;
template class FockMatrix<double, type::orthogonal_orbs<double>>;
template class FockMatrix<double, type::canonical_mos<double>>;
template class FockMatrix<float>;
template class FockMatrix<float,  type::orthogonal_orbs<float>>;
template class FockMatrix<float,  type::canonical_mos<float>>;

} // namespace property_types

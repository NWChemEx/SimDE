#include "property_types/ao_integrals/fock_matrix.hpp"

namespace property_types {

template class FockMatrix<double>;
template class FockMatrix<double, type::derived_space_t<double>>;
template class FockMatrix<double, type::canonical_space_t<double>>;
template class FockMatrix<float>;
template class FockMatrix<float, type::derived_space_t<float>>;
template class FockMatrix<float, type::canonical_space_t<float>>;

} // namespace property_types

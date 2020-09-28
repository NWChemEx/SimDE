#include "property_types/scf_iteration.hpp"

namespace property_types {

template class SCFIteration<double>;
template class SCFIteration<double, type::orthogonal_orbs<double>>;
template class SCFIteration<double, type::canonical_mos<double>>;
template class SCFIteration<float>;
template class SCFIteration<float, type::orthogonal_orbs<float>>;
template class SCFIteration<float, type::canonical_mos<float>>;

} // namespace property_types

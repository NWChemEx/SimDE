#include "property_types/update_mos.hpp"

namespace property_types {

template class UpdateMOs<double>;
template class UpdateMOs<double, type::orthogonal_orbs<double>>;
template class UpdateMOs<double, type::canonical_mos<double>>;
template class UpdateMOs<float>;
template class UpdateMOs<float,  type::orthogonal_orbs<float>>;
template class UpdateMOs<float,  type::canonical_mos<float>>;

} // namespace property_types

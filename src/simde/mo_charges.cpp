#include "simde/mo_charges.hpp"

namespace simde {

template class MOCharges<double>;
template class MOCharges<double, type::derived_space_t<double>>;
template class MOCharges<double, type::canonical_space_t<double>>;
template class MOCharges<float>;
template class MOCharges<float, type::derived_space_t<float>>;
template class MOCharges<float, type::canonical_space_t<float>>;

} // namespace simde

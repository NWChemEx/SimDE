#include "simde/atomic_charges.hpp"

namespace simde {

template class AtomicCharges<double>;
template class AtomicCharges<double, type::derived_space_t<double>>;
template class AtomicCharges<double, type::canonical_space_t<double>>;
template class AtomicCharges<float>;
template class AtomicCharges<float, type::derived_space_t<float>>;
template class AtomicCharges<float, type::canonical_space_t<float>>;

} // namespace simde

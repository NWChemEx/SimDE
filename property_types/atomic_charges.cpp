#include "property_types/atomic_charges.hpp"

namespace property_types {

template class AtomicCharges<double>;
template class AtomicCharges<double, type::orthogonal_orbs<double>>;
template class AtomicCharges<double, type::canonical_mos<double>>;
template class AtomicCharges<float>;
template class AtomicCharges<float,  type::orthogonal_orbs<float>>;
template class AtomicCharges<float,  type::canonical_mos<float>>;

} // namespace property_types
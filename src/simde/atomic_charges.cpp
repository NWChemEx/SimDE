#include "simde/atomic_charges.hpp"

namespace simde {

template class AtomicCharges<type::derived_space>;
template class AtomicCharges<type::canonical_space>;

} // namespace simde

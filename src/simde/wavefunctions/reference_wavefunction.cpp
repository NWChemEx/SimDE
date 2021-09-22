#include "simde/wavefunctions/reference_wavefunction.hpp"

namespace simde {

template class ReferenceWavefunction<type::canonical_reference>;
template class ReferenceWavefunction<type::local_reference>;

} // namespace simde

#pragma once
#include "simde/wavefunctions/correlated_wavefunction.hpp"
#include "simde/wavefunctions/reference_wavefunction.hpp"

namespace simde {

using NoncanonicalReference =
  ReferenceWavefunction<type::noncanonical_reference>;

using CanonicalReference = ReferenceWavefunction<type::canonical_reference>;

using CanonicalManyBodyWf =
  CorrelatedWavefunction<type::canonical_reference, type::canonical_many_body>;

} // namespace simde

#pragma once
#include "simde/wavefunctions/reference_wavefunction.hpp"

namespace simde {

using NoncanonicalReference =
  ReferenceWavefunction<type::noncanonical_reference>;

using CanonicalReference =
  ReferenceWavefunction<type::canonical_reference>;

//using Perturbative = CorrelatedWavefunction<type::canonical_reference,
//                                            type::canonical_perturbative>;

} // namespace simde

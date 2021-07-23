#pragma once
#include "simde/wavefunctions/reference_wavefunction.hpp"

namespace simde {

using NoncanonicalReferenceD =
  ReferenceWavefunction<type::noncanonical_reference, double>;

using CanonicalReferenceD =
  ReferenceWavefunction<type::canonical_reference, double>;

using Perturbative = CorrelatedWavefunction<type::canonical_reference,
                                            type::canonical_perturbative>;

} // namespace simde

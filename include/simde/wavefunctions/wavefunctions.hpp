#pragma once
#include "simde/wavefunctions/correlated_wavefunction.hpp"
#include "simde/wavefunctions/reference_wavefunction.hpp"
#include "simde/wavefunctions/transformed_wavefunction.hpp"

namespace simde {

using CanonicalManyBodyWf =
  CorrelatedWavefunction<type::canonical_reference, type::canonical_many_body>;

using LocalManyBodyWf =
  CorrelatedWavefunction<type::local_reference, type::local_many_body>;

} // namespace simde

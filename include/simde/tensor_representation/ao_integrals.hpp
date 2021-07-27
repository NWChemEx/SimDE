#pragma once
#include "simde/tensor_representation/ao_tensor_representation.hpp"
#include "simde/types.hpp"

namespace simde {

// -----------------------------------------------------------------------------
// ------------------------ Fundamental Integrals ------------------------------
// -----------------------------------------------------------------------------

/// double precision, electron kinetic energy
using EKinetic = TwoCenterAOTensorRepresentation<type::el_kinetic>;

/// Two-center, double precision, electron-electron repulsion integrals
using ERI2 = TwoCenterAOTensorRepresentation<type::el_el_coulomb>;

/// Three-center, double precision, electron-electron repulsion integrals
using ERI3 = ThreeCenterAOTensorRepresentation<type::el_el_coulomb>;

/// Four-center, double precision, electron-electron repulsion integrals
using ERI4 = FourCenterAOTensorRepresentation<type::el_el_coulomb>;

/// double precision, electron-nucleus attraction energies
using ENuclear = TwoCenterAOTensorRepresentation<type::el_nuc_coulomb>;

// ------------------------ SCF/DFT Derived Integrals --------------------------

// The Coulomb matrix (i.e. J) in SCF computed in double precision
using MeanFieldJ = TwoCenterAOTensorRepresentation<type::el_scf_j>;

// The exchange matrix (i.e. K) in SCF computed in double precision
using MeanFieldK = TwoCenterAOTensorRepresentation<type::el_scf_k>;

// The Kohn-Sham XC matrix in DFT computed in double precision
using XC = TwoCenterAOTensorRepresentation<type::el_xc>;

// The Fock matrix computed in double precision
using Fock = TwoCenterAOTensorRepresentation<libchemist::FockOperator>;

} // namespace simde

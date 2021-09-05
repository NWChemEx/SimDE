#pragma once
#include "simde/tensor_representation/ao_tensor_representation.hpp"
#include "simde/types.hpp"

namespace simde {

// -----------------------------------------------------------------------------
// ------------------------ Fundamental Integrals ------------------------------
// -----------------------------------------------------------------------------

using EDOI = TwoCenterAOTensorRepresentation<type::el_el_delta>;

/// Two center, double precision, overlap integrals
using EOverlap = TwoCenterAOTensorRepresentation<type::el_identity>;

/// Two center, double precision, 1st derivative overlap integrals wrt
/// nuclear positions
using EOverlapDeriv = TwoCenterAOTensorRepresentation<type::el_identity_nuc>;

/// double precision, electron kinetic energy
using EKinetic = TwoCenterAOTensorRepresentation<type::el_kinetic>;

/// Two center, double precision, 1st derivative kinetic energy integrals wrt
/// nuclear positions
using EKineticDeriv = TwoCenterAOTensorRepresentation<type::el_kinetic_nuc>;

/// Two-center, double precision, electron-electron repulsion integrals
using ERI2 = TwoCenterAOTensorRepresentation<type::el_el_coulomb>;

/// Three-center, double precision, electron-electron repulsion integrals
using ERI3 = ThreeCenterAOTensorRepresentation<type::el_el_coulomb>;

/// Four-center, double precision, electron-electron repulsion integrals
using ERI4 = FourCenterAOTensorRepresentation<type::el_el_coulomb>;

/// Four center, double precision, 1st derivative electron repulsion integrals
/// wrt nuclear positions
using ERI4Deriv = FourCenterAOTensorRepresentation<type::el_el_coulomb_nuc>;

/// double precision, electron-nucleus attraction energies
using ENuclear = TwoCenterAOTensorRepresentation<type::el_nuc_coulomb>;

/// Two center, double precision, 1st derivative nuclear attraction integrals
/// wrt nuclear positions
using ENuclearDeriv = TwoCenterAOTensorRepresentation<type::el_nuc_coulomb_nuc>;

// ------------------------ SCF/DFT Derived Integrals --------------------------

// The one-electron core Hamiltonian
using CoreH = TwoCenterAOTensorRepresentation<type::core_hamiltonian>;

// The Coulomb matrix (i.e. J) in SCF computed in double precision
using MeanFieldJ = TwoCenterAOTensorRepresentation<type::el_scf_j>;

// The exchange matrix (i.e. K) in SCF computed in double precision
using MeanFieldK = TwoCenterAOTensorRepresentation<type::el_scf_k>;

// The Kohn-Sham XC matrix in DFT computed in double precision
using XC = TwoCenterAOTensorRepresentation<type::el_xc>;

// The Fock matrix computed in double precision
using Fock = TwoCenterAOTensorRepresentation<libchemist::operators::Fock>;

// -----------------------------------------------------------------------------
// ------------------------ F12 Related Integrals ------------------------------
// -----------------------------------------------------------------------------

using STG3 = ThreeCenterAOTensorRepresentation<type::el_el_stg>;

using STG4 = FourCenterAOTensorRepresentation<type::el_el_stg>;

using Yukawa3 = ThreeCenterAOTensorRepresentation<type::el_el_yukawa>;

using Yukawa4 = FourCenterAOTensorRepresentation<type::el_el_yukawa>;

} // namespace simde

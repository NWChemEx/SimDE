#pragma once
#include "simde/tensor_representation/ao_tensor_representation.hpp"
#include "simde/types.hpp"

namespace simde {

// -----------------------------------------------------------------------------
// ------------------------ Fundamental Integrals ------------------------------
// -----------------------------------------------------------------------------

/// double precision, electron kinetic energy
using EKineticD = TwoCenterAOTensorRepresentationD<type::el_kinetic>;

/// Two-center, double precision, electron-electron repulsion integrals
using ERI2D = TwoCenterAOTensorRepresentationD<type::el_el_coulomb>;

/// Three-center, double precision, electron-electron repulsion integrals
using ERI3D = ThreeCenterAOTensorRepresentationD<type::el_el_coulomb>;

/// Four-center, double precision, electron-electron repulsion integrals
using ERI4D = FourCenterAOTensorRepresentationD<type::el_el_coulomb>;

/// double precision, electron-nucleus attraction energies
using ENuclearD = TwoCenterAOTensorRepresentationD<type::el_nuc_coulomb>;

// ------------------------ SCF/DFT Derived Integrals --------------------------

// The Coulomb matrix (i.e. J) in SCF computed in double precision
using MeanFieldJD = TwoCenterAOTensorRepresentationD<type::el_scf_j>;

// The exchange matrix (i.e. K) in SCF computed in double precision
using MeanFieldKD = TwoCenterAOTensorRepresentationD<type::el_scf_k>;

// The Kohn-Sham XC matrix in DFT computed in double precision
using XCD = TwoCenterAOTensorRepresentationD<type::el_xc>;

// The Fock matrix computed in double precision
using FockD = TwoCenterAOTensorRepresentationD<libchemist::FockOperator>;

} // namespace simde

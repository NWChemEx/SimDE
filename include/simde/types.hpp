#pragma once
#include <libchemist/libchemist.hpp>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in sync with
 *  the remainder of the library.
 */
namespace simde::type {

using namespace libchemist::type;

// --------------------- Fundamental Types -------------------------------------

/// Typedef of the class used to describe a molecule
using molecule = libchemist::Molecule;

/// Typedef of the class which describes an entire chemical system
using chemical_system = libchemist::ChemicalSystem;

/// Typedefs for one or more electrons
using electron = libchemist::Electron;
using many_electrons = libchemist::ManyElectrons;

// ------------------------------ Orbital Spaces -------------------------------

/// Typedef of class describing an AO space
using ao_space = libchemist::orbital_space::AOSpaceD;

/// Typedef of class describing an AO space with a sparse map
using sparse_ao_space = libchemist::orbital_space::DepAOSpaceD;

/// Typedef of orbital space obtained by transforming an ao_space
using derived_space = libchemist::orbital_space::DerivedSpaceD;

/// Typedef of orbital space obtained by transforming a sparse_ao_space
using ind_derived_space = libchemist::orbital_space::IndDerivedSpace;

/// Typedef of derived orbital space which has a sparse map
using dep_derived_space = libchemist::orbital_space::DepDerivedSpace;

/// Typedef of an orbital space with orbitals that diagonalize the Fock matrix
using canonical_space = libchemist::orbital_space::CanonicalSpaceD;

// ---------------------- Tensors ---------------------------------------------

using tensor = libchemist::type::tensor;

using tensor_of_tensors = libchemist::type::tensor_of_tensors;

// -----------------------------------------------------------------------------
// ----------------------------- Operators -------------------------------------
// -----------------------------------------------------------------------------

using nuc_nuc_coulomb = libchemist::NuclearNuclearCoulomb;

using el_dipole = libchemist::ElectricDipole;

using el_el_coulomb = libchemist::ElectronElectronCoulomb;
using nel_nel_coulomb = libchemist::NElectronNElectronCoulomb;

using el_el_delta = libchemist::ElectronElectronDelta;

using el_el_stg = libchemist::ElectronElectronSTG;

using el_el_yukawa = libchemist::ElectronElectronYukawa;

using el_identity = libchemist::ElectronIdentity;

using el_kinetic = libchemist::ElectronKinetic;
using nel_kinetic = libchemist::NElectronKinetic;

using el_nuc_coulomb = libchemist::ElectronNuclearCoulomb;
using nel_nuc_coulomb = libchemist::NElectronNuclearCoulomb;

using el_octupole = libchemist::ElectricOctupole;

using el_quadrupole = libchemist::ElectricQuadrupole;

using el_scf_j = libchemist::ElectronEDensityCoulomb;

using el_scf_k = libchemist::ElectronEDensityExchange;

using el_xc = libchemist::ExchangeCorrelation;

using fock = libchemist::FockOperator;

using hamiltonian = libchemist::Hamiltonian;

// -----------------------------------------------------------------------------
// ---------------------------- Wavefunctions ----------------------------------
// -----------------------------------------------------------------------------

using noncanonical_reference = libchemist::wavefunction::Reference;

using canonical_reference = libchemist::wavefunction::CanonicalReference;

using noncanonical_local_reference = libchemist::wavefunction::LocalReference;

using canonical_local_reference =
  libchemist::wavefunction::CanonicalLocalReference;

using many_body = libchemist::wavefunction::ManyBodyWf;

using canonical_many_body = libchemist::wavefunction::CanonicalManyBodyWf;

using local_many_body = libchemist::wavefunction::LocalManyBodyWf;

using canonical_local_many_body =
  libchemist::wavefunction::CanonicalLocalManyBodyWf;

// ---------------------------- Other ------------------------------------------

/// Typedef of the class used for connectivity information
using connectivity_table = libchemist::topology::ConnectivityTable;

/// Typedef of the class used for molecular topology
using topology = libchemist::topology::Topology;

} // namespace simde::type

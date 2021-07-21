#pragma once
#include <libchemist/libchemist.hpp>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in sync with
 *  the remainder of the library.
 */
namespace property_types::type {

using namespace libchemist::type;

// --------------------- Fundamental Input -------------------------------------

/// Typedef of the class used to describe a molecule
using molecule = libchemist::Molecule;

/// Typedef of the class which describes an entire chemical system
using chemical_system = libchemist::ChemicalSystem;

// ------------------------------ Orbital Spaces -------------------------------

/// Typedef of class describing an AO space
template<typename T>
using ao_space = libchemist::orbital_space::AOSpace<T>;

/// Typedef of class describing an AO space with a sparse map
template<typename T>
using sparse_ao_space = libchemist::orbital_space::SparseAOSpace<T>;

/// Typedef of orbital space obtained by transforming an ao_space
template<typename>
using derived_space = libchemist::orbital_space::DerivedSpaceD;

/// Typedef of orbital space obtained by transforming a sparse_ao_space
template<typename>
using ind_derived_space = libchemist::orbital_space::IndDerivedSpaceD;

/// Typedef of derived orbital space which has a sparse map
template<typename>
using dep_derived_space = libchemist::orbital_space::DepDerivedSpaceD;

template<typename T>
using canonical_space_t = libchemist::orbital_space::CanonicalSpace<T>;

// ---------------------- Tensors ---------------------------------------------

using tensor = libchemist::tensor::type::SparseTensorWrapper;

using tensor_of_tensors = libchemist::tensor::type::ToTWrapper;

// -----------------------------------------------------------------------------
// ----------------------------- Operators -------------------------------------
// -----------------------------------------------------------------------------

using el_kinetic = libchemist::ElectronKinetic;

using el_el_coulomb = libchemist::ElectronElectronCoulomb;

using el_nuc_coulomb = libchemist::ElectronNuclearCoulomb;

using el_scf_j = libchemist::MeanFieldElectronCoulomb;

using el_scf_k = libchemist::MeanFieldElectronExactExchange;

using el_xc = libchemist::KohnShamExchangeCorrelation;

using fock = libchemist::FockOperator;

using hamiltonian = libchemist::HamiltonianOperator;

// -----------------------------------------------------------------------------
// ---------------------------- Wavefunctions ----------------------------------
// -----------------------------------------------------------------------------

using noncanonical_reference = libchemist::Reference;

using canonical_reference = libchemist::CanonicalReference;

using noncanonical_local_reference = libchemist::LocalReference;

using canonical_local_reference = libchemist::CanonicalLocalReference;

using perturbative = libchemist::Perturbative;

using canonical_perturbative = libchemist::CanonicalPerturbative;

using noncanonical_local_perturbative = libchemist::LocalPerturbative;

using canonical_local_perturbative = libchemist::CanonicalLocalPerturbative;

// ---------------------------- Other ------------------------------------------

/// Typedef of the class used for connectivity information
using connectivity_table = libchemist::topology::ConnectivityTable;

/// Typedef of the class used for molecular topology
using topology = libchemist::topology::Topology;

/// Typedef of the classes modeling the orbital spaces

} // namespace property_types::type

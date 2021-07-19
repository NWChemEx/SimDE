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

template<typename T>
using ao_space = libchemist::orbital_space::AOSpace<T>;

template<typename T>
using sparse_ao_space = libchemist::orbital_space::SparseAOSpace<T>;

// ---------------------- Tensors ---------------------------------------------

template<typename T>
using tensor  = libchemist::type::tensor<T>;

template<typename T>
using tensor_of_tensors = libchemist::type::tensor_of_tensors<T>;

/// Typedef of the class used for connectivity information
using connectivity_table = libchemist::topology::ConnectivityTable;

/// Typedef of the class used for molecular topology
using topology = libchemist::topology::Topology;

/// Typedef of the classes modeling the orbital spaces
template<typename T>
using orbital_space_t = libchemist::orbital_space::BaseSpace<T>;

template<typename T>
using sparse_space_t = libchemist::orbital_space::SparseBase<T>;

template<typename T>
using derived_space_t = libchemist::orbital_space::DerivedSpace<T>;

template<typename T>
using sparse_independent_t =
  libchemist::orbital_space::SparseIndependentSpace<T>;

template<typename T>
using sparse_derived_t = libchemist::orbital_space::SparseDerivedSpace<T>;

template<typename T>
using canonical_space_t = libchemist::orbital_space::CanonicalSpace<T>;

} // namespace property_types::type
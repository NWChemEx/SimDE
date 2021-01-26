#pragma once
#include <libchemist/molecule/molecule.hpp>
#include <libchemist/orbital_space/orbital_space.hpp>
#include <libchemist/types.hpp>
#include <sde/types.hpp>
#include <utilities/containers/case_insensitive_map.hpp>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in sync with
 *  the remainder of the library.
 */
namespace property_types::type {

/// Typedef of the class used for tensors
template<typename T>
using tensor = libchemist::type::tensor<T>;

/// Typedef of the class used to describe a molecule
using molecule = libchemist::Molecule;

/// Typedef of the classes modeling the orbital spaces
template<typename T>
using orbital_space_t = libchemist::orbital_space::BaseSpace<T>;

template<typename T>
using ao_space_t = libchemist::orbital_space::AOSpace<T>;

template<typename T>
using sparse_ao_space_t = libchemist::orbital_space::SparseAOSpace<T>;

template<typename T>
using derived_space_t = libchemist::orbital_space::DerivedSpace<T>;

template<typename T>
using canonical_space_t = libchemist::orbital_space::CanonicalSpace<T>;

/// Typedef of a map containing multiple OrbitalSpaces
template<typename T>
using orbital_map = utilities::CaseInsensitiveMap<T>;

/// Type of a non-negative counting number
using size = std::size_t;

} // namespace property_types::type
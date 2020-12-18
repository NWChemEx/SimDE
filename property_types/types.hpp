#pragma once
#include <libchemist/basis_set/ao_basis_set/ao_basis_set.hpp>
#include <libchemist/canonical_mos.hpp>
#include <libchemist/molecule.hpp>
#include <libchemist/orbital_space.hpp>
#include <libchemist/orthogonal_space.hpp>
#include <libchemist/types.hpp>
#include <libchemist/ta_helpers/ta_hashers.hpp>
#include <random>
#include <sde/types.hpp>
#include <utilities/containers/case_insensitive_map.hpp>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in sync with
 *  the remainder of the library.
 */
namespace property_types {
namespace type {

/// Typedef of the class used for tensors
template<typename T>
using tensor = libchemist::type::tensor<T>;

/// Typedef of the class used to describe a molecule
using molecule = libchemist::Molecule;

/// Typedef of the class used to describe an AO basis set
template<typename T>
using basis_set = libchemist::AOBasisSet<T>;

/// Typedef of the classes modeling the orbital spaces
template<typename T>
using orbitals = libchemist::OrbitalSpace<T>;
template<typename T>
using orthogonal_orbs = libchemist::OrthogonalSpace<T>;
template<typename T>
using canonical_mos = libchemist::CanonicalMO<T>;

/// Typedef of a map containing multiple OrbitalSpaces
template<typename T>
using orbital_map = utilities::CaseInsensitiveMap<T>;

/// Type of a non-negative counting number
using size = std::size_t;

} // namespace type
} // namespace property_types
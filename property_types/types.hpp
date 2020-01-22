#pragma once
#include <libchemist/basis_set/ao_basis_set/ao_basis_set.hpp>
#include <libchemist/molecule.hpp>
#include <libchemist/orbital_space.hpp>
#include <libchemist/types.hpp>
#include <random>

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

/// Typedef of the class modeling the orbital space
template<typename T>
using orbitals = libchemist::OrbitalSpace<T>;

/// Type of a non-negative counting number
using size = std::size_t;

} // namespace type
} // namespace property_types

/*
// These allow sdeAny to wrap a tamm::Tensor, needed for Cache retrieval
namespace tamm {
template<typename T, typename U>
bool operator==(const Tensor<T>& lhs, const Tensor<U>& rhs) {
    return false;
}

inline void hash_object(const Tensor<double>& t, sde::Hasher& h) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist;
    h(dist(rng), dist(rng), dist(rng), dist(rng));
}
} // namespace tamm
*/

#pragma once
#include <LibChemist/AOBasisSet.hpp>
#include <LibChemist/Molecule.hpp>
#include <LibChemist/OrbitalSpace.hpp>
#include <tamm/tamm.hpp>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in synch with
 *  the remainder of the library.
 */
namespace property_types {
namespace type {

/// Typedef of the class used for tensors
template<typename T>
using tensor = tamm::Tensor<T>;

/// Typedef of the class used to describe a molecule
using molecule = LibChemist::Molecule;

/// Typedef of the class used to describe an AO basis set
using basis_set = LibChemist::AOBasisSet;

/// Typedef of the class modeling the orbital space
template<typename T>
using orbitals = LibChemist::OrbitalSpace<T>;

/// Type of a non-negative counting number
using size = std::size_t;

} // namespace type
} // namespace property_types

// These allow SDEAny to wrap a tamm::Tensor, needed for Cache retrieval
namespace tamm {
template<typename T, typename U>
bool operator==(const Tensor<T>& lhs, const Tensor<U>& rhs) {
    return false;
}

inline void hash_object(const Tensor<double>& t, SDE::Hasher& h) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist;
    h(dist(rng), dist(rng), dist(rng), dist(rng));
}
} // namespace tamm

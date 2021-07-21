#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that compute an initial reference
 *         wavefunction.
 *
 *  Most correlated electronic structure theory methods require an initial
 *  reference wavefunction from which
 *
 *  @tparam ElementType The type of the returned energy
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
template<typename WavefunctionType, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(ReferenceWavefunction, WavefunctionType,
                                ElementType);

template<typename WavefunctionType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ReferenceWavefunction, WavefunctionType,
                               ElementType) {
    using ham_t = const type::hamiltonian&;
    using ao_t  = const type::ao_space<ElementType>&;

    auto rv = sde::declare_input()
                .add_field<ham_t>("Hamiltonian")
                .add_field<ao_t>("AO Basis Set");
    return rv;
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ReferenceWavefunction, ElementType) {
    auto rv =
      sde::declare_result().add_field<canonical_reference>("Wavefunction");

    return rv;
}

extern template class ReferenceWavefunction<type::canonical_reference, double>;
extern template class ReferenceWavefunction<type::canonical_reference, float>;

} // namespace property_types

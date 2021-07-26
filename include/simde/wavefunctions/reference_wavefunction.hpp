#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

/** @brief Property type for modules that compute an initial reference
 *         wavefunction.
 *
 *  Most correlated electronic structure theory methods require an initial
 *  reference wavefunction from which
 *
 *  @tparam ElementType The type of the returned energy
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
template<typename WavefunctionType>
DECLARE_TEMPLATED_PROPERTY_TYPE(ReferenceWavefunction, WavefunctionType);

template<typename WavefunctionType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ReferenceWavefunction, WavefunctionType) {
    using ham_t = const type::hamiltonian&;
    using ao_t  = const type::ao_space&;

    auto rv = pluginplay::declare_input()
                .add_field<ham_t>("Hamiltonian")
                .add_field<ao_t>("AO Basis Set");
    return rv;
}

template<typename WavefunctionType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ReferenceWavefunction, WavefunctionType) {
    auto rv = pluginplay::declare_result().add_field<type::canonical_reference>(
      "Wavefunction");

    return rv;
}

extern template class ReferenceWavefunction<type::canonical_reference>;

} // namespace simde

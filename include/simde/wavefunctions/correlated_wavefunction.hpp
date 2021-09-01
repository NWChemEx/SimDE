#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename InputWavefunction, typename OutputWavefunction>
DECLARE_TEMPLATED_PROPERTY_TYPE(CorrelatedWavefunction, InputWavefunction,
                                OutputWavefunction);

template<typename InputWavefunction, typename OutputWavefunction>
TEMPLATED_PROPERTY_TYPE_INPUTS(CorrelatedWavefunction, InputWavefunction,
                               OutputWavefunction) {
    using op    = const type::els_hamiltonian&;
    using in_wf = const InputWavefunction&;

    auto rv = pluginplay::declare_input()
                .add_field<op>("Hamiltonian")
                .template add_field<in_wf>("Referencw Wavefunction");

    return rv;
}

template<typename InputWavefunction, typename OutputWavefunction>
TEMPLATED_PROPERTY_TYPE_RESULTS(CorrelatedWavefunction, InputWavefunction,
                                OutputWavefunction) {
    using out_wf = OutputWavefunction;

    auto rv =
      pluginplay::declare_result().add_field<out_wf>("Correlated Wavefunction");

    return rv;
}

} // namespace simde

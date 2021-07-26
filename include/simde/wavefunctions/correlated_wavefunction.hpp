#pragma once

namespace simde {

template<typename InputWavefunction, typename OutputWavefunction>
DECLARE_TEMPLATED_PROPERTY_TYPE(CorrelatedWavefunction, InputWavefunction,
                                OutputWavefunction);

template<typename InputWavefunction, typename OutputWavefunction>
TEMPLATED_PROPERTY_TYPE_INPUTS(CorrelatedWavefunction, InputWavefunction,
                               OutputWavefunction) {
    using op    = const type::hamiltonian&;
    using in_wf = const InputWavefunction&;

    auto rv = pluginplay::declare_inputs()
                .add_field<op>("Hamiltonian")
                .template add_field<in_wf>("Referencw Wavefunction");

    return rv;
}

template<typename InputWavefunction, typename OutputWavefunction>
TEMPLATED_PROPERTY_TYPE_RESULTS(CorrelatedWavefunction, InputWavefunction,
                                OutputWavefunction) {
    using out_wf = const OutputWavefunction&;

    auto rv = pluginplay::declare_results().add_field<out_wf>(
      "Correlated Wavefunction");

    return rv;
}

} // namespace simde

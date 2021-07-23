#pragma once

namespace simde {

template<typename WavefunctionType>
DECLARE_TEMPLATED_PROPERTY_TYPE(WavefunctionEnergy, WavefunctionType);

template<typename WavefunctionType>
TEMPLATED_PROPERTY_TYPE_INPUTS(WavefunctionEnergy, WavefunctionType) {
    using ham_t = const type::hamiltonian&;
    using wf_t  = const WavefunctionType&;

    auto rv = sde::declare_input()
                .add_field<ham_t>("Hamiltonian")
                .template add_field<wf_t>("Wavefunction");
    return rv;
}

template<typename WavefunctionType>
TEMPLATED_PROPERTY_TYPE_RESULTS(WavefunctionEnergy, WavefunctionType) {
    auto rv = sde::declare_result().add_field<double>("Energy");
    return rv;
}

} // namespace simde

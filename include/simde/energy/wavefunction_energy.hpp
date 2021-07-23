#pragma once

namespace simde {

template<typename WavefunctionType, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(WavefunctionEnergy, WavefunctionType,
                                ElementType);

template<typename WavefunctionType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(WavefunctionEnergy, WavefunctionType,
                               ElementType) {
    using ham_t = const type::hamiltonian&;
    using wf_t  = const WavefunctionType&;

    auto rv = sde::declare_inputs()
                .add_field<ham_t>("Hamiltonian")
                .template add_field<wf_t>("Wavefunction");
    return rv;
}

template<typename WavefunctionType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(WavefunctionEnergy, WavefunctionType,
                                ElementType) {
    auto rv = sde::declare_results().add_field<ElementType>("Energy");
    return rv;
}

} // namespace simde

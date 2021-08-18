#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename BraType, typename KetType>
DECLARE_TEMPLATED_PROPERTY_TYPE(CorrelationEnergy, BraType, KetType);

template<typename BraType, typename KetType>
TEMPLATED_PROPERTY_TYPE_INPUTS(CorrelationEnergy, BraType, KetType) {
    using ham_t = const type::els_hamiltonian&;

    auto rv = pluginplay::declare_input()
                .add_field<const BraType&>("Bra")
                .template add_field<ham_t>("Hamiltonian")
                .template add_field<const KetType&>("Ket");
    return rv;
}

template<typename BraType, typename KetType>
TEMPLATED_PROPERTY_TYPE_RESULTS(CorrelationEnergy, BraType, KetType) {
    auto rv =
      pluginplay::declare_result().add_field<double>("Correlation Energy");
    return rv;
}

} // namespace simde

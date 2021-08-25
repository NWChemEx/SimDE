#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename BraType, typename KetType, typename OpType>
DECLARE_TEMPLATED_PROPERTY_TYPE(BraKet, BraType, KetType, OpType);

template<typename BraType, typename KetType, typename OpType>
TEMPLATED_PROPERTY_TYPE_INPUTS(BraKet, BraType, KetType) {
    using op_t = const OpType&;

    auto rv = pluginplay::declare_input()
                .add_field<const BraType&>("Bra")
                .template add_field<op_t>("Operator")
                .template add_field<const KetType&>("Ket");
    return rv;
}

template<typename BraType, typename KetType, typename OpType>
TEMPLATED_PROPERTY_TYPE_RESULTS(BraKet, BraType, KetType) {
    auto rv = pluginplay::declare_result().add_field<double>("value");
    return rv;
}

template<typename BraType, typename KetType>
using CorrelationEnergy = BraKet<BraType, KetType, type::els_hamiltonian>;

template<typename BraType>
using ElectronicEnergy = BraKet<BraType, BraType, type::els_hamiltonian>;

template<typename BraType>
using TotalEnergy = BraKet<BraType, BraType, type::hamiltonian>;

} // namespace simde

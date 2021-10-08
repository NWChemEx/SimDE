#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename BraType, typename OpType, typename KetType>
DECLARE_TEMPLATED_PROPERTY_TYPE(BraKetDeriv, BraType, OpType, KetType);

template<typename BraType, typename OpType, typename KetType>
TEMPLATED_PROPERTY_TYPE_INPUTS(BraKetDeriv, BraType, OpType, KetType) {
    using op_t = const OpType&;

    auto rv = pluginplay::declare_input()
                .add_field<const BraType&>("Bra")
                .template add_field<op_t>("Operator")
                .template add_field<const KetType&>("Ket");
    return rv;
}

template<typename BraType, typename OpType, typename KetType>
TEMPLATED_PROPERTY_TYPE_RESULTS(BraKetDeriv, BraType, OpType, KetType) {
    auto rv = pluginplay::declare_result()
                .add_field<std::vector<libchemist::Point<double>>>("gradient");
    return rv;
}

template<typename BraType>
using ElectronicEnergy_Nuclear =
  BraKetDeriv<BraType, type::els_hamiltonian_nuc, BraType>;

template<typename BraType>
using TotalEnergy_Nuclear =
  BraKetDeriv<BraType, type::hamiltonian_nuc, BraType>;

} // namespace simde

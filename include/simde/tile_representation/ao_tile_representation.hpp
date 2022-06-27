#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

template<std::size_t N, typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(AO_NuclearTileRepresentation, N, OperatorType);

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AO_NuclearTileRepresentation, N, OperatorType) {
    using const_ao_space_t = const simde::type::ao_space;
    using const_mol_t      = const simde::type::molecule;
    OperatorType op;
    auto op_key = op.as_string();
    if constexpr(N == 2) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>(op_key)
          .template add_field<const_ao_space_t>("ket")
          .template add_field<const_mol_t>("coords");
    } else if constexpr(N == 3) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>(op_key)
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2")
          .template add_field<const_mol_t>("coords");
    } else if constexpr(N == 4) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra 1")
          .template add_field<const_ao_space_t>("bra 2")
          .template add_field<const OperatorType&>(op_key)
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2")
          .template add_field<const_mol_t>("coords");
    } else {
        // N.B. if we get here we know N != 2, but we can't just hardcode false
        static_assert(N == 2, "Inputs not defined for N outside range [2, 4]");
    }
}

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AO_NuclearTileRepresentation, N, OperatorType) {
    OperatorType op;
    auto op_name      = op.as_string();
    std::string r_key = "tile representation";
    if constexpr(N == 2) {
        r_key = "∂(μ|" + op_name + "|ν)/∂R";
    } else if constexpr(N == 3) {
        r_key = "∂(μ|" + op_name + "|νλ)/∂R";
    } else if constexpr(N == 4) {
        r_key = "∂(μν|" + op_name + "|λθ)/∂R";
    }
    return pluginplay::declare_result().add_field<type::tensor>(r_key);
}

template<typename OperatorType>
using TwoCenterAO_NuclearTileRepresentation =
  AO_NuclearTileRepresentation<2, OperatorType>;

template<typename OperatorType>
using ThreeCenterAO_NuclearTileRepresentation =
  AO_NuclearTileRepresentation<3, OperatorType>;

template<typename OperatorType>
using FourCenterAO_NuclearTileRepresentation =
  AO_NuclearTileRepresentation<4, OperatorType>;

} // namespace simde

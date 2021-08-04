#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

namespace {

template<typename OperatorType>
auto name_operator() {
    if constexpr(std::is_same_v<OperatorType, simde::type::el_identity>) {
        return "[I_1]";
    } else if constexpr(std::is_same_v<OperatorType, simde::type::el_dipole>) {
        return "[r_1]";
    } else if constexpr(std::is_same_v<OperatorType,
                                       simde::type::el_quadrupole>) {
        return "[r_1]^2";
    } else if constexpr(std::is_same_v<OperatorType,
                                       simde::type::el_octupole>) {
        return "[r_1]^3";
    } else {
        return "op";
    }
}

} // namespace

template<std::size_t N, typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(AOTensorRepresentation, N, OperatorType);

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AOTensorRepresentation, N, OperatorType) {
    using const_ao_space_t = const simde::type::ao_space;
    auto op_key            = name_operator<OperatorType>();
    using const_ao_space_t = const type::ao_space;

    if constexpr(N == 2) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>(op_key)
          .template add_field<const_ao_space_t>("ket");
    } else if constexpr(N == 3) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>(op_key)
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else if constexpr(N == 4) {
        return pluginplay::declare_input()
          .add_field<const_ao_space_t>("bra 1")
          .template add_field<const_ao_space_t>("bra 2")
          .template add_field<const OperatorType&>(op_key)
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else {
        // N.B. if we get here we know N != 2, but we can't just hardcode false
        static_assert(N == 2, "Inputs not defined for N outside range [2, 4]");
    }
}

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AOTensorRepresentation, N, OperatorType) {
    auto op_name = name_operator<OperatorType>();
    auto r_key   = std::string(op_name) + " tensor representation";
    return pluginplay::declare_result().add_field<type::tensor>(r_key);
}

template<typename OperatorType>
using TwoCenterAOTensorRepresentation = AOTensorRepresentation<2, OperatorType>;

template<typename OperatorType>
using ThreeCenterAOTensorRepresentation =
  AOTensorRepresentation<3, OperatorType>;

template<typename OperatorType>
using FourCenterAOTensorRepresentation =
  AOTensorRepresentation<4, OperatorType>;

} // namespace simde

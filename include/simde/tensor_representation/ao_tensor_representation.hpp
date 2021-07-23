#pragma once
#include <sde/property_type/property_type.hpp>

namespace simde {

template<std::size_t N, typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(AOTensorRepresentation, N, OperatorType,
                                ElementType);

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AOTensorRepresentation, N, OperatorType,
                               ElementType) {
    using const_ao_space_t = const type::ao_space;

    if constexpr(N == 2) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>("op")
          .template add_field<const_ao_space_t>("ket");
    } else if constexpr(N == 3) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const OperatorType&>("op")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else if constexpr(N == 4) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra 1")
          .template add_field<const_ao_space_t>("bra 2")
          .template add_field<const OperatorType&>("op")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else {
        // N.B. if we get here we know N != 2, but we can't just hardcode false
        static_assert(N == 2, "Inputs not defined for N outside range [2, 4]");
    }
}

template<std::size_t N, typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AOTensorRepresentation, N, OperatorType) {
    return sde::declare_result().add_field<type::tensor>(
      "tensor representation");
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

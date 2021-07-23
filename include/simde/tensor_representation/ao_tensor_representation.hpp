#pragma once
#include <sde/property_type/property_type.hpp>

namespace simde {

template<std::size_t N, typename OperatorType, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(AOTensorRepresentation, N, OperatorType,
                                ElementType);

template<std::size_t N, typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AOTensorRepresentation, N, OperatorType,
                               ElementType) {
    using const_ao_space_t = const type::ao_space<ElementType>&;

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

template<std::size_t N, typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AOTensorRepresentation, N, OperatorType,
                                ElementType) {
    return sde::declare_result().add_field<type::tensor>(
      "tensor representation");
}

template<std::size_t N, typename OperatorType>
using AOTensorRepresentationD = TensorRepresentation<N, OperatorType, double>;

template<typename OperatorType>
using TwoCenterAOTensorRepresentationD =
  AOTensorRepresentationD<2, OperatorType>;

template<typename OperatorType>
using ThreeCenterAOTensorRepresentationD =
  AOTensorRepresentationD<3, OperatorType>;

template<typename OperatorType>
using FourCenterAOTensorRepresentationD =
  AOTensorRepresentationD<4, OperatorType>;

} // namespace simde

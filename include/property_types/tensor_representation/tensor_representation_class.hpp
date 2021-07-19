#pragma once
#include <sde/property_type/property_type.hpp>

namespace property_types {

template<std::size_t N, typename OperatorType, typename SpaceType>
DECLARE_TEMPLATED_PROPERTY_TYPE(TensorRepresentation, N, OperatorType,
                                SpaceType);

template<std::size_t N, typename OperatorType, typename SpaceType>
TEMPLATED_PROPERTY_TYPE_INPUTS(TensorRepresentation, N, OperatorType,
                               AOSpaceType) {
    using const_ao_space_t = const AOSpaceType&;

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

template<std::size_t N, typename OperatorType, typename SpaceType>
TEMPLATED_PROPERTY_TYPE_RESULTS(TensorRepresentation, N, OperatorType,
                                AOSpaceType) {
    constexpr bool is_tot = false;
    using ElementType     = double;
    using tot_type = type::tensor_of_tensors<ElementType>;
    using tensor_type = type::tensor<ElementType>;
    
    using result_type = std::conditional_t<is_tot, tot_type, tensor_type>;
    return sde::declare_result()
        .add_field<result_type>("tensor representation");
}

} // namespace property_types
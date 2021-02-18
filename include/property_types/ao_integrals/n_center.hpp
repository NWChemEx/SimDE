#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals {

template<std::size_t N, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(NCenter, N, ElementType);

template<std::size_t N, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(NCenter, N, ElementType) {
    using const_ao_space_t = const type::ao_space_t<ElementType>&;

    if constexpr(N == 2) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const_ao_space_t>("ket");
    } else if constexpr(N == 3) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else if constexpr(N == 4) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra 1")
          .template add_field<const_ao_space_t>("bra 2")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else {
        // N.B. if we get here we know N != 2, but we can't just hardcode false
        static_assert(N == 2, "Inputs not defined for N not in range [2, 4]");
    }
}

template<std::size_t N, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(NCenter, N, ElementType) {
    return sde::declare_result();
}

template<typename ElementType>
using TwoCenter = NCenter<2, ElementType>;

template<typename ElementType>
using ThreeCenter = NCenter<3, ElementType>;

template<typename ElementType>
using FourCenter = NCenter<4, ElementType>;

} // namespace property_types::ao_integrals
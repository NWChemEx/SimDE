#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals {

template<typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(FourCenter, ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(FourCenter, ElementType) {
    using const_ao_space_t = const type::ao_space_t<ElementType>&;

    return sde::declare_input()
      .add_field<const_ao_space_t>("bra 1")
      .template add_field<const_ao_space_t>("bra 2")
      .template add_field<const_ao_space_t>("ket 1")
      .template add_field<const_ao_space_t>("ket 2");
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(FourCenter, ElementType) {
    using tensor_t = type::tensor<ElementType>;

    return sde::declare_result().add_field<tensor_t>("(pq|O|rs)");
}

} // namespace property_types::ao_integrals
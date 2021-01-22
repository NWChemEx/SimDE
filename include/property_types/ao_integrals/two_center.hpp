#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals {

template<typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(TwoCenter, ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(TwoCenter, ElementType) {
    using const_ao_space_t = const type::ao_space_t<ElementType>&;

    return sde::declare_input()
      .add_field<const_ao_space_t>("bra")
      .template add_field<const_ao_space_t>("ket");
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(TwoCenter, ElementType) {
    return sde::declare_result();
}

} // namespace property_types::ao_integrals
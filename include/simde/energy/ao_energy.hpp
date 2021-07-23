#pragma once
#include "simde/energy/energy_class.hpp"
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {

template<typename AOSpace, typename ElementType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(AOEnergy, Energy<ElementType>, AOSpace,
                                        ElementType);

template<typename AOSpace, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AOEnergy, AOSpace, ElementType) {
    auto rv = sde::declare_input().add_field<const AOSpace&>("AOs");
    rv["AOs"].set_description("The atomic orbital basis set");
    return rv;
}

template<typename AOSpace, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AOEnergy, AOSpace, ElementType) {
    return sde::declare_result();
}

extern template class AOEnergy<type::ao_space<double>, double>;
extern template class AOEnergy<type::ao_space<float>, float>;
extern template class AOEnergy<type::sparse_ao_space<double>, double>;
extern template class AOEnergy<type::sparse_ao_space<float>, float>;

} // namespace simde

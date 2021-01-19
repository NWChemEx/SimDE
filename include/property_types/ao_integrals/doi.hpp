#pragma once
#include "property_types/ao_integrals/two_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with
 * differential overlap integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename ElementType = double>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(DOI,
                                        ao_integral::TwoCenter<ElementType>,
                                        ElementType);

template<typename ElementType>
TEMPLATE_PROPERTY_TYPE_INPUTS(DOI, ElementType) {
    return sde::declare_input();
}

template<typename ElementType>
TEMPLATE_PROPERTY_TYPE_RESULTS(DOI, ElementType) {
    return sde::decalre_result();
}

extern template class DOI<double>;
extern template class DOI<float>;

} // namespace property_types

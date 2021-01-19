#pragma once
#include "property_types/ao_integrals/four_center.hpp"
#include "property_types/ao_integrals/three_center.hpp"
#include "property_types/ao_integrals/two_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with electron
 * repulsion integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename ElementType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(ERI2C,
                                        ao_integral::TwoCenter<ElementType>,
                                        ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ERI2C, ElementType) {
    return sde::declare_input();
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ERI2C, ElementType) {
    return sde::declare_result();
}

template<typename ElementType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(ERI3C,
                                        ao_integral::ThreeCenter<ElementType>,
                                        ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ERI3C, ElementType) {
    return sde::declare_input();
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ERI3C, ElementType) {
    return sde::declare_result();
}

template<typename ElementType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(ERI4C,
                                        ao_integral::FourCenter<ElementType>,
                                        ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ERI4C, ElementType) {
    return sde::declare_input();
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ERI4C, ElementType) {
    return sde::declare_result();
}

extern template class ERI2C<double>;
extern template class ERI2C<float>;
extern template class ERI3C<double>;
extern template class ERI3C<float>;
extern template class ERI4C<double>;
extern template class ERI4C<float>;

} // namespace property_types

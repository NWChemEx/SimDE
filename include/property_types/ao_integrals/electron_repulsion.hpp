#pragma once
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/n_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals {

/**
 * @brief The property type for modules that build tensors filled with electron
 * repulsion integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(ERI, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ERI, BaseType) {
    return sde::declare_input();
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ERI, BaseType) {
    using element_type = double; // TODO get from TMP
    using tensor_type  = type::tensor<element_type>;

    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<BaseType>("r_12"));
}

template<typename ElementType>
using ERI2C = ERI<TwoCenter<ElementType>>;

template<typename ElementType>
using ERI3C = ERI<ThreeCenter<ElementType>>;

template<typename ElementType>
using ERI4C = ERI<FourCenter<ElementType>>;

extern template class ERI<TwoCenter<double>>;
extern template class ERI<TwoCenter<float>>;
extern template class ERI<ThreeCenter<double>>;
extern template class ERI<ThreeCenter<float>>;
extern template class ERI<FourCenter<double>>;
extern template class ERI<FourCenter<float>>;

} // namespace property_types::ao_integrals

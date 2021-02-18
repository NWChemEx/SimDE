#pragma once
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include
namespace property_types::ao_integrals {

/** @brief This is the property type for the quantity usually denoted as
 *         @f$f_{12}(\vec{r}_{12})@f$ in f12 theory.
 */
template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(CorrelationFactor, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(CorrelationFactor, BaseType) {
    return sde::declare_input();
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(CorrelationFactor, BaseType) {
    using element_type = double;
    using tensor_type  = type::tensor<element_type>;
    using my_type      = CorrelationFactor<BaseType>;

    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<my_type>("f_12(r_12)"));
}

} // namespace property_types::ao_integrals
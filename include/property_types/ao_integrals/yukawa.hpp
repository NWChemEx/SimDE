#pragma once
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/four_center.hpp"
#include "property_types/ao_integrals/three_center.hpp"
#include "property_types/ao_integrals/two_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals {

/**
 * @brief The property type for modules that build tensors filled with
 * Yukawa (STG times Coulomb) integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(Yukawa, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Yukawa, BaseType) {
    using stg_exponent_t = double;

    return sde::declare_input().add_field<stg_exponent_t>("STG Exponent");
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Yukawa, BaseType) {
    using element_type = double;
    using tensor_type  = type::tensor<element_type>;
    using my_type      = Yukawa<BaseType>;

    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<my_type>("exp(-ar_12)/r_12"));
}

template<typename ElementType>
using Yukawa2C = Yukawa<TwoCenter<ElementType>>;

template<typename ElementType>
using Yukawa3C = Yukawa<ThreeCenter<ElementType>>;

template<typename ElementType>
using Yukawa4C = Yukawa<FourCenter<ElementType>>;

extern template class Yukawa<TwoCenter<double>>;
extern template class Yukawa<TwoCenter<float>>;
extern template class Yukawa<ThreeCenter<double>>;
extern template class Yukawa<ThreeCenter<float>>;
extern template class Yukawa<FourCenter<double>>;
extern template class Yukawa<FourCenter<float>>;

} // namespace property_types::ao_integrals

#pragma once
#include "property_types/ao_integrals/detail_/macros.hpp"
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/type_traits.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals::f12 {

/** @brief Property type for the F12 quantity ususally denoted as:
 *         @f$\frac{f_{12}(r_{12})}{r_{12}}@f$.
 *
 *  The name of this property type comes from the fact that it is very common to
 *  label the tensor of ERIS as @f$G@f$ and in the F12 literature the tensor
 *  containing the correlation factor is typically labeled @f$R@f$. Physically
 *  it represents the interaction of the geminal with a pair of orbitals.
 */
template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(GR, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(GR, BaseType) {
    return sde::declare_input();
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(GR, BaseType) {
    using element_type = element_t<BaseType>;
    using tensor_type  = type::tensor<element_type>;
    using my_type      = GR<BaseType>;

    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<my_type>("f_12(r_12)/r_12"));
}

MULTICENTER_AO_INTEGRAL_TYPEDEFS(GR);
MULTICENTER_AO_INTEGRAL_EXTERNS(GR);

} // namespace property_types::ao_integrals::f12
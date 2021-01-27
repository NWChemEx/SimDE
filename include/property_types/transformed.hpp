#pragma once
#include "property_types/ao_integrals/type_traits.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(Transformed, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Transformed, BaseType) {
    using orb_space_t = const type::orbital_space_t<double>&;

    if constexpr(ao_integrals::n_centers_v<BaseType> == 2) {
        return sde::declare_input()
          .add_field<orb_space_t>("final bra")
          .template add_field<orb_space_t>("final ket");
    } else if constexpr(ao_integrals::n_centers_v<BaseType> == 3) {
        return sde::declare_input()
          .add_field<orb_space_t>("final bra")
          .template add_field<orb_space_t>("final ket 1")
          .template add_field<orb_space_t>("final ket 2");
    } else if constexpr(ao_integrals::n_centers_v<BaseType> == 4) {
        return sde::declare_input()
          .add_field<orb_space_t>("final bra 1")
          .template add_field<orb_space_t>("final bra 2")
          .template add_field<orb_space_t>("final ket 1")
          .template add_field<orb_space_t>("final ket 2");
    } else {
        static_assert(
          ao_integrals::n_centers_v<BaseType>, // Will be false if we get here
          "Type does not inherit from TwoCenter, ThreeCenter, or FourCenter");
    }
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Transformed, BaseType) {
    return sde::declare_result();
}

} // namespace property_types
#pragma once
#include "property_types/ao_integrals/four_center.hpp"
#include "property_types/ao_integrals/three_center.hpp"
#include "property_types/ao_integrals/two_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {
namespace detail_ {

/// Stolen from https://stackoverflow.com/a/25958302
template<typename T, typename Tuple>
struct has_type;

template<typename T>
struct has_type<T, std::tuple<>> : std::false_type {};

template<typename T, typename U, typename... Ts>
struct has_type<T, std::tuple<U, Ts...>> : has_type<T, std::tuple<Ts...>> {};

template<typename T, typename... Ts>
struct has_type<T, std::tuple<T, Ts...>> : std::true_type {};

template<typename T, typename Tuple>
static constexpr bool has_type_v = has_type<T, Tuple>::value;

template<typename T>
static constexpr bool is_2c_v =
  has_type_v<ao_integrals::TwoCenter<double>, typename T::bases_t> ||
  has_type_v<ao_integrals::TwoCenter<float>, typename T::bases_t>;

template<typename T>
static constexpr bool is_3c_v =
  has_type_v<ao_integrals::ThreeCenter<double>, typename T::bases_t> ||
  has_type_v<ao_integrals::ThreeCenter<float>, typename T::bases_t>;

template<typename T>
static constexpr bool is_4c_v =
  has_type_v<ao_integrals::FourCenter<double>, typename T::bases_t> ||
  has_type_v<ao_integrals::FourCenter<float>, typename T::bases_t>;

} // namespace detail_

template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(Transformed, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Transformed, BaseType) {
    using orb_space_t = const type::orbital_space_t<double>&;

    if constexpr(detail_::is_2c_v<BaseType>) {
        return sde::declare_input()
          .add_field<orb_space_t>("final bra")
          .template add_field<orb_space_t>("final ket");
    } else if constexpr(detail_::is_3c_v<BaseType>) {
        return sde::declare_input()
          .add_field<orb_space_t>("final bra")
          .template add_field<orb_space_t>("final ket 1")
          .template add_field<orb_space_t>("final ket 2");
    } else if constexpr(detail_::is_4c_v<BaseType>) {
        return sde::declare_input()
          .add_field<orb_space_t>("final bra 1")
          .template add_field<orb_space_t>("final bra 2")
          .template add_field<orb_space_t>("final ket 1")
          .template add_field<orb_space_t>("final ket 2");
    } else {
        static_assert(
          detail_::is_2c_v<BaseType>, // Will be false if we get here
          "Type does not inherit from TwoCenter, ThreeCenter, or FourCenter");
    }
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Transformed, BaseType) {
    return sde::declare_result();
}

} // namespace property_types
#pragma once
#include "property_types/ao_integrals/ao_integrals_fwd.hpp"
#include "property_types/ao_integrals/four_center.hpp"
#include "property_types/ao_integrals/three_center.hpp"
#include "property_types/ao_integrals/two_center.hpp"
#include <tuple>

namespace property_types::ao_integrals {
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

/// Used to determine if the type @p T appears in the tuple of type @p Tuple
template<typename T, typename Tuple>
static constexpr bool has_type_v = has_type<T, Tuple>::value;

/** @brief Primary template for determining if a type is for a two-center
 *         integral.
 *
 *  The primary template takes care of the scenario where the type derives from
 *  `TwoCenter`. The type contains a static member `value` which is true if @T
 *  is a property type that derives from `TwoCenter` and false otherwise.
 *
 *  @tparam T The property type we are inspecting. Assumed to be the type of a
 *            valid property type.
 */
template<typename T>
struct IsTwoCentered {
    static constexpr bool value =
      has_type_v<ao_integrals::TwoCenter<float>, typename T::bases_t> ||
      has_type_v<ao_integrals::TwoCenter<double>, typename T::bases_t>;
};

template<typename T>
struct IsTwoCentered<ao_integrals::DOI<T>> : std::false_type {};

/** @brief Specialization of IsTwoCentered to register the base `TwoCenter`
 *         property type as being two centered.
 *
 *  This specialization is only in play when we are inquiring about the
 *  `TwoCenter` property type directly. When instantiated this type will contain
 *  a static member `value` which is set to true.
 *
 *  @tparam T The scalar type used in the integrals.
 */
template<typename T>
struct IsTwoCentered<ao_integrals::TwoCenter<T>> : std::true_type {};

/** @brief Primary template for determining if a type is for a three-center
 *         integral.
 *
 *  The primary template takes care of the scenario where the type derives from
 *  `ThreeCenter`. The type contains a static member `value` which is true if @T
 *  is a property type that derives from `ThreeCenter` and false otherwise.
 *
 *  @tparam T The property type we are inspecting. Assumed to be the type of a
 *            valid property type.
 */
template<typename T>
struct IsThreeCentered {
    static constexpr bool value =
      has_type_v<ao_integrals::ThreeCenter<float>, typename T::bases_t> ||
      has_type_v<ao_integrals::ThreeCenter<double>, typename T::bases_t>;
};

/** @brief Specialization of IsThreeCentered to register the base `ThreeCenter`
 *         property type as being three centered.
 *
 *  This specialization is only in play when we are inquiring about the
 *  `ThreeCenter` property type directly. When instantiated this type will
 *  contain a static member `value` which is set to true.
 *
 *  @tparam T The scalar type used in the integrals.
 */
template<typename T>
struct IsThreeCentered<ao_integrals::ThreeCenter<T>> : std::true_type {};

/** @brief Primary template for determining if a type is for a four-center
 *         integral.
 *
 *  The primary template takes care of the scenario where the type derives from
 *  `FourCenter`. The type contains a static member `value` which is true if @T
 *  is a property type that derives from `FourCenter` and false otherwise.
 *
 *  @tparam T The property type we are inspecting. Assumed to be the type of a
 *            valid property type.
 */
template<typename T>
struct IsFourCentered {
    static constexpr bool value =
      has_type_v<ao_integrals::FourCenter<float>, typename T::bases_t> ||
      has_type_v<ao_integrals::FourCenter<double>, typename T::bases_t>;
};

template<typename T>
struct IsFourCentered<ao_integrals::DOI<T>> : std::true_type {};

/** @brief Specialization of IsFourCentered to register the base `FourCenter`
 *         property type as being four centered.
 *
 *  This specialization is only in play when we are inquiring about the
 *  `FourCenter` property type directly. When instantiated this type will
 *  contain a static member `value` which is set to true.
 *
 *  @tparam T The scalar type used in the integrals.
 */
template<typename T>
struct IsFourCentered<ao_integrals::FourCenter<T>> : std::true_type {};

/** @brief Convenience function for determining how many centers an integral
 *         involves.
 *
 *  This `constexpr` determines how many centers an integral has based on the
 *  type. It relies on `IsXCentered` type traits working correctly (`X` being
 *  `Two`, `Three`, or `Four`).
 *
 *  @tparam T The type we are inspecting. Assumed to be a valid property type
 *            for which one of `IsTwoCentered`, `IsThreeCentered`, or
 *            `IsFourCentered` is true. If none are true this function will not
 *            compile.
 *
 *  @return The number of centers in the integral.
 */
template<typename T>
constexpr auto n_centers() {
    if constexpr(IsTwoCentered<T>::value) {
        return 2;
    } else if constexpr(IsThreeCentered<T>::value) {
        return 3;
    } else if constexpr(IsFourCentered<T>::value) {
        return 4;
    } else {
        static_assert(
          IsFourCentered<T>::value,
          "Does not derive from TwoCentered, ThreeCentered, or FourCentered");
    }
}

} // namespace detail_

/** @brief User API for determining how many centers an integral involves.
 *
 *  The global variable `n_centers_v<T>` is set to the number of centers that
 *  `T` invovles.
 *
 *  @tparam T The property type we are inspecting. Assumed to be the property
 *            type of an integral.
 */
template<typename T>
static constexpr auto n_centers_v = detail_::n_centers<T>();

} // namespace property_types::ao_integrals
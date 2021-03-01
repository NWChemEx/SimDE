#pragma once
#include "property_types/ao_integrals/ao_integrals_fwd.hpp"
#include "property_types/ao_integrals/detail_/type_traits.hpp"

#include <tuple>

namespace property_types::ao_integrals {

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
 *  The primary template takes care of the scenario where the type derives
 * from `TwoCenter`. The type contains a static member `value` which is true
 * if @T is a property type that derives from `TwoCenter` and false otherwise.
 *
 *  @tparam T The property type we are inspecting. Assumed to be the type of a
 *            valid property type.
 */
template<typename T>
struct IsTwoCentered {
    static constexpr bool value =
      has_type_v<ao_integrals::NCenter<2, float>, typename T::bases_t> ||
      has_type_v<ao_integrals::NCenter<2, double>, typename T::bases_t>;
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
struct IsTwoCentered<ao_integrals::NCenter<2, T>> : std::true_type {};

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
      has_type_v<ao_integrals::NCenter<3, float>, typename T::bases_t> ||
      has_type_v<ao_integrals::NCenter<3, double>, typename T::bases_t>;
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
struct IsThreeCentered<ao_integrals::NCenter<3, T>> : std::true_type {};

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
      has_type_v<ao_integrals::NCenter<4, float>, typename T::bases_t> ||
      has_type_v<ao_integrals::NCenter<4, double>, typename T::bases_t>;
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
struct IsFourCentered<ao_integrals::NCenter<4, T>> : std::true_type {};

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
        // If we get here we know v will be false
        constexpr bool v = IsFourCentered<T>::value;
        static_assert(v, "Does not derive from NCenters<N,T>");
    }
}

/** @brief Struct used to determine if a type is that of the differential
           overlap integral's property type.
 *
 *  The primary template is instantiated for all @p T which aren't a
 *  specialization of `ao_integrals::DOI`. When instantiated the class will have
 *  a static constexpr member `value` which be set to false.
 *
 *  @tparam T The type we are inspecting.
 */
template<typename T>
struct IsDOI : std::false_type {};

/** @brief Struct used to determine if a type is that of the differential
 *         overlap integral's property type.
 *
 *  This specialization is instantiated when @p T is a specialization of
 *  `ao_integrals::DOI`. When instantiated this specialization will have a
 *  static constexpr member `value` which is set to true.
 *
 *  @tparam T The scalar type of the integral values.
 */
template<typename T>
struct IsDOI<property_types::ao_integrals::DOI<T>> : std::true_type {};

/** @brief Struct used to determine if a type is that of the electron-nuclear
 *         attraction property type.
 *
 *  The primary template is instantiated for all @p T which aren't a
 *  specialization of `ao_integrals::Nuclear`. When instantiated the class will
 *  have a static constexpr member `value` which be set to false.
 *
 *  @tparam T The type we are inspecting.
 */
template<typename T>
struct IsNuclear : std::false_type {};

/** @brief Struct used to determine if a type is that of the nuclear-electron
 *         attraction integral's property type.
 *
 *  This specialization is instantiated when @p T is a specialization of
 *  `ao_integrals::Nuclear`. When instantiated this specialization will have a
 *  static constexpr member `value` which is set to true.
 *
 *  @tparam T The scalar type of the integral values.
 */
template<typename T>
struct IsNuclear<property_types::ao_integrals::Nuclear<T>> : std::true_type {};

/** @brief Struct used to determine if a type is that of a Slater-type geminal's
           property type.
 *
 *  The primary template is instantiated for all @p T which aren't a
 *  specialization of `ao_integrals::STG`. When instantiated the class will have
 *  a static constexpr member `value` which be set to false.
 *
 *  @tparam T The type we are inspecting.
 */
template<typename T>
struct IsSTG : std::false_type {};

/** @brief Struct used to determine if a type is that of the Slater-type geminal
 *         integral's property type.
 *
 *  This specialization is instantiated when @p T is a specialization of
 *  `ao_integrals::STG`. When instantiated this specialization will have a
 *  static constexpr member `value` which is set to true.
 *
 *  @tparam T The scalar type of the integral values.
 */
template<typename T>
struct IsSTG<property_types::ao_integrals::STG<T>> : std::true_type {};

/** @brief Struct used to determine if a type is that of the Yukawa integral's
 *         property type.
 *
 *  The primary template is instantiated for all @p T which aren't a
 *  specialization of `ao_integrals::Yukawa`. When instantiated the class will
 *  have a static constexpr member `value` which be set to false.
 *
 *  @tparam T The type we are inspecting.
 */
template<typename T>
struct IsYukawa : std::false_type {};

/** @brief Struct used to determine if a type is that of the Yukawa integral's
 *         property type.
 *
 *  This type trait is the type that property type @p T uses for each AO
 *  integral.
 *
 *  @param T The property type to inspect.
 */
template<typename T>
using element_t =
  std::conditional_t<detail_::HasDoubleElements<T>::value, double, float>;

// template<typename T>
// using element_t = typename detail_::GetElementType<T>::type;

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

/** @brief User API for determining if a type is the property type for the
 *         differential overlap integral.
 *
 *  If @p T is the same type as the differential overlap integral's property
 *  type this global variable will be set to true, otherwise it will be set to
 *  false.
 *
 *  @param T The type we are inspecting.
 */
template<typename T>
static constexpr auto is_doi_v = detail_::IsDOI<T>::value;

/** @brief User API for determining if a type is the property type for the
 *         nuclear-electron attraction integral.
 *
 *  If @p T is the same type as the nuclear-electron attraction integral's
 *  property type this global variable will be set to true, otherwise it will be
 *  set to false.
 *
 *  @param T The type we are inspecting.
 */
template<typename T>
static constexpr auto is_nuclear_v = detail_::IsNuclear<T>::value;

/** @brief User API for determining if a type is the property type for a Slater-
 *         type geminal integral.
 *
 *  If @p T is the same type as the Slater-type geminal integral's property
 *  type this global variable will be set to true, otherwise it will be set to
 *  false.
 *
 *  @param T The type we are inspecting.
 */
template<typename T>
static constexpr auto is_stg_v = detail_::IsSTG<T>::value;

/** @brief User API for determining if a type is the property type for the
 *         Yukawa integral.
 *
 *  If @p T is the same type as the Yukawa integral's property type this global
 *  variable will be set to true, otherwise it will be set to false.
 *
 *  @param T The type we are inspecting.
 */
template<typename T>
static constexpr auto is_yukawa_v = detail_::IsYukawa<T>::value;

} // namespace property_types::ao_integrals
#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief API for modules that compute localized orbitals
 *
 *  This property type is envisioned as being the property type for any module
 *  that computes localized orbitals. This accounts for conventional localized
 *  molecular orbitals, as well as things like pair-natural orbitals.
 *
 *  @tparam ElementType The type of elements in the tensors
 */
template<typename ElementType = double>
struct LocalizedOrbitals : public sde::PropertyType<LocalizedOrbitals<ElementType>> {
    /// Type of orbitals expected by this module, accounting for @p ElementType
    using orbital_type = type::orbitals<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class LocalizedOrbitals

//-------------------------------Implementations--------------------------------

template<typename ElementType>
auto LocalizedOrbitals<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const orbital_type&>("Orbitals");
    rv["Molecule"].set_description(
      "Molecular system to localize the orbitals of");
    rv["Orbitals"].set_description("The orbitals to localize");
    return rv;
}

template<typename ElementType>
auto LocalizedOrbitals<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<orbital_type>("Local Orbitals");
    rv["Local Orbitals"].set_description("The localized orbitals");
    return rv;
}

extern template class LocalizedOrbitals<double>;
extern template class LocalizedOrbitals<float>;

} // namespace property_types

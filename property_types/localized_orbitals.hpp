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
 *  @tparam InputOrbitals The type of the input orbitals
 *  @tparam OutputOrbitals the type iof the output orbitals
 */
template<typename InputOrbitals = type::orbitals<double>, typename OutputOrbitals = InputOrbitals>
struct LocalizedOrbitals : public sde::PropertyType<LocalizedOrbitals<InputOrbitals, OutputOrbitals>> {
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class LocalizedOrbitals

//-------------------------------Implementations--------------------------------

template<typename InputOrbitals, typename OutputOrbitals>
auto LocalizedOrbitals<InputOrbitals, OutputOrbitals>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const InputOrbitals&>("Orbitals");
    rv["Molecule"].set_description(
      "Molecular system to localize the orbitals of");
    rv["Orbitals"].set_description("The orbitals to localize");
    return rv;
}

template<typename InputOrbitals, typename OutputOrbitals>
auto LocalizedOrbitals<InputOrbitals, OutputOrbitals>::results_() {
    auto rv = sde::declare_result().add_field<OutputOrbitals>("Local Orbitals");
    rv["Local Orbitals"].set_description("The localized orbitals");
    return rv;
}

extern template class LocalizedOrbitals<type::orbitals<double>>;
extern template class LocalizedOrbitals<type::orthogonal_orbs<double>>;
extern template class LocalizedOrbitals<type::canonical_mos<double>>;
extern template class LocalizedOrbitals<type::orbitals<float>>;
extern template class LocalizedOrbitals<type::orthogonal_orbs<float>>;
extern template class LocalizedOrbitals<type::canonical_mos<float>>;

} // namespace property_types

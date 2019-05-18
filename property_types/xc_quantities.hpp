#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that that build XC related quantities
 * (EXC, VXC, etc) in the AO basis set.
 *
 *  @tparam ElementType the type of the elements in the tensors
 */
template<typename ElementType = double>
struct XCQuantities : sde::PropertyType<XCQuantities<ElementType>> {
    /// The type of the new MOs, accounting for ElementType
    using orbital_type = type::orbitals<ElementType>;
    /// The type of the tensors representing the MOs, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class XCQuantities

//-------------------------------Implementations--------------------------------
template<typename ElementType>
auto XCQuantities<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const orbital_type&>("Molecular Orbitals")
                .template add_field<const type::basis_set&>("Bra")
                .template add_field<const type::basis_set&>("Ket")
                .template add_field<type::size>("Derivative");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    rv["Bra"].set_description("The basis set used for the bra");
    rv["Ket"].set_description("The basis set used for the ket");
    rv["Derivative"].set_description("The derivative order to compute");
    return rv;
}

template<typename ElementType>
auto XCQuantities<ElementType>::results_() {
    auto rv = sde::declare_result()
                .add_field<tensor_type>("VXC Matrix")
                .template add_field<tensor_type>("EXC Energy")
                .template add_field<tensor_type>("xEXX");
    rv["VXC Matrix"].set_description("The computed VXC Matrix");
    rv["EXC Energy"].set_description("The computed EXC Energy");
    rv["xEXX"]      .set_description("Scaled HF Exchange Contribution");
    return rv;
}

} // namespace property_types

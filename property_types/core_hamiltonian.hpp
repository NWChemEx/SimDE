#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build the core Hamiltonian in the
 *        AO basis set.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 */
template<typename ElementType = double>
struct CoreHamiltonian : SDE::PropertyType<CoreHamiltonian<ElementType>> {
    ///The type of the returned tensor, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    ///Generates the input fields required by this property type
    auto inputs_();
    ///Generates the result fields required by this property type
    auto results_();
}; // class CoreHamiltonian

//---------------------------Implementations------------------------------------
template<typename ElementType>
auto CoreHamiltonian<ElementType>::inputs_() {
    auto rv = SDE::declare_input()
      .add_field<const type::molecule&>("Molecule")
      .add_field<const type::basis_set&>("Bra")
      .add_field<const type::basis_set&>("Ket")
      .add_field<type::size>("Derivative");
    rv["Molecule"].set_description("The molecular system");
    rv["Bra"].set_description("The basis set for the bra");
    rv["Ket"].set_description("The basis set for the ket");
    rv["Derivative"].set_description("The derivative order");
    return rv;
}

template<typename ElementType>
auto CoreHamiltonian<ElementType>::results_() {
    auto rv = SDE::declare_result().add_field<tensor_type>("Core Hamiltonian");
    rv["Core Hamiltonian"].set_description("The computed Core Hamiltonian");
    return rv;
}

} // namespace property_types

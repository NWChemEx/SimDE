#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build the core Hamiltonian in the
 *        AO basis set.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 */
template<typename ElementType = double>
struct CoreHamiltonian
  : public sde::PropertyType<CoreHamiltonian<ElementType>> {
    /// The type of the returned tensor, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class CoreHamiltonian

//---------------------------Implementations------------------------------------
template<typename ElementType>
auto CoreHamiltonian<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set<ElementType>&>("Bra")
                .template add_field<const type::basis_set<ElementType>&>("Ket")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Molecule"].set_description("The molecular system");
    rv["Bra"].set_description("The basis set for the bra");
    rv["Ket"].set_description("The basis set for the ket");
    rv["Derivative"].set_description("The derivative order");
    return rv;
}

template<typename ElementType>
auto CoreHamiltonian<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("Core Hamiltonian");
    rv["Core Hamiltonian"].set_description("The computed Core Hamiltonian");
    return rv;
}

extern template class CoreHamiltonian<double>;
extern template class CoreHamiltonian<float>;

} // namespace property_types

#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/** @brief The property type for modules that compute energies and energy
 *         derivatives of molecular systems.
 *
 *  Arguably one of the most important quantities in electronic structure theory
 *  is the energy of the system. Modules that are capable of computing the
 *  energy of a molecular system satisfy the Energy property type.
 *
 *  @tparam ElementType The type of the elements in the tensors.
 */
template<typename ElementType = double>
struct Energy : public SDE::PropertyType<Energy<ElementType>> {
    ///The type of the energy derivative, accounting for ElementType
    using tensor_type   = type::tensor<ElementType>;
    ///Generates the input fields required by this property type
    auto inputs_();
    ///Generates the result fields required by this property type
    auto results_();
}; // class Energy

//-------------------------------Implementations--------------------------------
template<typename ElementType>
auto Energy<ElementType>::inputs_() {
    auto rv = SDE::declare_input()
      .add_field<const type::molecule&>("Molecule")
      .add_field<type::size>("Derivative");
    rv["Molecule"].set_description("The molecular system");
    rv["Derivative"].set_description("The derivative order of the energy");
    return rv;
}

template<typename ElementType>
auto Energy<ElementType>::results_() {
    auto rv = SDE::declare_result().add_field<tensor_type>("Energy");
    rv["Energy"].set_description("The computed energy or derivatives");
    return rv;
}

} //namespace property_types
#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build the density-fitting coefficients
 *        for computing the J and K matrices using 3C ERIs.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 */
template<typename ElementType = double>
struct DFCoefficients : sde::PropertyType<DFCoefficients<ElementType>> {
    /// The type of the returned tensor, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class DFCoefficients

//---------------------------Implementations------------------------------------
template<typename ElementType>
auto DFCoefficients<ElementType>::inputs_() {
    auto rv = sde::declare_input()
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
auto DFCoefficients<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("DF Coefficients");
    rv["DF Coefficients"].set_description("The computed DF coefficients");
    return rv;
}

extern template class DFCoefficients<double>;
extern template class DFCoefficients<float>;

} // namespace property_types

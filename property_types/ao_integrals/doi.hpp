#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with
 * differential overlap integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename ElementType = double>
struct DOI : public sde::PropertyType<DOI<ElementType>> {
    /// The type of an std::array of basis sets
    using basis_type = type::basis_set<ElementType>;
    /// The type of a tensor accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class DOI

//------------------------Implementations---------------------------------------

template<typename ElementType>
auto DOI<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Bra"].set_description("The basis set for the bra");
    rv["Ket"].set_description("The basis set for the ket");
    rv["Derivative"].set_description(
      "The derivative order of differential overlap integrals to be computed");
    return rv;
}

template<typename ElementType>
auto DOI<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("DOIs");
    rv["DOIs"].set_description("The requested differential overlap integrals");
    return rv;
}

extern template class DOI<double>;
extern template class DOI<float>;

} // namespace property_types

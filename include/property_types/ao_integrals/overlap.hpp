#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with overlap
 * integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename ElementType = double>
struct OverlapIntegral
  : public sde::PropertyType<OverlapIntegral<ElementType>> {
    /// The type of an std::array of basis sets
    using basis_type = type::ao_space_t<ElementType>;
    /// The type of a tensor accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class OverlapIntegral

//------------------------Implementations---------------------------------------

template<typename ElementType>
auto OverlapIntegral<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Bra"].set_description("The basis set for the bra");
    rv["Ket"].set_description("The basis set for the ket");
    rv["Derivative"].set_description(
      "The derivative order of overlap integrals to be computed");
    return rv;
}

template<typename ElementType>
auto OverlapIntegral<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("Overlap Integrals");
    rv["Overlap Integrals"].set_description("The requested overlap integrals");
    return rv;
}

extern template class OverlapIntegral<double>;
extern template class OverlapIntegral<float>;

} // namespace property_types

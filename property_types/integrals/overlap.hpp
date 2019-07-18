#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types::integrals {

/** @brief Computes the overlap between two basis sets.
 *
 *  This property type is for modules that can compute the overlap between two
 *  AO basis sets. These integrals are of the form
 *  @f$\left\langle\mu\middle\mid\nu\right\rangle@f$.
 *
 *  @tparam ElementType Type of the elements in the returned tensor.
 */
template<typename ElementType = double>
struct Overlap : sde::PropertyType<Overlap<ElementType>> {
    auto inputs_();
    auto results_();
};

//-------------------------Implementations--------------------------------------

template<typename ElementType>
auto Overlap<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set&>("Bra")
                .add_field<const type::basis_set&>("Ket")
                .add_field<type::size>("Derivative");

    rv["Molecule"].set_description("The molecular system");
    rv["Bra"].set_description("The basis set used for the bra");
    rv["Ket"].set_description("The basis set used for the ket");
    rv["Derivative"].set_description("The derivative order");
    return rv;
}

template<typename ElementType>
auto Overlap<ElementType>::results_() {
    using tensor_type = tamm::Tensor<ElementType>;
    auto rv = sde::declare_result().add_field<tensor_type>("overlap matrix");
    rv["overlap matrix"].set_description("The overlap matrix in the AO basis");
    return rv;
}

extern template class Overlap<double>;

} // namespace property_types::integrals

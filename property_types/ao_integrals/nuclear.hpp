#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with electron nuclear
 * repulsion integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
    template<typename ElementType = double>
    struct NuclearIntegral : public sde::PropertyType<NuclearIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class NuclearIntegral

//------------------------Implementations---------------------------------------

    template<typename ElementType>
    auto NuclearIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket")
                .template add_field<type::size>("Derivative");
        rv["Molecule"].set_description(
                "The molecule for which the electron nuclear repulsion integrals are computed");
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket"].set_description("The basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto NuclearIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("Nuclear Integrals");
        rv["Nuclear Integrals"].set_description("The requested electron nuclear repulsion integrals");
        return rv;
    }

    extern template class NuclearIntegral<double>;
    extern template class NuclearIntegral<float>;

} // namespace property_types


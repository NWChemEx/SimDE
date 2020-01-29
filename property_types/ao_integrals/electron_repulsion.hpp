#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with electron repulsion
 * integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
    template<typename ElementType = double>
    struct ERI2CIntegral : public sde::PropertyType<ERI2CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class ERI2CIntegral

    template<typename ElementType = double>
    struct ERI3CIntegral : public sde::PropertyType<ERI3CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class ERI3CIntegral

    template<typename ElementType = double>
    struct ERI4CIntegral : public sde::PropertyType<ERI4CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class ERI4CIntegral

//------------------------Implementations---------------------------------------

    template<typename ElementType>
    auto ERI2CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket")
                .template add_field<type::size>("Derivative");
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket"].set_description("The basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of electron repulsion integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto ERI2CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("ERIs");
        rv["ERIs"].set_description("The requested electron repulsion integrals");
        return rv;
    }

    template<typename ElementType>
    auto ERI3CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket1")
                .template add_field<const basis_type&>("Ket2")
                .template add_field<type::size>("Derivative");
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket1"].set_description("The first basis set for the ket");
        rv["Ket2"].set_description("The second basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of electron repulsion integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto ERI3CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("ERIs");
        rv["ERIs"].set_description("The requested electron repulsion integrals");
        return rv;
    }

    template<typename ElementType>
    auto ERI4CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra1")
                .template add_field<const basis_type&>("Bra2")
                .template add_field<const basis_type&>("Ket1")
                .template add_field<const basis_type&>("Ket2")
                .template add_field<type::size>("Derivative");
        rv["Bra1"].set_description("The first basis set for the bra");
        rv["Bra2"].set_description("The second basis set for the bra");
        rv["Ket1"].set_description("The first basis set for the ket");
        rv["Ket2"].set_description("The second basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of electron repulsion integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto ERI4CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("ERIs");
        rv["ERIs"].set_description("The requested electron repulsion integrals");
        return rv;
    }

    extern template class ERI2CIntegral<double>;
    extern template class ERI2CIntegral<float>;
    extern template class ERI3CIntegral<double>;
    extern template class ERI3CIntegral<float>;
    extern template class ERI4CIntegral<double>;
    extern template class ERI4CIntegral<float>;

} // namespace property_types


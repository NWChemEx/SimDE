#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with Slater-type geminal
 * integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
    template<typename ElementType = double>
    struct STG2CIntegral : public sde::PropertyType<STG2CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class STG2CIntegral

    template<typename ElementType = double>
    struct STG3CIntegral : public sde::PropertyType<STG3CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class STG3CIntegral

    template<typename ElementType = double>
    struct STG4CIntegral : public sde::PropertyType<STG4CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class STG4CIntegral

//------------------------Implementations---------------------------------------

    template<typename ElementType>
    auto STG2CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket")
                .template add_field<type::size>("Derivative");
        rv["Molecule"].set_description(
                "The molecule for which the integrals are computed");
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket"].set_description("The basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto STG2CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("STG Integrals");
        rv["STG Integrals"].set_description("The requested STG integrals");
        return rv;
    }

    template<typename ElementType>
    auto STG3CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket1")
                .template add_field<const basis_type&>("Ket2")
                .template add_field<type::size>("Derivative");
        rv["Molecule"].set_description(
                "The molecule for which the integrals are computed");
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket1"].set_description("The first basis set for the ket");
        rv["Ket2"].set_description("The second basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto STG3CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("STG Integrals");
        rv["STG Integrals"].set_description("The requested STG integrals");
        return rv;
    }

    template<typename ElementType>
    auto STG4CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const basis_type&>("Bra1")
                .template add_field<const basis_type&>("Bra2")
                .template add_field<const basis_type&>("Ket1")
                .template add_field<const basis_type&>("Ket2")
                .template add_field<type::size>("Derivative");
        rv["Molecule"].set_description(
                "The molecule for which the integrals are computed");
        rv["Bra1"].set_description("The first basis set for the bra");
        rv["Bra2"].set_description("The second basis set for the bra");
        rv["Ket1"].set_description("The first basis set for the ket");
        rv["Ket2"].set_description("The second basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        return rv;
    }

    template<typename ElementType>
    auto STG4CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("STG Integrals");
        rv["STG Integrals"].set_description("The requested STG integrals");
        return rv;
    }

    extern template class STG2CIntegral<double>;
    extern template class STG2CIntegral<float>;
    extern template class STG3CIntegral<double>;
    extern template class STG3CIntegral<float>;
    extern template class STG4CIntegral<double>;
    extern template class STG4CIntegral<float>;

} // namespace property_types


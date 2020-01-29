#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with 
 * Yukawa (STG times Coulomb) integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
    template<typename ElementType = double>
    struct Yukawa2CIntegral : public sde::PropertyType<Yukawa2CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class Yukawa2CIntegral

    template<typename ElementType = double>
    struct Yukawa3CIntegral : public sde::PropertyType<Yukawa3CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class Yukawa3CIntegral

    template<typename ElementType = double>
    struct Yukawa4CIntegral : public sde::PropertyType<Yukawa4CIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class Yukawa4CIntegral

//------------------------Implementations---------------------------------------

    template<typename ElementType>
    auto Yukawa2CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket")
                .template add_field<type::size>("Derivative")
                .template add_field<ElementType>("STG Exponent",ElementType{1.0});
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket"].set_description("The basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        rv["STG Exponent"].set_description("The exponent for the Slate type geminal");
        return rv;
    }

    template<typename ElementType>
    auto Yukawa2CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("Yukawa Integrals");
        rv["Yukawa Integrals"].set_description("The requested Yukawa integrals");
        return rv;
    }

    template<typename ElementType>
    auto Yukawa3CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra")
                .template add_field<const basis_type&>("Ket1")
                .template add_field<const basis_type&>("Ket2")
                .template add_field<type::size>("Derivative")
                .template add_field<ElementType>("STG Exponent",ElementType{1.0});
        rv["Bra"].set_description("The basis set for the bra");
        rv["Ket1"].set_description("The first basis set for the ket");
        rv["Ket2"].set_description("The second basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        rv["STG Exponent"].set_description("The exponent for the Slate type geminal");
        return rv;
    }

    template<typename ElementType>
    auto Yukawa3CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("Yukawa Integrals");
        rv["Yukawa Integrals"].set_description("The requested Yukawa integrals");
        return rv;
    }

    template<typename ElementType>
    auto Yukawa4CIntegral<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const basis_type&>("Bra1")
                .template add_field<const basis_type&>("Bra2")
                .template add_field<const basis_type&>("Ket1")
                .template add_field<const basis_type&>("Ket2")
                .template add_field<type::size>("Derivative")
                .template add_field<ElementType>("STG Exponent",ElementType{1.0});
        rv["Bra1"].set_description("The first basis set for the bra");
        rv["Bra2"].set_description("The second basis set for the bra");
        rv["Ket1"].set_description("The first basis set for the ket");
        rv["Ket2"].set_description("The second basis set for the ket");
        rv["Derivative"].set_description(
                "The derivative order of the integrals to be computed");
        rv["STG Exponent"].set_description("The exponent for the Slate type geminal");
        return rv;
    }

    template<typename ElementType>
    auto Yukawa4CIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("Yukawa Integrals");
        rv["Yukawa Integrals"].set_description("The requested Yukawa integrals");
        return rv;
    }

    extern template class Yukawa2CIntegral<double>;
    extern template class Yukawa2CIntegral<float>;
    extern template class Yukawa3CIntegral<double>;
    extern template class Yukawa3CIntegral<float>;
    extern template class Yukawa4CIntegral<double>;
    extern template class Yukawa4CIntegral<float>;

} // namespace property_types


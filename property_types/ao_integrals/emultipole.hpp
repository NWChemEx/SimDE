#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with various
 * electric multipole integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
    template<typename ElementType = double>
    struct EDipoleIntegral : public sde::PropertyType<EDipoleIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class EDipoleIntegral

    template<typename ElementType = double>
    struct EQuadrupoleIntegral : public sde::PropertyType<EQuadrupoleIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class EQuadrupoleIntegral

    template<typename ElementType = double>
    struct EOctopoleIntegral : public sde::PropertyType<EOctopoleIntegral<ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class EOctopoleIntegral

//------------------------Implementations---------------------------------------

    template<typename ElementType>
    auto EDipoleIntegral<ElementType>::inputs_() {
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
    auto EDipoleIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("EDipole Integrals");
        rv["EDipole Integrals"].set_description("The requested electric dipole integrals");
        return rv;
    }

    template<typename ElementType>
    auto EQuadrupoleIntegral<ElementType>::inputs_() {
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
    auto EQuadrupoleIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("EQuadrupole Integrals");
        rv["EQuadrupole Integrals"].set_description("The requested electric quadrupole integrals");
        return rv;
    }

    template<typename ElementType>
    auto EOctopoleIntegral<ElementType>::inputs_() {
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
    auto EOctopoleIntegral<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("EOctopole Integrals");
        rv["EOctopole Integrals"].set_description("The requested electric octopole integrals");
        return rv;
    }

    extern template class EDipoleIntegral<double>;
    extern template class EDipoleIntegral<float>;
    extern template class EQuadrupoleIntegral<double>;
    extern template class EQuadrupoleIntegral<float>;
    extern template class EOctopoleIntegral<double>;
    extern template class EOctopoleIntegral<float>;
} // namespace property_types


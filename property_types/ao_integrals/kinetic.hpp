#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build tensors filled with AO
 * integrals.
 *
 * Most electronic structure methods start by computing some integrals in the
 * AO basis set. Typical examples of such integrals are the kinetic energy of
 * the electrons, the electron-nucleus attraction, and the electron-electron
 * repulsion. From a physical perspective these integrals are very different;
 * however, since these integrals are usually generated from a black-box
 * integral library it tends to be the case that they are created in the same
 * manner. The AOIntegral property type is the property type for modules that
 * wrap calls to these black-box integral libraries.
 *
 * @tparam NBases The total number of AO basis sets involved in the integral.
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
    template<type::size NBases, typename ElementType = double>
    struct AOIntegral : public sde::PropertyType<AOIntegral<NBases, ElementType>> {
        /// The type of an std::array of basis sets
        using basis_type = type::basis_set<ElementType>;
        /// The type of a tensor accounting for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class AOIntegral

//------------------------Implementations---------------------------------------

    template<type::size NBases, typename ElementType>
    auto AOIntegral<NBases, ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const basis_array_type&>("Basis Sets")
                .template add_field<type::size>("Derivative");
        rv["Molecule"].set_description(
                "The molecule for which the AO integrals are computed");
        rv["Basis Sets"].set_description(
                "The basis sets used for the AO integral computation");
        rv["Derivative"].set_description(
                "The derivative order of AO integrals to be computed");
        return rv;
    }

    template<type::size NBases, typename ElementType>
    auto AOIntegral<NBases, ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("AO Integrals");
        rv["AO Integrals"].set_description("The requested AO integrals");
        return rv;
    }

    extern template class KineticIntegral<double>;
    extern template class KineticIntegral<float>;

} // namespace property_types


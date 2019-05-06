#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/**
 * @brief The base class for modules that build tensors filled with AO
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
struct AOIntegral : public SDE::PropertyType<AOIntegral<NBases, element_type>> {
    ///The type of an std::array of basis sets
    using basis_array_type = std::array<type::basis_set, NBases>;
    auto inputs_();
    auto results_();
}; //class AOIntegral

//------------------------Implementations---------------------------------------

template<type::size NBases, typename ElementType>
auto AOIntegral<NBases, ElementType>::inputs_() {
    auto rv = SDE::declare_input()
              .add_field<const type::molecule&>("Molecule")
              .add_field<const basis_array_type&>("Basis Sets")
              .add_field<type::size>("Derivative");
    rv["Molecule"]
    .set_description("The molecule for which the AO integrals are computed");
    rv["Basis Sets"]
    .set_description("The basis sets used for the AO integral computation");
    rv["Derivative"]
    .set_description("The derivative order of AO integrals to be computed");
    return rv;
}

template<type::size NBases, typename ElementType>
auto AOIntegral<NBases, ElementType>::results_() {
    auto rv = SDE::declare_result()
              .add_field<type::tensor<ElementType>>("AO Integrals");
    rv["AO Integrals"].set_description("The requested AO integrals");
    return rv;
}

} //namespace property_types

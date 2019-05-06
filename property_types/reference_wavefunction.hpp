#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/** @brief Property type for modules that compute an initial reference
 *         wavefunction.
 *
 *  Most correlated electronic structure theory methods require an initial
 *  reference wavefunction from which
 *
 */
template<typename ElementType=double>
struct ReferenceWavefunction :
  SDE::PropertyType<ReferenceWavefunction<ElementType>> {
    ///Type of the MOs, accounting for ElementType
    using orbital_type = type::orbitals<ElementType>;
    ///Type of the returned tensor, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    ///Generates the input fields required by this property type
    auto inputs_();
    ///Generates the result fields required by this property type
    auto results_();
}; // class ReferenceWavefunction

//------------------------------Implementations---------------------------------
template<typename ElementType>
auto ReferenceWavefunction<ElementType>::inputs_() {
    auto rv = SDE::declare_input()
      .add_field<const type::molecule&>("Molecule")
      .add_field<const type::basis_set&>("Basis Set")
      .add_field<type::size>("Derivative");
    rv["Molecule"].set_description("The molecular system");
    rv["Basis Set"].set_description("The basis set used for the computation");
    rv["Derivative"].set_description("The derivative order of the energy");
    return rv;
}

template<typename ElementType>
auto ReferenceWavefunction<ElementType>::results_() {
    auto rv = SDE::declare_result()
      .add_field<tensor_type>("Energy")
      .template add_field<orbital_type>("Orbital Space");
    rv["Energy"].set_description("The computed energy or derivatives");
    rv["Orbital Space"].set_description("The reference wavefunction");
    return rv;
}

} //namespace property_types

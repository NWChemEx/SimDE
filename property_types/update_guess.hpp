#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that can update a guess of MOs
 *
 *  @tparam ElementType the type of the elements in the tensors
 */
template<typename ElementType = double>
struct UpdateGuess : public sde::PropertyType<UpdateGuess<ElementType>> {
    /// The type of the new MOs, accounting for ElementType
    using orbital_type = type::orbitals<ElementType>;
    /// Type used to contain various MO subspaces
    using orbital_map = std::map<std::string,orbital_type>;
    /// The type of the tensors representing the MOs, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class UpdateGuess

//-------------------------------Implementations--------------------------------
template<typename ElementType>
auto UpdateGuess<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set<ElementType>&>("Basis Set")
                .template add_field<const tensor_type&>("Fock Matrix");
    rv["Molecule"].set_description("The molecule associated with the density");
    rv["Basis Set"].set_description("The basis set used for the density");
    rv["Fock Matrix"].set_description(
      "The Fock matrix used for the density update");
    return rv;
}

template<typename ElementType>
auto UpdateGuess<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<orbital_map>("Molecular Orbitals");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

extern template class UpdateGuess<double>;
extern template class UpdateGuess<float>;

} // namespace property_types

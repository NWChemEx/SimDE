#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that can guess an initial density from a
 *         molecule and basis set.
 *
 *  Particularly for the SCF method, it is necessary to provide an initial
 *  guess for the electronic density. This property type is for modules that are
 *  capable of providing such a guess.
 *
 *  @tparam ElementType The type of the elements in the returned tensors
 */
template<typename ElementType = double>
struct GuessDensity : public sde::PropertyType<GuessDensity<ElementType>> {
    /// Type used to contain various MO subspaces
    using orbital_map = type::orbital_map<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class GuessDensity

//-------------------------------Implementations--------------------------------
template<typename ElementType>
auto GuessDensity<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set<ElementType>&>("Basis Set");
    rv["Molecule"].set_description(
      "The molecule for which the guess density is computed");
    rv["Basis Set"].set_description(
      "The basis set used for the density computation");
    return rv;
}

template<typename ElementType>
auto GuessDensity<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<orbital_map>("Molecular Orbitals");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

extern template class GuessDensity<double>;
extern template class GuessDensity<float>;

} // namespace property_types

#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that compute an initial reference
 *         wavefunction.
 *
 *  Most correlated electronic structure theory methods require an initial
 *  reference wavefunction from which
 *
 */
template<typename ElementType = double>
struct ReferenceWavefunction
  : public sde::PropertyType<ReferenceWavefunction<ElementType>> {
    /// Type used to contain various MO subspaces
    using orbital_map = type::orbital_map<ElementType>;
    /// Type of the returned tensor, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class ReferenceWavefunction

//------------------------------Implementations---------------------------------
template<typename ElementType>
auto ReferenceWavefunction<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set<ElementType>&>("Basis Set")
                .template add_field<type::size>("Derivative",type::size{0});
    rv["Molecule"].set_description("The molecular system");
    rv["Basis Set"].set_description("The basis set used for the computation");
    rv["Derivative"].set_description("The derivative order of the energy");
    return rv;
}

template<typename ElementType>
auto ReferenceWavefunction<ElementType>::results_() {
    auto rv = sde::declare_result()
                .add_field<ElementType>("Energy")
                .template add_field<orbital_map>("Molecular Orbitals");
    rv["Energy"].set_description("The computed energy or derivatives");
    rv["Molecular Orbitals"].set_description("The reference wavefunction");
    return rv;
}

extern template class ReferenceWavefunction<double>;
extern template class ReferenceWavefunction<float>;

} // namespace property_types

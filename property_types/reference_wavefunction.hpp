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
 *  @tparam ElementType The type of the returned energy
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
template<typename ElementType = double, typename OrbitalType = type::orbitals<ElementType>>
struct ReferenceWavefunction
  : public sde::PropertyType<ReferenceWavefunction<ElementType, OrbitalType>> {
    /// Type used to contain various MO subspaces
    using orbital_map = type::orbital_map<OrbitalType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class ReferenceWavefunction

//------------------------------Implementations---------------------------------
template<typename ElementType, typename OrbitalType>
auto ReferenceWavefunction<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set<ElementType>&>("Basis Set")
                .template add_field<type::size>("Derivative",type::size{0});
    rv["Molecule"].set_description("The molecular system");
    rv["Basis Set"].set_description("The basis set used for the computation");
    rv["Derivative"].set_description("The derivative order of the energy");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto ReferenceWavefunction<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result()
                .add_field<ElementType>("Energy")
                .template add_field<orbital_map>("Molecular Orbitals");
    rv["Energy"].set_description("The computed energy or derivatives");
    rv["Molecular Orbitals"].set_description("The reference wavefunction");
    return rv;
}

extern template class ReferenceWavefunction<double>;
extern template class ReferenceWavefunction<double, type::orthogonal_orbs<double>>;
extern template class ReferenceWavefunction<double, type::canonical_mos<double>>;
extern template class ReferenceWavefunction<float>;
extern template class ReferenceWavefunction<float,  type::orthogonal_orbs<float>>;
extern template class ReferenceWavefunction<float,  type::canonical_mos<float>>;

} // namespace property_types

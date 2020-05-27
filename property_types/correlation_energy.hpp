#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that compute an correlation energy.
 *
 *  Most correlated electronic structure theory methods require an initial
 *  reference wavefunction from which
 *
 *  @tparam ElementType The type of the returned energy
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
    template<typename ElementType = double, typename OrbitalType = type::orbitals<ElementType>>
    struct CorrelationEnergy : public sde::PropertyType<CorrelationEnergy<ElementType, OrbitalType>> {
        /// Type used to contain various MO subspaces
        using orbital_map = type::orbital_map<OrbitalType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class CorrelationEnergy

//------------------------------Implementations---------------------------------
    template<typename ElementType, typename OrbitalType>
    auto CorrelationEnergy<ElementType, OrbitalType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set<ElementType>&>("Basis Set")
                .template add_field<orbital_map>("Reference Molecular Orbitals")
                .template add_field<type::size>("Derivative",type::size{0});
        rv["Molecule"].set_description("The molecular system");
        rv["Basis Set"].set_description("The basis set used for the computation");
        rv["Reference Molecular Orbitals"].set_description("The molecular orbitals of the reference");
        rv["Derivative"].set_description("The derivative order of the energy");
        return rv;
    }

    template<typename ElementType, typename OrbitalType>
    auto CorrelationEnergy<ElementType, OrbitalType>::results_() {
        auto rv = sde::declare_result()
                .add_field<ElementType>("Correlation Energy");
        rv["Correlation Energy"].set_description("The computed energy or derivatives");
        return rv;
    }

    extern template class CorrelationEnergy<double>;
    extern template class CorrelationEnergy<double, type::orthogonal_orbs<double>>;
    extern template class CorrelationEnergy<double, type::canonical_mos<double>>;
    extern template class CorrelationEnergy<float>;
    extern template class CorrelationEnergy<float,  type::orthogonal_orbs<float>>;
    extern template class CorrelationEnergy<float,  type::canonical_mos<float>>;

} // namespace property_types

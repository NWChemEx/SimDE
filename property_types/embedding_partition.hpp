#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that can partition the density into
 * active and environment parts
 *
 *  @tparam ElementType the type of the elements in the basis set
 *  @tparam OrbitalType the type of the input and output orbital spaces
 */
template<typename ElementType = double, typename OrbitalType = type::orbitals<ElementType>>
struct EmbedPartition : public sde::PropertyType<EmbedPartition<ElementType, OrbitalType>> {
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class UpdateMOs

//-------------------------------Implementations--------------------------------
template<typename ElementType, typename OrbitalType>
auto EmbedPartition<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                    .add_field<const type::molecule&>("Molecule")
                    .add_field<const type::basis_set<ElementType>&>("Basis Set")
                    .template add_field<const std::vector<type::size>&>("Active Atoms")
                    .template add_field<const OrbitalType&>("Initial OrbitalSpace");
    rv["Molecule"].set_description("The molecule associated with the density");
    rv["Basis Set"].set_description("The basis set used for the density");
    rv["Active Atoms"].set_description("The list of active atoms");
    rv["Initial OrbitalSpace"].set_description("The initial MOs/density");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto EmbedPartition<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result()
            .add_field<int>("N Active MOs")
            .template add_field<OrbitalType>("Orbital Space");
    rv["N Active MOs"].set_description("The number of active MOs");
    rv["Orbital Space"].set_description("The OrbitalSpace with computed density and MOs");
    return rv;
}

extern template class EmbedPartition<double>;
extern template class EmbedPartition<double, type::orthogonal_orbs<double>>;
extern template class EmbedPartition<double, type::canonical_mos<double>>;
extern template class EmbedPartition<float>;
extern template class EmbedPartition<float,  type::orthogonal_orbs<float>>;
extern template class EmbedPartition<float,  type::canonical_mos<float>>;

} // namespace property_types

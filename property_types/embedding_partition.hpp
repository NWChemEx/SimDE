#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that can partition the density into
 * active and environment parts
 *
 *  @tparam ElementType the type of the elements in the tensors
 */
template<typename ElementType = double>
struct EmbedPartition : sde::PropertyType<EmbedPartition<ElementType>> {
    /// The type of the new MOs, accounting for ElementType
    using orbital_type = type::orbitals<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class UpdateMOs

//-------------------------------Implementations--------------------------------
template<typename ElementType>
auto EmbedPartition<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                    .add_field<const type::molecule&>("Molecule")
                    .add_field<const type::basis_set&>("Basis Set")
                    .add_field<const std::vector<type::size>&>("Active Atoms")
                    .template add_field<const orbital_type&>("Initial OrbitalSpace");
    rv["Molecule"].set_description("The molecule associated with the density");
    rv["Basis Set"].set_description("The basis set used for the density");
    rv["Active Atoms"].set_description("The list of active atoms");
    rv["Initial OrbitalSpace"].set_description("The initial MOs/density");
    return rv;
}

template<typename ElementType>
auto EmbedPartition<ElementType>::results_() {
    auto rv = sde::declare_result()
            .add_field<int>("N Active MOs")
            .template add_field<orbital_type>("Orbital Space");
    rv["N Active MOs"].set_description("The number of active MOs");
    rv["Orbital Space"].set_description("The OrbitalSpace with computed density and MOs");
    return rv;
}

extern template class EmbedPartition<double>;
extern template class EmbedPartition<float>;

} // namespace property_types

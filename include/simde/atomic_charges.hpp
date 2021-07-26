#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

/**
 * @brief The property type for modules that calculate atomic charges.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 * @tparam OrbitalType The type of the input orbital space
 */
template<typename OrbitalType>
DECLARE_TEMPLATED_PROPERTY_TYPE(AtomicCharges, OrbitalType);

//---------------------------Implementations------------------------------------
template<typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_INPUTS(AtomicCharges, OrbitalType) {
    auto rv = pluginplay::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

template<typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_RESULTS(AtomicCharges, OrbitalType) {
    auto rv =
      pluginplay::declare_result().add_field<type::tensor>("Partial Charges");
    rv["Partial Charges"].set_description("The calculated partial charges");
    return rv;
}

extern template class AtomicCharges<type::derived_space>;
extern template class AtomicCharges<type::canonical_space>;

} // namespace simde

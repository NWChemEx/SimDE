#pragma once
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {

/** @brief The property type for modules that compute energies and energy
 *         derivatives of molecular systems.
 *
 *  Arguably one of the most important quantities in electronic structure theory
 *  is the energy of the system. Modules that are capable of computing the
 *  energy of a molecular system satisfy the Energy property type.
 *
 *  @tparam ElementType The type of the elements in the tensors.
 */
template<typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(Energy, ElementType);

//-------------------------------Implementations--------------------------------
template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Energy, ElementType) {
    auto rv =
      sde::declare_input().add_field<const type::chemical_system&>("system");
    rv["system"].set_description("The molecular system");
    return rv;
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Energy, ElementType) {
    auto rv = sde::declare_result().add_field<ElementType>("Energy");
    rv["Energy"].set_description("The computed energy");
    return rv;
}

extern template class Energy<double>;
extern template class Energy<float>;

} // namespace simde

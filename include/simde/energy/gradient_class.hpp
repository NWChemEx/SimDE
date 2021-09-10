#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

/** @brief The property type for modules that compute gradients 
 *         (1st order derivatives of the energy wrt atom positions)
 *         of molecular systems.
 *
 *  @tparam ElementType The type of the elements in the tensors.
 */
DECLARE_PROPERTY_TYPE(Gradient);

//-------------------------------Implementations--------------------------------
PROPERTY_TYPE_INPUTS(Gradient) {
    using chem_sys_t = const type::chemical_system&;
    auto rv = pluginplay::declare_input().add_field<chem_sys_t>("system");
    rv["system"].set_description("The molecular system");
    return rv;
}

PROPERTY_TYPE_RESULTS(Gradient) {
    using grad_t = std::vector<double>;
    auto rv = pluginplay::declare_result().add_field<grad_t>("Gradient");
    rv["Gradient"].set_description("The computed 1st order derivative of the energy wrt to atom positions");
    return rv;
}

} // namespace simde

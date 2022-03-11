#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

/** @brief API for modules which create SCF densities.
 *
 *  Modules which satisfy the `SCFDensity` property type effectively
 *  have an API: `simde::type::el_density (const canonical_reference&)`.
 *  For example, the `SCF::Density` will compute the density by extracting the
 *  coeffecients for the occupied MOs from the reference and contracting them.
 */
DECLARE_PROPERTY_TYPE(SCFDensity);

PROPERTY_TYPE_INPUTS(SCFDensity) {
    using simde::type::canonical_reference;
    auto rv =
      pluginplay::declare_input().add_field<const canonical_reference&>("Phi0");
    return rv;
}

PROPERTY_TYPE_RESULTS(SCFDensity) {
    using simde::type::el_density;
    auto rv = pluginplay::declare_result().add_field<el_density>("Density");
    return rv;
}

} // namespace simde
#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

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
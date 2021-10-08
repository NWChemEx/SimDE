#pragma once
#include "simde/energy/gradient.hpp"
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

DECLARE_DERIVED_PROPERTY_TYPE(AOGradient, Gradient);

PROPERTY_TYPE_INPUTS(AOGradient) {
    using ao_space = const type::ao_space&;
    auto rv        = pluginplay::declare_input().add_field<ao_space>("AOs");
    rv["AOs"].set_description("The atomic orbital basis set");
    return rv;
}

PROPERTY_TYPE_RESULTS(AOGradient) {
    auto rv = pluginplay::declare_result();
    return rv;
}

} // namespace simde

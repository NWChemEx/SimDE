#pragma once
#include "simde/energy/ao_energy.hpp"
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

DECLARE_DERIVED_PROPERTY_TYPE(AOGradient, AOEnergy);

PROPERTY_TYPE_INPUTS(AOGradient) {
    auto rv = pluginplay::declare_input();
    return rv;
}

PROPERTY_TYPE_RESULTS(AOGradient) {
    using point_vector = std::vector<Point<double>> > ;
    auto rv =
      pluginplay::declare_result().template add_field<const point_vector&>(
        "Gradient");
    rv["Gradient"].set_description(
      "The 1st derivates wrt the nuclear coordinates");
    return rv;
}

} // namespace simde

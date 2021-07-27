#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(UpdateDensity);

PROPERTY_TYPE_INPUTS(UpdateDensity) {
    using tensor_type = const type::tensor&;

    auto rv = pluginplay::declare_input()
                .add_field<tensor_type>("Fock Matrix")
                .template add_field<tensor_type>("Density");
    return rv;
}

PROPERTY_TYPE_RESULTS(UpdateDensity) {
    return pluginplay::declare_result().add_field<type::tensor>("New density");
}

} // namespace simde

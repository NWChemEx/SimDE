#pragma once

namespace simde {

DECLARE_PROPERTY_TYPE(UpdateDensity);

PROPERTY_TYPE_INPUTS(UpdateDensity) {
    using tensor_type = const type::tensor&;

    auto rv = sde::declare_inputs()
                .add_field<tensor_type>("Fock Matrix")
                .template add_field<tensor_type>("Density");
    return rv;
}

PROPERTY_TYPE_RESULTS(UpdateDensity) {
    return sde::declare_results().add_field<type::tensor>("New density");
}

} // namespace simde

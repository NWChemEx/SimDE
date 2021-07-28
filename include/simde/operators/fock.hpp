#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(FockOp);

PROPERTY_TYPE_INPUTS(FockOp) {
    using ham         = const type::hamiltonian&;
    using tensor_type = const type::tensor&;

    auto rv = pluginplay::declare_input()
                .add_field<ham>("System Hamiltonian")
                .template add_field<tensor_type>("Density");
    return rv;
}

PROPERTY_TYPE_RESULTS(FockOp) {
    return pluginplay::declare_result().add_field<type::fock>("Fock operator");
}

} // namespace simde

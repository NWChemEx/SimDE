#pragma once
#include "property_types/types.hpp"
#include <sde/sde.hpp>

namespace property_types {

DECLARE_PROPERTY_TYPE(Connectivity);

PROPERTY_TYPE_INPUTS(Connectivity) {
    using mol_input_t = const type::molecule&;
    auto rv           = sde::declare_input().add_field<mol_input_t>("Molecule");
    rv.at("Molecule")
      .set_description("The molecule whose bonds are being assigned.");
    return rv;
}

PROPERTY_TYPE_RESULTS(Connectivity) {
    using table_t = type::connectivity_table;
    auto rv = sde::declare_result().add_field<table_t>("Connectivity Table");
    rv.at("Connectivity Table")
      .set_description("Connectivity of the input molecule.");
    return rv;
}

} // namespace property_types
#pragma once
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(ShellNorms);

//------------------------Implementations---------------------------------------

PROPERTY_TYPE_INPUTS(ShellNorms) {
    using basis_type = const type::ao_space&;
    auto rv = sde::declare_input()
                .add_field<basis_type>("Basis1")
                .template add_field<basis_type>("Basis2")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Basis1"].set_description("The first basis set");
    rv["Basis2"].set_description("The second basis set");
    rv["Derivative"].set_description(
      "The derivative order of integrals to be computed");
    return rv;
}

PROPERTY_TYPE_RESULTS(ShellNorms) {
    using return_type = std::vector<std::vector<double>>;
    auto rv = sde::declare_result().add_field<return_type>("Screening Matrix");
    rv["Screening Matrix"].set_description(
      "The Cauchy Schwarz screening matrix");
    return rv;
}

} // namespace simde

#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

template<typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(ShellNorms, OperatorType);

//------------------------Implementations---------------------------------------

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ShellNorms, OperatorType) {
    using basis_type = const simde::type::ao_space&;
    OperatorType op;
    auto op_key = op.as_string();
    auto rv     = pluginplay::declare_input()
                .add_field<basis_type>("bra")
                .template add_field<const OperatorType&>(op_key)
                .template add_field<basis_type>("ket");
    rv["bra"].set_description("The first basis set");
    rv[op_key].set_description("The integral operator");
    rv["ket"].set_description("The second basis set");
    return rv;
}

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ShellNorms, OperatorType) {
    using return_type = std::vector<std::vector<double>>;
    auto rv =
      pluginplay::declare_result().add_field<return_type>("Screening Matrix");
    rv["Screening Matrix"].set_description(
      "The Cauchy Schwarz screening matrix");
    return rv;
}

} // namespace simde

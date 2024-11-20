#pragma once
#include <pluginplay/pluginplay.hpp>
#include <simde/types.hpp>

namespace simde {

template<typename DensityType>
DECLARE_TEMPLATED_PROPERTY_TYPE(FockOperator, DensityType);

template<typename DensityType>
TEMPLATED_PROPERTY_TYPE_INPUTS(FockOperator, DensityType) {
    using hamiltonian_type = const type::hamiltonian&;
    return pluginplay::declare_input()
      .add_field<hamiltonian_type>("Hamiltonian")
      .template add_field<DensityType>("Density");
}

template<typename DensityType>
TEMPLATED_PROPERTY_TYPE_RESULTS(FockOperator, DensityType) {
    return pluginplay::declare_result().template add_field<type::fock>(
      "Fock operator");
}

} // namespace simde
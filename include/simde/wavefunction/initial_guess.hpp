#pragma once
#include <pluginplay/pluginplay.hpp>
#include <simde/types.hpp>

namespace simde {

template<typename ResultType>
DECLARE_TEMPLATED_PROPERTY_TYPE(InitialGuess, ResultType);

template<typename ResultType>
TEMPLATED_PROPERTY_TYPE_INPUTS(InitialGuess, ResultType) {
    using hamiltonian_type = const type::hamiltonian&;
    using aos_type         = const type::aos&;
    return PropertyType::inputs()
      .template add_field<hamiltonian_type>("Hamiltonian")
      .template add_field<aos_type>("AOs");
}

template<typename ResultType>
TEMPLATED_PROPERTY_TYPE_RESULTS(InitialGuess, ResultType) {
    return pluginplay::declare_result().template add_field<ResultType>(
      "Initial Wavefunction");
}

} // namespace simde
#pragma once
#include <pluginplay/pluginplay.hpp>
#include <simde/types.hpp>

namespace simde {

template<typename GuessType>
DECLARE_TEMPLATED_PROPERTY_TYPE(UpdateGuess, GuessType);

template<typename GuessType>
TEMPLATED_PROPERTY_TYPE_INPUTS(UpdateGuess, GuessType) {
    using guess_type = const GuessType&;
    using fock_type  = const type::fock&;
    return pluginplay::declare_input()
      .template add_field<fock_type>("New Fock Operator")
      .template add_field<guess_type>("Old guess");
}

template<typename GuessType>
TEMPLATED_PROPERTY_TYPE_RESULTS(UpdateGuess, GuessType) {
    return pluginplay::declare_result().template add_field<GuessType>(
      "New guess");
}

} // namespace simde
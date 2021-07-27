#pragma once
#include "simde/localized_orbitals.hpp"

namespace simde {

template<typename InputOrbitals, typename OutputOrbitals>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(
  PAOs, LocalizedOrbitals<InputOrbitals, OutputOrbitals>, InputOrbitals,
  OutputOrbitals);

template<typename InputOrbitals, typename OutputOrbitals>
TEMPLATED_PROPERTY_TYPE_INPUTS(PAOs, InputOrbitals, OutputOrbitals) {
    return pluginplay::declare_input();
}

template<typename InputOrbitals, typename OutputOrbitals>
TEMPLATED_PROPERTY_TYPE_RESULTS(PAOs, InputOrbitals, OutputOrbitals) {
    return pluginplay::declare_result();
}

} // namespace simde

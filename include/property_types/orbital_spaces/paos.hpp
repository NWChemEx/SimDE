#pragma once
#include "property_types/localized_orbitals.hpp"

namespace property_types {

template<typename InputOrbitals, typename OutputOrbitals>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(
  PAOs, LocalizedOrbitals<InputOrbitals, OutputOrbitals>, InputOrbitals,
  OutputOrbitals);

template<typename InputOrbitals, typename OutputOrbitals>
TEMPLATED_PROPERTY_TYPE_INPUTS(PAOs, InputOrbitals, OutputOrbitals) {
    return sde::declare_input();
}

template<typename InputOrbitals, typename OutputOrbitals>
TEMPLATED_PROPERTY_TYPE_RESULTS(PAOs, InputOrbitals, OutputOrbitals) {
    return sde::declare_result();
}

} // namespace property_types
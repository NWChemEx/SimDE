#pragma once
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/types.hpp>
#include <simde/utils/convert.hpp>

namespace simde {
inline void export_utils(python_module_reference m) {
    using HamiltonianFromChemicalSystem =
      Convert<type::hamiltonian, type::chemical_system>;
    EXPORT_PROPERTY_TYPE(HamiltonianFromChemicalSystem, m);
}
} // namespace simde
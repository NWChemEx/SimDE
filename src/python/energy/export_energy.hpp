#pragma once
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/energy/energy.hpp>

namespace simde {

inline void export_energy(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(Energy, m);
}

} // namespace simde

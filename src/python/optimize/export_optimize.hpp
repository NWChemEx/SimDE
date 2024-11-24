#pragma once
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/optimize/optimize.hpp>
#include <simde/types.hpp>

namespace simde {
inline void export_optimize(python_module_reference m) {
    using OptimizeRSCFEnergyWRTRSCFWavefunction =
      Optimize<ESCF<type::cmos>, type::rscf_wf>;

    EXPORT_PROPERTY_TYPE(OptimizeRSCFEnergyWRTRSCFWavefunction, m);
}
} // namespace simde
#pragma once
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/quantum_mechanics/quantum_mechanics.hpp>
#include <simde/types.hpp>

namespace simde {
inline void export_quantum_mechanics(python_module_reference m) {
    using FockOperator_e_density = FockOperator<type::e_density>;
    using FockOperator_decomposable_e_density =
      FockOperator<type::decomposable_e_density>;

    EXPORT_PROPERTY_TYPE(FockOperator_e_density, m);
    EXPORT_PROPERTY_TYPE(FockOperator_decomposable_e_density, m);

    using RSCFGuess = InitialGuess<type::rscf_wf>;
    EXPORT_PROPERTY_TYPE(RSCFGuess, m);

    using UpdateRSCFGuess = UpdateGuess<type::rscf_wf>;
    EXPORT_PROPERTY_TYPE(UpdateRSCFGuess, m);
}
} // namespace simde
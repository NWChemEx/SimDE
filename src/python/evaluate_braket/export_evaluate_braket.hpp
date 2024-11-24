#pragma once
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/evaluate_braket/evaluate_braket.hpp>
#include <simde/types.hpp>

namespace simde {
inline void export_evaluate_braket(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(aos_t_e_aos, m);
    EXPORT_PROPERTY_TYPE(aos_v_en_aos, m);

    using aos_rho_e_cmos_aos = aos_rho_e_aos<type::cmos>;
    EXPORT_PROPERTY_TYPE(aos_rho_e_cmos_aos, m);

    EXPORT_PROPERTY_TYPE(ERI2, m);
    EXPORT_PROPERTY_TYPE(ERI3, m);
    EXPORT_PROPERTY_TYPE(ERI4, m);

    using ESCF_CMOs = ESCF<type::cmos>;
    EXPORT_PROPERTY_TYPE(ESCF_CMOs, m);
}
} // namespace simde
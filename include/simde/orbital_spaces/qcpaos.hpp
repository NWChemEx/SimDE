#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename InputOrbitals, typename OutputOrbitals>
DECLARE_TEMPLATED_PROPERTY_TYPE(QCPAOs, InputOrbitals, OutputOrbitals);

template<typename InputOrbitals, typename OutputOrbitals>
TEMPLATED_PROPERTY_TYPE_INPUTS(QCPAOs, InputOrbitals, OutputOrbitals) {
    auto rv = pluginplay::declare_input()
                .add_field<const type::fock&>("Fock Operator")
                .template add_field<const InputOrbitals&>("Orbitals");
    return rv;
}

template<typename InputOrbitals, typename OutputOrbitals>
TEMPLATED_PROPERTY_TYPE_RESULTS(QCPAOs, InputOrbitals, OutputOrbitals) {
    auto rv = pluginplay::declare_result().add_field<OutputOrbitals>("PAOs");
    return rv;
}

using qcpaos = QCPAOs<type::derived_space, type::canonical_space>;
// using sparse_qcpaos =
//   QCPAOs<type::ind_derived_space, type::canonical_dep_space>;

} // namespace simde

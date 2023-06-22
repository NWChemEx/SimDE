/*
 * Copyright 2022 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "simde/types.hpp"
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename OpType, typename RhoType>
DECLARE_TEMPLATED_PROPERTY_TYPE(OneEDensityExpval, OpType, RhoType);

template<typename OpType, typename RhoType>
TEMPLATED_PROPERTY_TYPE_INPUTS(OneEDensityExpval, OpType, RhoType) {
    using op_t = const OpType&;

    auto rv = pluginplay::declare_input()
                .add_field<op_t>("Operator")
                .template add_field<const RhoType&>("Rho");
    return rv;
}

template<typename OpType, typename RhoType>
TEMPLATED_PROPERTY_TYPE_RESULTS(OneEDensityExpval, OpType, RhoType) {
    auto rv = pluginplay::declare_result().add_field<double>("value");
    return rv;
}

using OneEDensityElecEnergy =
  OneEDensityExpval<type::els_hamiltonian, type::el_density>;

using OneEDensityTotalEnergy =
  OneEDensityExpval<type::hamiltonian, type::el_density>;

} // namespace simde

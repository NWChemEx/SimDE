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
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals::f12 {

template<typename OccType, typename VirtType>
DECLARE_TEMPLATED_PROPERTY_TYPE(CouplingCoefficient, OccType, VirtType);

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_INPUTS(CouplingCoefficient, OccType, VirtType) {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecular system")
                .template add_field<const OccType&>("Occupied Orbital Space")
                .template add_field<const VirtType&>("Virtual Orbital Space");
    return rv;
}

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_RESULTS(CouplingCoefficient, OccType, VirtType) {
    using tensor_type = std::decay_t<decltype(std::declval<VirtType>().C())>;
    auto rv           = sde::declare_result().add_field<tensor_type>("C");
    return rv;
}

} // namespace property_types::ao_integrals::f12
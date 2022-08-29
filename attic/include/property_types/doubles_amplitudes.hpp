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

namespace property_types {

template<typename OccType, typename VirtType>
DECLARE_TEMPLATED_PROPERTY_TYPE(DoublesAmplitudes, OccType, VirtType);

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_INPUTS(DoublesAmplitudes, OccType, VirtType) {
    auto rv = sde::declare_input()
                .add_field<const OccType&>("occupied space")
                .template add_field<const VirtType&>("virtual space");
    return rv;
}

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_RESULTS(DoublesAmplitudes, OccType, VirtType) {
    using tensor_type = std::decay_t<decltype(std::declval<OccType>().C())>;
    auto rv           = sde::declare_result().add_field<tensor_type>("T");
    return rv;
}

} // namespace property_types
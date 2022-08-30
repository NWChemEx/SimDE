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
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/n_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals {

/**
 * @brief The property type for modules that build tensors filled with electron
 * nuclear attraction integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename ElementType = double>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(Nuclear, TwoCenter<ElementType>,
                                        ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Nuclear, ElementType) {
    using molecule_t = const type::molecule&;

    return sde::declare_input().add_field<molecule_t>("molecule");
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Nuclear, ElementType) {
    using tensor_type = type::tensor<ElementType>;
    using my_type     = Nuclear<ElementType>;

    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<my_type>("Z_A/r_iA"));
}

extern template class Nuclear<double>;
extern template class Nuclear<float>;

} // namespace property_types::ao_integrals

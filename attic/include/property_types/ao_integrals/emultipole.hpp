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
 * @brief The property type for modules that build tensors filled with various
 * electric multipole integrals in the AO basis set.
 *
 * @tparam ElementType The type of the element in the tensor. Defaults to
 *                     `double`.
 */
template<typename ElementType, unsigned Order>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(EMultipole, TwoCenter<ElementType>,
                                        ElementType, Order);

template<typename ElementType, unsigned Order>
TEMPLATED_PROPERTY_TYPE_INPUTS(EMultipole, ElementType, Order) {
    using center_t = const std::array<ElementType, 3>&;

    return sde::declare_input().add_field<center_t>("origin");
}

template<typename ElementType, unsigned Order>
TEMPLATED_PROPERTY_TYPE_RESULTS(EMultipole, ElementType, Order) {
    using tensor_type = type::tensor<ElementType>;
    using base_type   = TwoCenter<ElementType>;

    auto op = "r**" + std::to_string(Order);
    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<base_type>(op));
}

template<typename ElementType>
using EDipole = EMultipole<ElementType, 1>;

template<typename ElementType>
using EQuadrupole = EMultipole<ElementType, 2>;

template<typename ElementType>
using EOctopole = EMultipole<ElementType, 3>;

extern template class EMultipole<double, 1>;
extern template class EMultipole<float, 1>;
extern template class EMultipole<double, 2>;
extern template class EMultipole<float, 2>;
extern template class EMultipole<double, 3>;
extern template class EMultipole<float, 3>;

} // namespace property_types::ao_integrals

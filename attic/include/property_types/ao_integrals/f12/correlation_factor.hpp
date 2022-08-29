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
#include "property_types/ao_integrals/detail_/macros.hpp"
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/type_traits.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types::ao_integrals::f12 {

/** @brief This is the property type for the quantity usually denoted as
 *         @f$f_{12}(r_{12})@f$ in f12 theory.
 */
template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(CorrelationFactor, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(CorrelationFactor, BaseType) {
    return sde::declare_input();
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(CorrelationFactor, BaseType) {
    using traits       = detail_::NCenterTraits<BaseType>;
    using element_type = typename traits::element_type;
    using space_type   = typename traits::space_type;
    using tensor_type  = typename space_type::overlap_type;
    using my_type      = CorrelationFactor<BaseType>;

    return sde::declare_result().add_field<tensor_type>(
      detail_::make_key<my_type>("f_12(r_12)"));
}

template<typename ElementType>
using SparseCorrelationFactor4C =
  CorrelationFactor<SparseFourCenter<ElementType>>;

MULTICENTER_AO_INTEGRAL_TYPEDEFS(CorrelationFactor);
MULTICENTER_AO_INTEGRAL_EXTERNS(CorrelationFactor);

} // namespace property_types::ao_integrals::f12
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

namespace property_types::ao_integrals {

template<std::size_t N, typename AOSpaceType>
DECLARE_TEMPLATED_PROPERTY_TYPE(NCenter, N, AOSpaceType);

template<std::size_t N, typename AOSpaceType>
TEMPLATED_PROPERTY_TYPE_INPUTS(NCenter, N, AOSpaceType) {
    using const_ao_space_t = const AOSpaceType&;

    if constexpr(N == 2) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const_ao_space_t>("ket");
    } else if constexpr(N == 3) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else if constexpr(N == 4) {
        return sde::declare_input()
          .add_field<const_ao_space_t>("bra 1")
          .template add_field<const_ao_space_t>("bra 2")
          .template add_field<const_ao_space_t>("ket 1")
          .template add_field<const_ao_space_t>("ket 2");
    } else {
        // N.B. if we get here we know N != 2, but we can't just hardcode false
        static_assert(N == 2, "Inputs not defined for N outside range [2, 4]");
    }
}

template<std::size_t N, typename AOSpaceType>
TEMPLATED_PROPERTY_TYPE_RESULTS(NCenter, N, AOSpaceType) {
    return sde::declare_result();
}

// ---------------------- Dense Typedefs ---------------------------------------

template<std::size_t N, typename ElementType>
using DenseNCenter = NCenter<N, type::ao_space_t<ElementType>>;

template<typename ElementType>
using TwoCenter = DenseNCenter<2, ElementType>;

template<typename ElementType>
using ThreeCenter = DenseNCenter<3, ElementType>;

template<typename ElementType>
using FourCenter = DenseNCenter<4, ElementType>;

// ----------------------- Sparse Typedefs -------------------------------------

template<std::size_t N, typename ElementType>
using SparseNCenter = NCenter<N, type::sparse_ao_space_t<ElementType>>;

template<typename ElementType>
using SparseTwoCenter = SparseNCenter<2, ElementType>;

template<typename ElementType>
using SparseThreeCenter = SparseNCenter<3, ElementType>;

template<typename ElementType>
using SparseFourCenter = SparseNCenter<4, ElementType>;

} // namespace property_types::ao_integrals
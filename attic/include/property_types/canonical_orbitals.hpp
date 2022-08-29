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

// #pragma once
// #include "property_types/types.hpp"
// #include <sde/property_type/property_type.hpp>

// namespace property_types {

// /** @brief The property type for modules that compute canonical orbitals.
//  *
//  *  Canonical orbitals diagonalize the Fock matrix. Modules that satisfy this
//  *  property type take an input set of orbitals and a Fock matrix and return
//  *  the orbitals that digonalize the Fock matrix.
//  *
//  *  @tparam InputOrbitalType The type of the input orbitals.
//  *  @tparam OutputOrbitalType The type of the output orbitals.
//  */
// template<typename InputOrbitalType, typename OutputOrbitalType>
// DECLARE_TEMPLATED_PROPERTY_TYPE(CanonicalOrbitals, InputOrbitalType,
//                                 OutputOrbitalType);

// template<typename InputOrbitalType, typename OutputOrbitalType>
// TEMPLATED_PROPERTY_TYPE_INPUTS(CanonicalOrbitals, InputOrbitalType,
//                                OutputOrbitalType) {
//     auto rv =
//       sde::declare_input()
//         .add_field<const InputOrbitalType&>("Orbitals")
//         .template add_field<const chemist::type::tensor<double>&>("F");
//     return rv;
// }

// template<typename InputOrbitalType, typename OutputOrbitalType>
// TEMPLATED_PROPERTY_TYPE_RESULTS(CanonicalOrbitals, InputOrbitalType,
//                                 OutputOrbitalType) {
//     auto rv = sde::declare_result().add_field<OutputOrbitalType>("K");
//     return rv;
// }

// } // namespace property_types
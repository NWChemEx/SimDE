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

namespace property_types {

/** @brief Property type for modules that can update a guess of MOs
 *
 *  @tparam ElementType the type of the elements in the tensors
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbital_space_t<ElementType>>
struct UpdateGuess
  : public sde::PropertyType<UpdateGuess<ElementType, OrbitalType>> {
    /// Type used to contain various MO subspaces
    using orbital_map = type::orbital_map<OrbitalType>;
    /// The type of the tensors representing the MOs, accounting for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class UpdateGuess

//-------------------------------Implementations--------------------------------
template<typename ElementType, typename OrbitalType>
auto UpdateGuess<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::ao_space_t<ElementType>&>("Basis Set")
                .template add_field<const tensor_type&>("Fock Matrix");
    rv["Molecule"].set_description("The molecule associated with the density");
    rv["Basis Set"].set_description("The basis set used for the density");
    rv["Fock Matrix"].set_description(
      "The Fock matrix used for the density update");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto UpdateGuess<ElementType, OrbitalType>::results_() {
    auto rv =
      sde::declare_result().add_field<orbital_map>("Molecular Orbitals");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

extern template class UpdateGuess<double>;
extern template class UpdateGuess<double, type::derived_space_t<double>>;
extern template class UpdateGuess<double, type::canonical_space_t<double>>;
extern template class UpdateGuess<float>;
extern template class UpdateGuess<float, type::derived_space_t<float>>;
extern template class UpdateGuess<float, type::canonical_space_t<float>>;

} // namespace property_types
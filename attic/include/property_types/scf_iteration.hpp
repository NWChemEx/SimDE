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
#include <sde/property_type/property_type.hpp>

namespace simde {

/** @brief The property type for modules that compute electronic energies and
 *  build Fock matrices in the AO basis set.
 *
 *  The Fock matrix (or Kohn-Sham matrix for DFT) is an effective one-electron
 *  potential. Modules that satisfy this property type are capable of computing
 *  the Fock matrix in the AO basis set as well as the electronic energy of the
 *  system.
 *
 *  @tparam ElementType The type of the elements in the returned tensors.
 *  @tparam OrbitalType The type of the input orbital space
 */
template<typename OrbitalType>
DECLARE_TEMPLATED_PROPERTY_TYPE(SCFIteration, OrbitalType);

//-------------------------------------Implementations--------------------------

template<typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_INPUTS(SCFIteration, OrbitalType) {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals")
                .template add_field<const type::ao_space&>("bra")
                .template add_field<const type::ao_space&>("ket");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    rv["bra"].set_description("The basis set used for the bra");
    rv["ket"].set_description("The basis set used for the ket");
    return rv;
}

template<typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_INPUTS(SCFIteration, OrbitalType) {
    auto key = "(m|f|n)";
    auto rv  = sde::declare_result()
                .add_field<tensor_type>(key)
                .template add_field<ElementType>("Electronic Energy");
    rv[key].set_description("The computed Fock Matrix");
    rv["Electronic Energy"].set_description("The computed electronic energy");
    return rv;
}

extern template class SCFIteration<double>;
extern template class SCFIteration<double, type::derived_space_t<double>>;
extern template class SCFIteration<double, type::canonical_space_t<double>>;
extern template class SCFIteration<float>;
extern template class SCFIteration<float, type::derived_space_t<float>>;
extern template class SCFIteration<float, type::canonical_space_t<float>>;
} // namespace simde

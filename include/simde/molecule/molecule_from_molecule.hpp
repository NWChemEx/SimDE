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

/** @brief The property type for modules that transforms a molecule into another
 *         one.
 *
 * The usage of this property type can be pretty varied. Modules that satisfy
 * this property type could potentially just modify the coordinates of the
 * molecule (i.e. rotation, geometry optimization) or change the composition of
 * the molecule (i.e. add/remove hydrogens, fucntional groups).
 *
 */
DECLARE_PROPERTY_TYPE(MoleculeFromMolecule);

PROPERTY_TYPE_INPUTS(MoleculeFromMolecule) {
    using mol_t = const type::molecule&;
    auto rv = pluginplay::declare_input().add_field<mol_t>("Initial molecule");
    return rv;
}

PROPERTY_TYPE_RESULTS(MoleculeFromMolecule) {
    using mol_t = type::molecule;
    auto rv = pluginplay::declare_result().add_field<mol_t>("Final molecule");
    return rv;
}

} // namespace simde

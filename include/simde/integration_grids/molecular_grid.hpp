/*
 * Copyright 2025 NWChemEx-Project
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
#include <chemist/grid/grid_class.hpp>
#include <chemist/molecule/molecule.hpp>
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(MolecularGrid);

PROPERTY_TYPE_INPUTS(MolecularGrid) {
    using input_type =
      chemist::ChemistClassTraits<chemist::Molecule>::const_view_type;
    return pluginplay::declare_input().add_field<input_type>("Molecule");
}

PROPERTY_TYPE_RESULTS(MolecularGrid) {
    using result_type = chemist::Grid;
    return pluginplay::declare_result().add_field<result_type>("Grid");
}

} // namespace simde

/*
 * Copyright 2023 NWChemEx-Project
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
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/numerical_methods/numerical_methods.hpp>

namespace simde {

inline void export_numerical_methods(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(GeneralizedEigenSolve, m);
}

} // namespace simde

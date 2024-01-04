/*
 * Copyright 2024 NWChemEx-Project
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

#include "atoms/export_atoms.hpp"
#include "density/export_density.hpp"
#include "derivative/export_derivative.hpp"
#include "export_simde.hpp"
#include "operators/export_operators.hpp"

namespace simde {

PYBIND11_MODULE(experimental_simde, m) {
    m.doc() = "PySimDE: Python bindings for the experimental features in the "
              "Simulation development environment";
    export_atoms(m);
    export_density(m);
    export_derivative(m);
    export_operators(m);
}

} // namespace simde

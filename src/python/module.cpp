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

#include "basis_set/export_basis_set.hpp"
#include "chemical_system/export_chemical_system.hpp"
#include "derivative/export_derivative.hpp"
#include "energy/export_energy.hpp"
#include "evaluate_braket/export_evaluate_braket.hpp"
#include "export_simde.hpp"
#include "numerical_methods/export_numerical_methods.hpp"
#include "optimize/export_optimize.hpp"
#include "quantum_mechanics/export_quantum_mechanics.hpp"
#include "utils/export_utils.hpp"

namespace simde {

PYBIND11_MODULE(simde, m) {
    m.doc() =
      "PySimDE: Python bindings for the Simulation development environment";
    export_chemical_system(m);
    export_basis_set(m);
    export_energy(m);
    export_evaluate_braket(m);
    export_derivative(m);
    export_numerical_methods(m);
    export_optimize(m);
    export_utils(m);
    export_quantum_mechanics(m);
}

} // namespace simde

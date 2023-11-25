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
#include "energy/export_energy.hpp"
#include "export_simde.hpp"
#include "wavefunctions/export_wavefunctions.hpp"

namespace simde {

PYBIND11_MODULE(simde, m) {
    m.doc() =
      "PySimDE: Python bindings for the Simulation development environment";

    export_energy(m);
    export_aoenergy(m);
    export_molecular_basis_set(m);
    export_atomic_basis_set_from_sym(m);
    export_atomic_basis_set_from_z(m);
    export_NoncanonicalReference(m);
    export_CanonicalReference(m);
    export_CanonicalRefFromDensity(m);
    export_SCFWf(m);
    export_CanonicalManyBodyWf(m);
}

} // namespace simde

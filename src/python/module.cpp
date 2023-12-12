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

#include "atoms/export_atoms.hpp"
#include "basis_set/export_basis_set.hpp"
#include "density/export_density.hpp"
#include "derivative/export_derivative.hpp"
#include "energy/export_energy.hpp"
#include "export_simde.hpp"
#include "operators/export_operators.hpp"

namespace simde {

PYBIND11_MODULE(simde, m) {
    m.doc() =
      "PySimDE: Python bindings for the Simulation development environment";
    export_atomfromz(m);
    export_atomfromsym(m);
    export_atomdenfromz(m);
    export_atomdenfromsym(m);
    export_elecconfigfromz(m);
    export_elecconfigfromsym(m);
    export_fracconfigfromz(m);
    export_fracconfigfromsym(m);
    export_fullconfigfromz(m);
    export_fullconfigfromsym(m);
    export_symbolfromz(m);
    export_zfromsymbol(m);
    export_energy(m);
    export_aoenergy(m);
    export_aoenergynucleargradient(m);
    export_aoenergynuclearhessian(m);
    export_atomic_basis_set_from_z(m);
    export_atomic_basis_set_from_sym(m);
    export_molecular_basis_set(m);
    export_scf_density(m);
    export_initial_density(m);
    export_scf_guess_density(m);
    export_scf_density_step(m);
    export_fock_op(m);
    export_system_hamiltonian(m);
}

} // namespace simde

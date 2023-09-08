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

#include "../test_property_type.hpp"
#include "simde/density/density.hpp"

using namespace simde;

TEST_CASE("SCF Density") {
    test_property_type<SCFDensity>({"Phi0"}, {"Density"});
}

TEST_CASE("Initial Density") {
    test_property_type<InitialDensity>({"Hamiltonian"}, {"Density"});
}

TEST_CASE("SCF Guess Density") {
    test_property_type<SCFGuessDensity>({"Hamiltonian", "Input Space"},
                                        {"Output Density"});
}

TEST_CASE("SCF Density Step") {
    test_property_type<SCFDensityStep>({"Hamiltonian", "Input Space"},
                                       {"Output Density"});
}

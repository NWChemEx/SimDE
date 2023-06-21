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
#include "simde/tensor_representation/one_elec_density.hpp"

using namespace simde;

TEST_CASE("DM elec energy 1e") {
    test_property_type<OneEDensityElecEnergy>({"Operator", "Rho"}, {"value"});
}

TEST_CASE("DM total energy 1e") {
    test_property_type<OneEDensityTotalEnergy>({"Operator", "Rho"}, {"value"});
}
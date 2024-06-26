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
#include <simde/derivative/nuclear.hpp>
#include <simde/energy/ao_energy.hpp>
#include <vector>

using Gradient   = simde::EnergyNuclearGradientStdVectorD;
using Hessian    = simde::EnergyNuclearHessianStdVectorD;
using AOGradient = simde::AOEnergyNuclearGradientStdVectorD;
using AOHessian  = simde::AOEnergyNuclearHessianStdVectorD;

TEST_CASE("Nuclear Derivative Property Types") {
    test_property_type<Gradient>({"Chemical System", "Arg 1"}, {"Derivative"});
    test_property_type<Hessian>({"Chemical System", "Arg 1", "Arg2"},
                                {"Derivative"});
    test_property_type<AOGradient>({"AOs", "Chemical System", "Arg 1"},
                                   {"Derivative"});

    test_property_type<AOHessian>({"AOs", "Chemical System", "Arg 1", "Arg 2"},
                                  {"Derivative"});
}

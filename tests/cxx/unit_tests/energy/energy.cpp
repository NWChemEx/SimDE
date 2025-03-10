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
#include <simde/energy/energy.hpp>

using namespace simde;

TEST_CASE("TotalEnergy") {
    test_property_type<TotalEnergy>({"Chemical System"}, {"Energy"});
}

TEST_CASE("AOEnergy") {
    test_property_type<AOEnergy>({"AOs", "Chemical System"}, {"Energy"});
}

TEST_CASE("ElectrostaticEnergy<charges, charges>") {
    test_property_type<charge_charge_interaction>({"Objects", "Potential"},
                                                  {"Energy"});
}

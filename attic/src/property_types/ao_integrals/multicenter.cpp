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

#include "property_types/ao_integrals/electron_repulsion.hpp"
#include "property_types/ao_integrals/f12/f12.hpp"
#include "property_types/ao_integrals/stg.hpp"
#include "property_types/ao_integrals/yukawa.hpp"

namespace property_types::ao_integrals {
namespace f12 {

MULTICENTER_AO_INTEGRAL_DEFINES(CorrelationFactor);
MULTICENTER_AO_INTEGRAL_DEFINES(CorrelationFactorSquared);
MULTICENTER_AO_INTEGRAL_DEFINES(dfdrSquared);
MULTICENTER_AO_INTEGRAL_DEFINES(GR);

} // namespace f12

MULTICENTER_AO_INTEGRAL_DEFINES(ERI);
template class ERI<SparseFourCenter<double>>;
template class ERI<SparseFourCenter<float>>;
MULTICENTER_AO_INTEGRAL_DEFINES(STG);
MULTICENTER_AO_INTEGRAL_DEFINES(Yukawa);

} // namespace property_types::ao_integrals

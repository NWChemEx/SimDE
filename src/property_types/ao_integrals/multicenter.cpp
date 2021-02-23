#include "property_types/ao_integrals/electron_repulsion.hpp"
#include "property_types/ao_integrals/f12/f12.hpp"
#include "property_types/ao_integrals/stg.hpp"
#include "property_types/ao_integrals/yukawa.hpp"

namespace property_types::ao_integrals {

MULTICENTER_AO_INTEGRAL_DEFINES(CorrelationFactor);
MULTICENTER_AO_INTEGRAL_DEFINES(CorrelationFactorSquared);
MULTICENTER_AO_INTEGRAL_DEFINES(dfdrSquared);
MULTICENTER_AO_INTEGRAL_DEFINES(ERI);
MULTICENTER_AO_INTEGRAL_DEFINES(GR);
MULTICENTER_AO_INTEGRAL_DEFINES(STG);
MULTICENTER_AO_INTEGRAL_DEFINES(Yukawa);

} // namespace property_types::ao_integrals

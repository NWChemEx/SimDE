#include "property_types/ao_integrals/stg.hpp"

namespace property_types::ao_integrals {

template class STG<TwoCenter<double>>;
template class STG<TwoCenter<float>>;
template class STG<ThreeCenter<double>>;
template class STG<ThreeCenter<float>>;
template class STG<FourCenter<double>>;
template class STG<FourCenter<float>>;

} // namespace property_types::ao_integrals

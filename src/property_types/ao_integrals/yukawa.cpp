#include "property_types/ao_integrals/yukawa.hpp"

namespace property_types::ao_integrals {

template class Yukawa<TwoCenter<double>>;
template class Yukawa<TwoCenter<float>>;
template class Yukawa<ThreeCenter<double>>;
template class Yukawa<ThreeCenter<float>>;
template class Yukawa<FourCenter<double>>;
template class Yukawa<FourCenter<float>>;

} // namespace property_types::ao_integrals

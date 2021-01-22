#include "property_types/ao_integrals/electron_repulsion.hpp"
namespace property_types::ao_integrals {

template class ERI<TwoCenter<double>>;
template class ERI<TwoCenter<float>>;
template class ERI<ThreeCenter<double>>;
template class ERI<ThreeCenter<float>>;
template class ERI<FourCenter<double>>;
template class ERI<FourCenter<float>>;

} // namespace property_types::ao_integrals

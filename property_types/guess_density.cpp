#include "property_types/guess_density.hpp"

namespace property_types {

template class GuessDensity<double>;
template class GuessDensity<double, type::orthogonal_orbs<double>>;
template class GuessDensity<double, type::canonical_mos<double>>;
template class GuessDensity<float>;
template class GuessDensity<float,  type::orthogonal_orbs<float>>;
template class GuessDensity<float,  type::canonical_mos<double>>;

} // namespace property_types

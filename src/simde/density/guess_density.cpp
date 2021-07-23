#include "simde/guess_density.hpp"

namespace simde {

template class GuessDensity<double>;
template class GuessDensity<double, type::derived_space_t<double>>;
template class GuessDensity<double, type::canonical_space_t<double>>;
template class GuessDensity<float>;
template class GuessDensity<float, type::derived_space_t<float>>;
template class GuessDensity<float, type::canonical_space_t<double>>;

} // namespace simde

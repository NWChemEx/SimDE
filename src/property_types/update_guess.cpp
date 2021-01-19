#include "property_types/update_guess.hpp"

namespace property_types {

template class UpdateGuess<double>;
template class UpdateGuess<double, type::orthogonal_orbs<double>>;
template class UpdateGuess<double, type::canonical_mos<double>>;
template class UpdateGuess<float>;
template class UpdateGuess<float, type::orthogonal_orbs<float>>;
template class UpdateGuess<float, type::canonical_mos<float>>;

} // namespace property_types

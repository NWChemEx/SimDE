#include "property_types/xc_quantities.hpp"

namespace property_types {

template class PureXCQuantities<double>;
template class PureXCQuantities<double, type::orthogonal_orbs<double>>;
template class PureXCQuantities<double, type::canonical_mos<double>>;
template class PureXCQuantities<float>;
template class PureXCQuantities<float,  type::orthogonal_orbs<float>> ;
template class PureXCQuantities<float,  type::canonical_mos<float>>;

template class HybridXCQuantities<double>;
template class HybridXCQuantities<double, type::orthogonal_orbs<double>>;
template class HybridXCQuantities<double, type::canonical_mos<double>>;
template class HybridXCQuantities<float>;
template class HybridXCQuantities<float,  type::orthogonal_orbs<float>>;
template class HybridXCQuantities<float,  type::canonical_mos<float>>;

template class DoubleHybridXCQuantities<double>;
template class DoubleHybridXCQuantities<double, type::orthogonal_orbs<double>>;
template class DoubleHybridXCQuantities<double, type::canonical_mos<double>>;
template class DoubleHybridXCQuantities<float>;
template class DoubleHybridXCQuantities<float,  type::orthogonal_orbs<float>>;
template class DoubleHybridXCQuantities<float,  type::canonical_mos<float>>;

} // namespace property_types

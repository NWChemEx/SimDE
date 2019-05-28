#include "property_types/xc_quantities.hpp"

namespace property_types {

template class PureXCQuantities<double>;
template class PureXCQuantities<float>;

template class HybridXCQuantities<double>;
template class HybridXCQuantities<float>;

template class DoubleHybridXCQuantities<double>;
template class DoubleHybridXCQuantities<float>;

} // namespace property_types

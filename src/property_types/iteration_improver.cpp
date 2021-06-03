#include "property_types/iteration_improver.hpp"

namespace property_types {

template class IterationImprover<type::tensor<double>>;
template class IterationImprover<type::tensor<float>>;
template class IterationImprover<type::tensor_of_tensors<double>>;
template class IterationImprover<type::tensor_of_tensors<float>>;

} // namespace property_types

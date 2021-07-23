#include "simde/iteration_improver.hpp"

namespace simde {

template class IterationImprover<type::tensor<double>>;
template class IterationImprover<type::tensor<float>>;
template class IterationImprover<type::tensor_of_tensors<double>>;
template class IterationImprover<type::tensor_of_tensors<float>>;

} // namespace simde

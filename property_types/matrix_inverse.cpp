#include "property_types/matrix_inverse.hpp"

namespace property_types {

template class MatrixInverse<double>;
template class MatrixInverse<float>;
template class MatrixInverse<std::complex<double>>;
template class MatrixInverse<std::complex<float>>;

} // namespace property_types

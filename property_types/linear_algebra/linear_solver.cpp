#include "property_types/linear_algebra/linear_solver.hpp"

namespace property_types {

template class LinearSolver<double, double, double>;
template class LinearSolver<float, float, float>;

template class LinearSolver<std::complex<double>, std::complex<double>,
                            std::complex<double>>;
template class LinearSolver<std::complex<double>, double, std::complex<double>>;
template class LinearSolver<double, std::complex<double>, std::complex<double>>;

template class LinearSolver<std::complex<float>, std::complex<float>,
                            std::complex<float>>;
template class LinearSolver<std::complex<float>, float, std::complex<float>>;
template class LinearSolver<float, std::complex<float>, std::complex<float>>;

} // namespace property_types

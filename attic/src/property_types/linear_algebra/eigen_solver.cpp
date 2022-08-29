/*
 * Copyright 2022 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "simde/linear_algebra/eigen_solver.hpp"

namespace simde {

template class SelfAdjointEigenSolver<double, double>;
template class SelfAdjointEigenSolver<float, float>;
template class SelfAdjointEigenSolver<std::complex<double>, double>;
template class SelfAdjointEigenSolver<std::complex<float>, float>;

template class GeneralizedSelfAdjointEigenSolver<double, double, double>;
template class GeneralizedSelfAdjointEigenSolver<float, float, float>;
template class GeneralizedSelfAdjointEigenSolver<std::complex<double>,
                                                 std::complex<double>, double>;
template class GeneralizedSelfAdjointEigenSolver<std::complex<float>,
                                                 std::complex<float>, float>;
template class GeneralizedSelfAdjointEigenSolver<std::complex<double>, double,
                                                 double>;
template class GeneralizedSelfAdjointEigenSolver<std::complex<float>, float,
                                                 float>;

} // namespace simde

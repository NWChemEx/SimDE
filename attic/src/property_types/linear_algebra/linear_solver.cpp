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

#include "simde/linear_algebra/linear_solver.hpp"

namespace simde {

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

} // namespace simde

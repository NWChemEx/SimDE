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

#include "property_types/ao_integrals/fock_matrix.hpp"

namespace property_types {

template class FockMatrix_<double, type::derived_space_t<double>,
                           ao_integrals::TwoCenter<double>>;
template class FockMatrix_<float, type::derived_space_t<float>,
                           ao_integrals::TwoCenter<float>>;

} // namespace property_types

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

#include "property_types/ao_integrals/xc_quantities.hpp"

namespace property_types {

template class PureXCQuantities<double>;
template class PureXCQuantities<double, type::derived_space_t<double>>;
template class PureXCQuantities<double, type::canonical_space_t<double>>;
template class PureXCQuantities<float>;
template class PureXCQuantities<float, type::derived_space_t<float>>;
template class PureXCQuantities<float, type::canonical_space_t<float>>;

template class HybridXCQuantities<double>;
template class HybridXCQuantities<double, type::derived_space_t<double>>;
template class HybridXCQuantities<double, type::canonical_space_t<double>>;
template class HybridXCQuantities<float>;
template class HybridXCQuantities<float, type::derived_space_t<float>>;
template class HybridXCQuantities<float, type::canonical_space_t<float>>;

template class DoubleHybridXCQuantities<double>;
template class DoubleHybridXCQuantities<double, type::derived_space_t<double>>;
template class DoubleHybridXCQuantities<double,
                                        type::canonical_space_t<double>>;
template class DoubleHybridXCQuantities<float>;
template class DoubleHybridXCQuantities<float, type::derived_space_t<float>>;
template class DoubleHybridXCQuantities<float, type::canonical_space_t<float>>;

} // namespace property_types

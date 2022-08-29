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

#pragma once
#include <cstddef>

/** @file ao_integrals_fwd.hpp
 *
 *  Forward declarations of the AO integrals types, primarily for template
 *  meta-programming.
 */

namespace property_types::ao_integrals {

template<typename T>
struct CorrelationFactor;

template<typename T>
struct DOI;

template<typename T>
struct ERI;

template<typename T, unsigned Order>
struct EMultipole;

template<typename T>
struct Kinetic;

template<std::size_t N, typename T>
struct NCenter;

template<typename T>
struct Nuclear;

template<typename T>
struct Overlap;

template<typename T>
struct STG;

template<typename T>
struct Yukawa;

} // namespace property_types::ao_integrals
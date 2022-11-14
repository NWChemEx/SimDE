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

#include <type_traits>

namespace simde {

template<typename T, typename U>
class Derivative;

namespace detail_ {

template<typename T>
struct IsDerivative : std::false_type {};

template<typename T, typename U>
struct IsDerivative<Derivative<T, U>> : std::true_type {};

template<typename T>
struct DerivativeOrder;

template<typename T, typename U>
struct DerivativeOrder<Derivative<T, U>> {
private:
    static constexpr std::size_t value_() {
        if constexpr(IsDerivative<T>::value) {
            return DerivativeOrder<T>::value() + 1;
        } else {
            return 1;
        }
    }

public:
    static constexpr auto value = value_();
};

} // namespace detail_

template<typename T>
static constexpr auto is_derivative_v = detail_::IsDerivative<T>::value;

template<typename T>
static constexpr auto derivative_order_v = detail_::DerivativeOrder<T>::value;

} // namespace simde

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
#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>
// Type of an initializer list filled with strings
using string_list = std::initializer_list<std::string>;

/**@brief Factors out the boilerplate required to test a property type
 *
 * @tparam T The type of the property type
 * @param input_fields An initializer list of the property type's input fields
 * @param result_fields An initializer list of the property type's returns
 */
template<typename T>
void test_property_type(string_list input_fields, string_list result_fields) {
    SECTION("inputs") {
        auto inputs = T::inputs();
        REQUIRE(inputs.size() == input_fields.size());
        for(const auto& field : input_fields) {
            REQUIRE(inputs.count(field) == 1);
        }
    }
    SECTION("results") {
        auto results = T::results();
        REQUIRE(results.size() == result_fields.size());
        for(const auto& field : result_fields) {
            REQUIRE(results.count(field) == 1);
        }
    }
}

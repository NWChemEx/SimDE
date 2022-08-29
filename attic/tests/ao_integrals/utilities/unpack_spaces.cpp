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

#include "../ao_integrals_test.hpp"
#include "property_types/ao_integrals/type_traits.hpp"
#include "property_types/ao_integrals/utilities/unpack_spaces.hpp"
#include <catch2/catch.hpp>

using namespace property_types;
using namespace ao_integrals;

namespace {

template<typename T>
auto generate_inputs() {
    sde::type::input_map inputs;
    using bs_t       = chemist::AOBasisSet<T>;
    using ao_space_t = type::ao_space_t<T>;
    bs_t bs0, bs1, bs2, bs3;
    chemist::Center<T> c0{0.0, 0.0, 1.0}, c1{0.0, 1.0, 0.0};
    bs1.add_center(c0);
    bs2.add_center(c1);
    bs3.add_center(c0);
    bs3.add_center(c1);
    inputs["bra"].set_type<ao_space_t>().change(ao_space_t{bs0});
    inputs["bra 1"].set_type<ao_space_t>().change(ao_space_t{bs0});
    inputs["bra 2"].set_type<ao_space_t>().change(ao_space_t{bs1});
    inputs["ket"].set_type<ao_space_t>().change(ao_space_t{bs2});
    inputs["ket 1"].set_type<ao_space_t>().change(ao_space_t{bs2});
    inputs["ket 2"].set_type<ao_space_t>().change(ao_space_t{bs3});
    return inputs;
}

} // namespace

TEMPLATE_LIST_TEST_CASE("unpack_spaces<2>", "", test::all_2c) {
    using element_type = double;
    using space_type   = type::ao_space_t<element_type>;
    auto inputs        = generate_inputs<element_type>();
    auto rv            = ao_integrals::unpack_spaces<TestType>(inputs);
    REQUIRE(rv.size() == 2);
    REQUIRE(rv[0] == inputs.at("bra").template value<space_type>());
    REQUIRE(rv[1] == inputs.at("ket").template value<space_type>());
}

TEMPLATE_LIST_TEST_CASE("unpack_spaces<3>", "", test::all_3c) {
    using element_type = double;
    using space_type   = type::ao_space_t<element_type>;
    auto inputs        = generate_inputs<element_type>();
    auto rv            = ao_integrals::unpack_spaces<TestType>(inputs);
    REQUIRE(rv.size() == 3);
    REQUIRE(rv[0] == inputs.at("bra").template value<space_type>());
    REQUIRE(rv[1] == inputs.at("ket 1").template value<space_type>());
    REQUIRE(rv[2] == inputs.at("ket 2").template value<space_type>());
}

TEMPLATE_LIST_TEST_CASE("unpack_spaces<4>", "", test::all_4c) {
    using element_type = double;
    using space_type   = type::ao_space_t<element_type>;
    auto inputs        = generate_inputs<element_type>();
    auto rv            = ao_integrals::unpack_spaces<TestType>(inputs);
    if constexpr(ao_integrals::is_doi_v<TestType>) {
        REQUIRE(rv.size() == 2);
        REQUIRE(rv[0] == inputs.at("bra").template value<space_type>());
        REQUIRE(rv[1] == inputs.at("ket").template value<space_type>());
    } else {
        REQUIRE(rv.size() == 4);
        REQUIRE(rv[0] == inputs.at("bra 1").template value<space_type>());
        REQUIRE(rv[1] == inputs.at("bra 2").template value<space_type>());
        REQUIRE(rv[2] == inputs.at("ket 1").template value<space_type>());
        REQUIRE(rv[3] == inputs.at("ket 2").template value<space_type>());
    }
}
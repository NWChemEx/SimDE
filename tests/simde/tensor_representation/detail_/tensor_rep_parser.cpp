#include "simde/tensor_representation/detail_/tensor_rep_parser.hpp"
#include <catch2/catch.hpp>

using namespace simde;

template<typename T>
using map_t = typename detail_::TensorRepTraits<T>::map_type;

template<typename T>
using tuple_t = typename std::tuple<const T&>;

/* Testing strategy:
 *
 * There are a lot of possible input tuples to contend with. This unit test does
 * not attempt to be exahustive. Rather we first test a single space at a time.
 * Even though this is a non-physical scenario, it allows us to ensure that
 * dispatch occurs correctly (i.e. the space shows up in the correct member).
 * After that we test a 2, 3, and 4 basis dispatch with different spaces, which
 * helps assert that recursion in `parse` works as it should.
 */

TEST_CASE("TensorRepParser") {
    type::ao_space aos;
    type::sparse_ao_space aos_i;
    type::derived_space mos;
    type::ind_derived_space mos_i;
    type::dep_derived_space paos_i;

    SECTION("One space") {
        SECTION("TensorRepParser(ao_space)") {
            using space_t = type::ao_space;
            tuple_t<space_t> t(aos);
            detail_::TensorRepParser p(t);
            REQUIRE(p.m_ao_spaces.size() == 1);
            REQUIRE(p.m_ao_spaces.count(0));
            REQUIRE(&p.m_ao_spaces.at(0).get() == &aos);
        }

        SECTION("TensorRepParser(sparse_ao_space)") {
            using space_t = type::sparse_ao_space;
            tuple_t<space_t> t(aos_i);
            detail_::TensorRepParser p(t);
            REQUIRE(p.m_sparse_ao_spaces.size() == 1);
            REQUIRE(p.m_sparse_ao_spaces.count(0));
            REQUIRE(&p.m_sparse_ao_spaces.at(0).get() == &aos_i);
        }

        SECTION("TensorRepParser(derived_space)") {
            using space_t = type::derived_space;
            tuple_t<space_t> t(mos);
            detail_::TensorRepParser p(t);
            REQUIRE(p.m_derived_spaces.size() == 1);
            REQUIRE(p.m_derived_spaces.count(0));
            REQUIRE(&p.m_derived_spaces.at(0).get() == &mos);
        }

        SECTION("TensorRepParser(ind_derived_space)") {
            using space_t = type::ind_derived_space;
            tuple_t<space_t> t(mos_i);
            detail_::TensorRepParser p(t);
            REQUIRE(p.m_ind_spaces.size() == 1);
            REQUIRE(p.m_ind_spaces.count(0));
            REQUIRE(&p.m_ind_spaces.at(0).get() == &mos_i);
        }

        SECTION("TensorRepParser(dep_derived_space)") {
            using space_t = type::dep_derived_space;
            tuple_t<space_t> t(paos_i);
            detail_::TensorRepParser p(t);
            REQUIRE(p.m_dep_spaces.size() == 1);
            REQUIRE(p.m_dep_spaces.count(0));
            REQUIRE(&p.m_dep_spaces.at(0).get() == &paos_i);
        }
    }

    SECTION("Two inputs") {
        using space1_t = type::ao_space;
        using space2_t = type::sparse_ao_space;

        std::tuple<const space1_t&, const space2_t&> t(aos, aos_i);
        detail_::TensorRepParser p(t);

        map_t<space1_t> corr1;
        corr1.emplace(0, std::cref(aos));

        map_t<space2_t> corr2;
        corr2.emplace(1, std::cref(aos_i));
        REQUIRE(corr1 == p.m_ao_spaces);
        REQUIRE(corr2 == p.m_sparse_ao_spaces);
    }

    SECTION("Three inputs") {
        using space1_t = type::ao_space;
        using space2_t = type::sparse_ao_space;
        using space3_t = type::ao_space;

        std::tuple<const space1_t&, const space2_t&, const space3_t&> t(
          aos, aos_i, aos);
        detail_::TensorRepParser p(t);

        map_t<space1_t> corr1;
        corr1.emplace(0, std::cref(aos));
        corr1.emplace(2, std::cref(aos));

        map_t<space2_t> corr2;
        corr2.emplace(1, std::cref(aos_i));
        REQUIRE(corr1 == p.m_ao_spaces);
        REQUIRE(corr2 == p.m_sparse_ao_spaces);
    }

    SECTION("Four inputs") {
        using space1_t = type::ao_space;
        using space2_t = type::sparse_ao_space;
        using space3_t = type::ao_space;
        using space4_t = type::sparse_ao_space;

        std::tuple<const space1_t&, const space2_t&, const space3_t&,
                   const space4_t&>
          t(aos, aos_i, aos, aos_i);
        detail_::TensorRepParser p(t);

        map_t<space1_t> corr1;
        corr1.emplace(0, std::cref(aos));
        corr1.emplace(2, std::cref(aos));

        map_t<space2_t> corr2;
        corr2.emplace(1, std::cref(aos_i));
        corr2.emplace(3, std::cref(aos_i));

        REQUIRE(corr1 == p.m_ao_spaces);
        REQUIRE(corr2 == p.m_sparse_ao_spaces);
    }
}

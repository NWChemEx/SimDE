/*
 * Copyright 2026 NWChemEx-Project
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

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <simde/uncertainty/uq_factory.hpp>
#include <type_traits>

using namespace simde;

namespace {

/// The center/radius used throughout; the radius is on the order of the error
/// the UQ-aware integral drivers actually see.
constexpr double center = 0.774606;
constexpr double radius = 0.0000010000000000;

/// All of the kinds, in the order they're declared (which is also the order
/// UQFactory::operator< sorts them in).
const std::vector<UQKind> all_kinds{UQKind::none, UQKind::uncertain,
                                    UQKind::interval, UQKind::affine,
                                    UQKind::thresholded_affine};

} // namespace

TEST_CASE("uq_kind_from_string") {
    SECTION("Valid names") {
        REQUIRE(uq_kind_from_string("none") == UQKind::none);
        REQUIRE(uq_kind_from_string("uncertain") == UQKind::uncertain);
        REQUIRE(uq_kind_from_string("interval") == UQKind::interval);
        REQUIRE(uq_kind_from_string("affine") == UQKind::affine);
        REQUIRE(uq_kind_from_string("thresholded affine") ==
                UQKind::thresholded_affine);
    }

    SECTION("Invalid names throw") {
        REQUIRE_THROWS_AS(uq_kind_from_string("not a uq type"),
                          std::runtime_error);
        REQUIRE_THROWS_AS(uq_kind_from_string(""), std::runtime_error);

        // The mapping is case- and spelling-sensitive.
        REQUIRE_THROWS_AS(uq_kind_from_string("Uncertain"), std::runtime_error);
        REQUIRE_THROWS_AS(uq_kind_from_string("thresholded_affine"),
                          std::runtime_error);

        // Taylor models are not supported yet
        REQUIRE_THROWS_AS(uq_kind_from_string("taylor model"),
                          std::runtime_error);
    }
}

TEST_CASE("to_string(UQKind)") {
    SECTION("Each kind") {
        REQUIRE(to_string(UQKind::none) == "none");
        REQUIRE(to_string(UQKind::uncertain) == "uncertain");
        REQUIRE(to_string(UQKind::interval) == "interval");
        REQUIRE(to_string(UQKind::affine) == "affine");
        REQUIRE(to_string(UQKind::thresholded_affine) == "thresholded affine");
    }

    SECTION("Is the inverse of uq_kind_from_string") {
        for(auto kind : all_kinds)
            REQUIRE(uq_kind_from_string(to_string(kind)) == kind);
    }
}

TEST_CASE("UQFactory") {
    UQFactory defaulted;
    UQFactory none(UQKind::none);
    UQFactory uncertain(UQKind::uncertain);
    UQFactory interval(UQKind::interval);
    UQFactory affine(UQKind::affine);
    UQFactory taffine(UQKind::thresholded_affine);

    SECTION("Default ctor") { REQUIRE(defaulted.kind() == UQKind::uncertain); }

    SECTION("Value ctor") {
        for(auto kind : all_kinds) REQUIRE(UQFactory(kind).kind() == kind);
    }

    SECTION("Copy ctor") {
        UQFactory copy(taffine);
        REQUIRE(copy == taffine);
        REQUIRE(copy.kind() == UQKind::thresholded_affine);
    }

    SECTION("Copy assignment") {
        UQFactory copy;
        copy = interval;
        REQUIRE(copy == interval);
    }

// Sigma provides the UQ representations; without it TensorWrapper's UQ types
// are plain doubles that carry no bounds, leaving nothing here to check.
#ifdef ENABLE_SIGMA
    SECTION("operator()") {
        using tensorwrapper::types::uq_center;
        using tensorwrapper::types::uq_lower;
        using tensorwrapper::types::uq_upper;

        SECTION("none") {
            auto erased = none(center, radius);
            REQUIRE(wtf::fp::float_cast<double>(erased) == center);
        }

        SECTION("uncertain") {
            auto erased = uncertain(center, radius);
            auto value =
              wtf::fp::float_cast<tensorwrapper::types::uncertain_type<double>>(
                erased);
            REQUIRE(uq_center(value) == Catch::Approx(center));
            REQUIRE(value.sd() == Catch::Approx(radius));
        }

        SECTION("interval") {
            auto erased = interval(center, radius);
            auto value =
              wtf::fp::float_cast<tensorwrapper::types::interval_type<double>>(
                erased);
            REQUIRE(uq_lower(value) == Catch::Approx(center - radius));
            REQUIRE(uq_upper(value) == Catch::Approx(center + radius));
        }

        SECTION("affine") {
            auto erased = affine(center, radius);
            auto value =
              wtf::fp::float_cast<tensorwrapper::types::affine_type<double>>(
                erased);
            REQUIRE(uq_center(value) == Catch::Approx(center));
            REQUIRE(uq_lower(value) == Catch::Approx(center - radius));
            REQUIRE(uq_upper(value) == Catch::Approx(center + radius));
        }

        SECTION("thresholded affine") {
            auto erased = taffine(center, radius);
            auto value  = wtf::fp::float_cast<
               tensorwrapper::types::thresholded_affine_type<double>>(erased);
            REQUIRE(uq_center(value) == Catch::Approx(center));
            REQUIRE(uq_lower(value) == Catch::Approx(center - radius));
            REQUIRE(uq_upper(value) == Catch::Approx(center + radius));
        }
    }
#endif

    SECTION("kind") {
        REQUIRE(defaulted.kind() == UQKind::uncertain);
        REQUIRE(none.kind() == UQKind::none);
        REQUIRE(interval.kind() == UQKind::interval);
    }

    SECTION("operator==") {
        SECTION("Same kind") {
            REQUIRE(defaulted == uncertain);
            REQUIRE(interval == UQFactory(UQKind::interval));
            REQUIRE(affine == UQFactory(UQKind::affine));
            REQUIRE(taffine == UQFactory(UQKind::thresholded_affine));
        }

        SECTION("Different kinds") {
            for(auto lhs : all_kinds) {
                for(auto rhs : all_kinds) {
                    if(lhs == rhs) continue;
                    REQUIRE_FALSE(UQFactory(lhs) == UQFactory(rhs));
                }
            }
        }
    }

    SECTION("operator<") {
        SECTION("Orders by kind") {
            for(std::size_t i = 0; i < all_kinds.size(); ++i) {
                for(std::size_t j = 0; j < all_kinds.size(); ++j) {
                    UQFactory lhs(all_kinds[i]), rhs(all_kinds[j]);
                    REQUIRE((lhs < rhs) == (i < j));
                }
            }
        }

        SECTION("Irreflexive") {
            for(auto kind : all_kinds) {
                UQFactory factory(kind);
                REQUIRE_FALSE(factory < factory);
            }
        }
    }
}

TEST_CASE("UQFactoryBase") {
    detail::NoneFactoryImpl none;
    detail::UncertainFactoryImpl uncertain;
    detail::IntervalFactoryImpl interval;

    SECTION("kind") {
        REQUIRE(none.kind() == UQKind::none);
        REQUIRE(uncertain.kind() == UQKind::uncertain);
        REQUIRE(interval.kind() == UQKind::interval);
        REQUIRE(detail::AffineFactoryImpl{}.kind() == UQKind::affine);
        REQUIRE(detail::ThresholdedAffineFactoryImpl{}.kind() ==
                UQKind::thresholded_affine);
    }

    SECTION("clone") {
        auto pcopy = interval.clone();
        REQUIRE(pcopy.get() != &interval); // Deep, not shallow
        REQUIRE(pcopy->kind() == UQKind::interval);
        REQUIRE(pcopy->equal(interval));
    }

    SECTION("equal") {
        REQUIRE(uncertain.equal(detail::UncertainFactoryImpl{}));
        REQUIRE_FALSE(uncertain.equal(interval));
    }

    SECTION("less") {
        REQUIRE(none.less(uncertain));
        REQUIRE(uncertain.less(interval));
        REQUIRE_FALSE(interval.less(uncertain));
        REQUIRE_FALSE(interval.less(interval));
    }
}

TEST_CASE("visit_uq_kind") {
    using namespace tensorwrapper::types;

    // Returns true if visit_uq_kind passes the type T for kind
    auto passes = []<typename T>(UQKind kind, std::type_identity<T>) {
        return visit_uq_kind(kind, [](auto type) {
            return std::is_same_v<typename decltype(type)::type, T>;
        });
    };

    REQUIRE(passes(UQKind::none, std::type_identity<double>{}));
    REQUIRE(
      passes(UQKind::uncertain, std::type_identity<uncertain_type<double>>{}));
    REQUIRE(
      passes(UQKind::interval, std::type_identity<interval_type<double>>{}));
    REQUIRE(passes(UQKind::affine, std::type_identity<affine_type<double>>{}));
    REQUIRE(passes(UQKind::thresholded_affine,
                   std::type_identity<thresholded_affine_type<double>>{}));

    SECTION("FloatType") {
        auto is_float = visit_uq_kind<float>(UQKind::none, [](auto type) {
            return std::is_same_v<typename decltype(type)::type, float>;
        });
        REQUIRE(is_float);
    }
}

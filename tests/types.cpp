#include <catch2/catch.hpp>
#include <property_types/types.hpp>

TEST_CASE("Compare two TAMM tensors") {
    property_types::type::tensor<double> A, B;
    REQUIRE_FALSE(A == B);
}

TEST_CASE("Hash a TAMM tensor") {
    sde::Hasher h(bphash::HashType::Hash128);
    property_types::type::tensor<double> A;
    h(A);
}

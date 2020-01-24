#include <catch2/catch.hpp>
#include <property_types/types.hpp>

TEST_CASE("Hash a TAMM tensor") {
    sde::Hasher h(bphash::HashType::Hash128);
    property_types::type::tensor<double> A;
    //h(A);
    hash_object(A,h);
}

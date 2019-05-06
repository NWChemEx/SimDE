#include <property_types/k.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("K"){
    SECTION("Inputs") {
        auto inputs = K<>::inputs();
        for(auto fields : {"Molecule", "Molecular Orbitals", "Bra", "Ket",
                           "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = K<>::results();
        for(auto fields : {"K Matrix"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

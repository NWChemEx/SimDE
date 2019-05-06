#include <property_types/j.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("J"){
    SECTION("Inputs") {
        auto inputs = J<>::inputs();
        for(auto fields : {"Molecule", "Molecular Orbitals", "Bra", "Ket",
                           "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = J<>::results();
        for(auto fields : {"J Matrix"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

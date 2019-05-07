#include <property_types/xc_quantities.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("XCQuantities"){
    SECTION("Inputs") {
        auto inputs = XCQuantities<>::inputs();
        for(auto fields : {"Molecule", "Molecular Orbitals" "Bra", "Ket", "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = XCQuantities<>::results();
        for(auto fields : {"VXC Matrix", "EXC Energy"})
            SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}


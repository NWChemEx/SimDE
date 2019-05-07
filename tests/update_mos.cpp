#include <property_types/update_mos.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("UpdateMOs"){
    SECTION("Inputs") {
        auto inputs = UpdateGuess<>::inputs();
        for(auto fields : {"Molecule", "Basis Set", "Fock Matrix", "Previous OrbitalSpace"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = UpdateGuess<>::results();
        for(auto fields : {"Orbital Space"})
            SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}


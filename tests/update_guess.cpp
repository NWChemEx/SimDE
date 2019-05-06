#include <property_types/update_guess.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("UpdateGuess"){
    SECTION("Inputs") {
        auto inputs = UpdateGuess<>::inputs();
        for(auto fields : {"Molecule", "Basis Set", "Fock Matrix"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = UpdateGuess<>::results();
        for(auto fields : {"Orbital Space"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

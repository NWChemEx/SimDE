#include <property_types/guess_density.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("GuessDensity"){
    SECTION("Inputs") {
        auto inputs = GuessDensity<>::inputs();
        for(auto fields : {"Molecule", "Basis Set"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = GuessDensity<>::results();
        for(auto fields : {"Orbital Space"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

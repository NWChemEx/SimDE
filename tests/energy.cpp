#include <property_types/energy.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("Energy"){
    SECTION("Inputs") {
        auto inputs = Energy<>::inputs();
        for(auto fields : {"Molecule", "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = Energy<>::results();
        for(auto fields : {"Energy"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

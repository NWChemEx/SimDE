#include <property_types/aointegral.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("AOIntegral"){
    SECTION("Inputs") {
        auto inputs = AOIntegral<2>::inputs();
        for(auto fields : {"Molecule", "Basis Sets", "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = AOIntegral<2>::results();
        for(auto fields : {"AO Integrals"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

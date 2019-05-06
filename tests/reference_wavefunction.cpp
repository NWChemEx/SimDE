#include <property_types/reference_wavefunction.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("ReferenceWavefunction"){
    SECTION("Inputs") {
        auto inputs = ReferenceWavefunction<>::inputs();
        for(auto fields : {"Molecule", "Basis Set", "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = ReferenceWavefunction<>::results();
        for(auto fields : {"Energy", "Orbital Space"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

#include <property_types/core_hamiltonian.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("CoreHamiltonian"){
    SECTION("Inputs") {
        auto inputs = CoreHamiltonian<>::inputs();
        for(auto fields : {"Molecule", "Bra", "Ket", "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = CoreHamiltonian<>::results();
        for(auto fields : {"Core Hamiltonian"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

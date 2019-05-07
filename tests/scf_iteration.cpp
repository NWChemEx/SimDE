#include <property_types/scf_iteration.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("SCFIteration"){
    SECTION("Inputs") {
        auto inputs = SCFIteration<>::inputs();
        for(auto fields : {"Molecule", "Molecular Orbitals", "Bra", "Ket", "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = SCFIteration<>::results();
        for(auto fields : {"Fock Matrix", "Electronic Energy"})
            SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}
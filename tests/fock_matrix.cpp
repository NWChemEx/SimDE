#include <property_types/fock_matrix.hpp>
#include <catch2/catch.hpp>

using namespace property_types;

TEST_CASE("FockMatrix"){
    SECTION("Inputs") {
        auto inputs = FockMatrix<>::inputs();
        for(auto fields : {"Molecule", "Molecular Orbitals", "Bra", "Ket",
                           "Derivative"})
            SECTION(fields){ REQUIRE(inputs.count(fields) == 1); }
    }
    SECTION("Results") {
        auto outputs = FockMatrix<>::results();
        for(auto fields : {"Fock Matrix"})
        SECTION(fields){ REQUIRE(outputs.count(fields) == 1); }
    }
}

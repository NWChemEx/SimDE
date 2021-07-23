#include "../test_property_type.hpp"
#include "simde/density/guess_density.hpp"

TEST_CASE("GuessDensity") {
    test_property_type<simde::GuessDensity>({"System Hamiltonian", "Basis Set"},
                                            {"Initial density"});
}

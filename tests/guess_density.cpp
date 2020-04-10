#include "test_property_type.hpp"
#include <property_types/guess_density.hpp>

TEST_CASE("GuessDensity"){
    test_property_type<property_types::GuessDensity<>>(
    {"Molecule", "Basis Set"}, {"Molecular Orbitals"});
}

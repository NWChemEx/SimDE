#include "../test_property_type.hpp"
#include "simde/wavefunctions/reference_wavefunction.hpp"

using namespace simde;

TEST_CASE("ReferenceWavefunction") {
    test_property_type<ReferenceWavefunction<type::canonical_space>>(
      {"Molecule", "Basis Set", "Derivative"},
      {"Energy", "Molecular Orbitals"});
}

#include "test_property_type.hpp"
#include <property_types/reference_wavefunction.hpp>

TEST_CASE("ReferenceWavefunction"){
    test_property_type<property_types::ReferenceWavefunction<>>(
      {"Molecule", "Basis Set", "Derivative"},{"Energy", "Orbital Space"}
    );
}

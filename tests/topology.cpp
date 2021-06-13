#include "property_types/topology.hpp"
#include "test_property_type.hpp"

TEST_CASE("Topology") {
    test_property_type<property_types::MolecularTopology>({"Molecule"},
                                                          {"Topology"});
}
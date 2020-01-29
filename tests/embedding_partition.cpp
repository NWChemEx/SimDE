#include "test_property_type.hpp"
#include <property_types/embedding_partition.hpp>

TEST_CASE("EmbedPartition") {
    test_property_type<property_types::EmbedPartition<>>(
      {"Molecule", "Basis Set", "Active Atoms", "Initial OrbitalSpace"},
      {"N Active MOs", "Orbital Space"});
}

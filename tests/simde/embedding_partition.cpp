/*
 * Copyright 2022 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "simde/embedding_partition.hpp"
#include "test_property_type.hpp"

using namespace simde;

TEST_CASE("EmbedPartition") {
    test_property_type<EmbedPartition<type::canonical_space>>(
      {"Molecule", "Basis Set", "Active Atoms", "Initial Orbitals"},
      {"Active Orbitals", "Environment Orbitals"});
}

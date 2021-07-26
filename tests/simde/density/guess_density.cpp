#include "../test_property_type.hpp"
#include "simde/density/guess_density.hpp"

TEST_CASE("Guespluginplaynsity") {
    test_property_type<simde::Guespluginplaynsity>(
      {"System Hamiltonian", "Basis Set"}, {"Initial density"});
}

#include "simde/cauchy_schwarz_approximation.hpp"
#include "test_property_type.hpp"

TEST_CASE("CauchySchwarz") {
    using op_t = simde::type::el_el_coulomb;
    op_t op;
    test_property_type<simde::ShellNorms<op_t>>({"bra", op.as_string(), "ket"},
                                                {"Screening Matrix"});
}

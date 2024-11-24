#include "../test_property_type.hpp"
#include <simde/simde.hpp>

using namespace simde;

TEST_CASE("Optimize<ESCF, rscf_wf>") {
    using pt2opt  = ESCF<type::cmos>;
    using wrt     = type::rscf_wf;
    using pt      = Optimize<pt2opt, wrt>;
    auto inp_desc = "Object to optimize the objective function with respect to";
    auto out_desc = "Object that optimizes the objective function";
    test_property_type<pt>({"BraKet", inp_desc},
                           {"tensor representation", out_desc});
}
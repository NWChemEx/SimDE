#include "mo_charges.hpp"

namespace property_types {

    template class MOCharges<double>;
    template class MOCharges<double, type::orthogonal_orbs<double>>;
    template class MOCharges<double, type::canonical_mos<double>>;
    template class MOCharges<float>;
    template class MOCharges<float,  type::orthogonal_orbs<float>>;
    template class MOCharges<float,  type::canonical_mos<float>>;

} // namespace property_types
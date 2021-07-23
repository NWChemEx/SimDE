#pragma once
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {
/** @brief The property type for modules that compute an orbital energy
 *  denominator.
 *
 *  As defined this class is suitable for use with pair theories.
 *
 *  @tparam OccType The type of the occupied orbital space.
 *  @tparam VirtType The type of the virtual orbital space.
 */
template<typename OccType, typename VirtType>
DECLARE_TEMPLATED_PROPERTY_TYPE(EnergyDenominator_, OccType, VirtType);

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_INPUTS(EnergyDenominator_, OccType, VirtType) {
    auto rv = sde::declare_input()
                .add_field<const OccType&>("Occupieds")
                .template add_field<const VirtType&>("Virtuals");
    return rv;
}

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_RESULTS(EnergyDenominator_, OccType, VirtType) {
    using tensor_type = std::decay_t<decltype(std::declval<VirtType>().C())>;
    auto rv           = sde::declare_result().add_field<tensor_type>(
      "-1/(e_a + e_b - e_i - e_j)");
    return rv;
}

template<typename T>
using EnergyDenominator =
  EnergyDenominator_<type::canonical_space_t<T>, type::canonical_space_t<T>>;

} // namespace simde

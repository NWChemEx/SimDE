#pragma once

namespace simde {

/** @brief The property type for modules that compute a pair energy.
 *
 *  @tparam OccType The type of the occupied orbital energies.
 *  @tparam VirtType The type of the virtual orbital energies.
 */
template<typename OccType, typename VirtType>
DECLARE_TEMPLATED_PROPERTY_TYPE(PairEnergy, OccType, VirtType);

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_INPUTS(PairEnergy, OccType, VirtType) {
    auto rv = sde::declare_input()
                .add_field<const OccType&>("Occupieds")
                .template add_field<const VirtType&>("Virtuals");
    return rv;
}

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_RESULTS(PairEnergy, OccType, VirtType) {
    using tensor_type =
      std::decay_t<decltype(std::declval<OccType>().orbital_energies())>;
    auto rv = sde::declare_result().add_field<tensor_type>("Pair Energies");
    return rv;
}

} // namespace simde

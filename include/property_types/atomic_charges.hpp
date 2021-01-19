#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that calculate atomic charges.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 * @tparam OrbitalType The type of the input orbital space
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbitals<ElementType>>
struct AtomicCharges
  : public sde::PropertyType<AtomicCharges<ElementType, OrbitalType>> {
    /// Type of the return values
    using return_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class AtomicCharges

//---------------------------Implementations------------------------------------
template<typename ElementType, typename OrbitalType>
auto AtomicCharges<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto AtomicCharges<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result().add_field<return_type>("Partial Charges");
    rv["Partial Charges"].set_description("The calculated partial charges");
    return rv;
}

extern template class AtomicCharges<double>;
extern template class AtomicCharges<double, type::orthogonal_orbs<double>>;
extern template class AtomicCharges<double, type::canonical_mos<double>>;
extern template class AtomicCharges<float>;
extern template class AtomicCharges<float, type::orthogonal_orbs<float>>;
extern template class AtomicCharges<float, type::canonical_mos<float>>;

} // namespace property_types

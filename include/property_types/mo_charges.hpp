#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that calculate MO charges.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 * @tparam OrbitalType The type of the input molecular orbitals
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbital_space_t<ElementType>>
struct MOCharges
  : public sde::PropertyType<MOCharges<ElementType, OrbitalType>> {
    /// Type of the returned tensor that accounts for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class MOCharges

//---------------------------Implementations------------------------------------
template<typename ElementType, typename OrbitalType>
auto MOCharges<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto MOCharges<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("MO Charges");
    rv["MO Charges"].set_description("The calculated MO charge densities");
    return rv;
}

extern template class MOCharges<double>;
extern template class MOCharges<double, type::derived_space_t<double>>;
extern template class MOCharges<double, type::canonical_space_t<double>>;
extern template class MOCharges<float>;
extern template class MOCharges<float, type::derived_space_t<float>>;
extern template class MOCharges<float, type::canonical_space_t<float>>;

} // namespace property_types

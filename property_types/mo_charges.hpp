#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that calculate MO charges.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 */
    template<typename ElementType = double>
    struct MOCharges : public sde::PropertyType<MOCharges<ElementType>> {
        /// Type of the MOs that accounts for ElementType
        using orbital_type = type::orbitals<ElementType>;
        /// Type of the returned tensor that accounts for ElementType
        using tensor_type = type::tensor<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class MOCharges

//---------------------------Implementations------------------------------------
    template<typename ElementType>
    auto MOCharges<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const orbital_type&>("Molecular Orbitals");
        rv["Molecule"].set_description("The molecular system");
        rv["Molecular Orbitals"].set_description("The molecular orbitals");
        return rv;
    }

    template<typename ElementType>
    auto MOCharges<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<tensor_type>("MO Charges");
        rv["MO Charges"].set_description("The calculated MO charge densities");
        return rv;
    }

    extern template class MOCharges<double>;
    extern template class MOCharges<float>;

} // namespace property_types

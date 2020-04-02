#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that calculate partial charges.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 */
    template<typename ElementType = double>
    struct PartialCharges : public sde::PropertyType<PartialCharges<ElementType>> {
        /// Type of the MOs that accounts for ElementType
        using orbital_type = type::orbitals<ElementType>;
        /// Type of the return values
        using return_type = std::vector<ElementType>;
        /// Generates the input fields required by this property type
        auto inputs_();
        /// Generates the result fields required by this property type
        auto results_();
    }; // class CoreHamiltonian

//---------------------------Implementations------------------------------------
    template<typename ElementType>
    auto PartialCharges<ElementType>::inputs_() {
        auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const orbital_type&>("Molecular Orbitals");
        rv["Molecule"].set_description("The molecular system");
        rv["Molecular Orbitals"].set_description("The molecular orbitals");
        return rv;
    }

    template<typename ElementType>
    auto PartialCharges<ElementType>::results_() {
        auto rv = sde::declare_result().add_field<return_type>("Partial Charges");
        rv["Partial Charges"].set_description("The calculated partial charges");
        return rv;
    }

    extern template class PartialCharges<double>;
    extern template class PartialCharges<float>;

} // namespace property_types

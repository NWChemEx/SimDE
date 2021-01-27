#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief The property type for modules that compute electronic energies and
 *  build Fock matrices in the AO basis set.
 *
 *  The Fock matrix (or Kohn-Sham matrix for DFT) is an effective one-electron
 *  potential. Modules that satisfy this property type are capable of computing
 *  the Fock matrix in the AO basis set as well as the electronic energy of the
 *  system.
 *
 *  @tparam ElementType The type of the elements in the returned tensors.
 *  @tparam OrbitalType The type of the input orbital space
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbital_space_t<ElementType>>
struct SCFIteration
  : public sde::PropertyType<SCFIteration<ElementType, OrbitalType>> {
    /// Type of the returned tensor that accounts for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class SCFIteration

//-------------------------------------Implementations--------------------------

template<typename ElementType, typename OrbitalType>
auto SCFIteration<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals")
                .template add_field<const type::ao_space_t<ElementType>&>("Bra")
                .template add_field<const type::ao_space_t<ElementType>&>("Ket")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    rv["Bra"].set_description("The basis set used for the bra");
    rv["Ket"].set_description("The basis set used for the ket");
    rv["Derivative"].set_description("The derivative order to compute");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto SCFIteration<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result()
                .add_field<tensor_type>("Fock Matrix")
                .template add_field<ElementType>("Electronic Energy");
    rv["Fock Matrix"].set_description("The computed Fock Matrix");
    rv["Electronic Energy"].set_description("The computed electronic energy");
    return rv;
}

extern template class SCFIteration<double>;
extern template class SCFIteration<double, type::derived_space_t<double>>;
extern template class SCFIteration<double, type::canonical_space_t<double>>;
extern template class SCFIteration<float>;
extern template class SCFIteration<float, type::derived_space_t<float>>;
extern template class SCFIteration<float, type::canonical_space_t<float>>;
} // namespace property_types

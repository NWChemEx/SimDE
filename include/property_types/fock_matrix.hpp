#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief The property type for modules that build Fock matrices in the AO
 *  basis set.
 *
 *  The Fock matrix (or Kohn-Sham matrix for DFT) is an effective one-electron
 *  potential. Modules that satisfy this property type are capable of computing
 *  the Fock matrix in the AO basis set.
 *
 *  @tparam ElementType The type of the elements in the returned tensor.
 *  @tparam OrbitalType The type of the input orbital space
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbital_space_t<ElementType>>
struct FockMatrix
  : public sde::PropertyType<FockMatrix<ElementType, OrbitalType>> {
    /// Type of the returned tensor that accounts for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class FockMatrix

//-------------------------------------Implementations--------------------------

template<typename ElementType, typename OrbitalType>
auto FockMatrix<ElementType, OrbitalType>::inputs_() {
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
auto FockMatrix<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("Fock Matrix");
    rv["Fock Matrix"].set_description("The computed Fock Matrix");
    return rv;
}

extern template class FockMatrix<double>;
extern template class FockMatrix<double, type::derived_space_t<double>>;
extern template class FockMatrix<double, type::canonical_space_t<double>>;
extern template class FockMatrix<float>;
extern template class FockMatrix<float, type::derived_space_t<float>>;
extern template class FockMatrix<float, type::canonical_space_t<float>>;

} // namespace property_types
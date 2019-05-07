#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

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
 */
    template<typename ElementType = double>
    struct SCFIteration : public SDE::PropertyType<SCFIteration<ElementType>> {
        ///Type of the returned tensor that accounts for ElementType
        using tensor_type  = type::tensor<ElementType>;
        ///Type of the MOs that accounts for ElementType
        using orbital_type = type::orbitals<ElementType>;
        ///Generates the input fields required by this property type
        auto inputs_();
        ///Generates the result fields required by this property type
        auto results_();
    }; //class SCFIteration

//-------------------------------------Implementations--------------------------

    template<typename ElementType>
    auto SCFIteration<ElementType>::inputs_() {
        auto rv = SDE::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const orbital_type&>("Molecular Orbitals")
                .template add_field<const type::basis_set&>("Bra")
                .template add_field<const type::basis_set&>("Ket")
                .template add_field<type::size>("Derivative");
        rv["Molecule"].set_description("The molecular system");
        rv["Molecular Orbitals"].set_description("The molecular orbitals");
        rv["Bra"].set_description("The basis set used for the bra");
        rv["Ket"].set_description("The basis set used for the ket");
        rv["Derivative"].set_description("The derivative order to compute");
        return rv;
    }

    template<typename ElementType>
    auto SCFIteration<ElementType>::results_() {
        auto rv = SDE::declare_result().add_field<tensor_type>("Fock Matrix")
                .template add_field<tensor_type>("Electronic Energy");
        rv["Fock Matrix"].set_description("The computed Fock Matrix");
        rv["Electronic Energy"].set_description("The computed electronic energy");
        return rv;
    }

} //namespace property_types

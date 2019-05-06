#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/** @brief The property type for modules that build the Coulomb matrix, which is
 *  canonically denoted @f$\mathbf{J}@f$.
 *
 *  While the canonical algorithms for building @f$\mathbf{J}@f$ and
 *  @f$\mathbf{K}@f$ usually have them being built together to avoid recomputing
 *  integrals, modern algorithms often build the two by relying on very
 *  different procedures. This property type is for modules that build
 *  @f$\mathbf{J}@f$. The same module may also build @f$\mathbf{K}@f$, in which
 *  case it should register itself as satisfying both property types and rely
 *  on memoization for "computing" @f$\mathbf{K}@f$.
 *
 *  @tparam ElementType The type of the elements in the returned tensor.
 */
template<typename ElementType = double>
struct J : public SDE::PropertyType<J<ElementType>> {
    ///Type of the MOs that accounts for ElementType
    using orbital_type = type::orbitals<ElementType>;
    ///Type of the returned tesnor that accounts for ElementType
    using tensor_type = type::tensor<ElementType>;
    ///Generates the input fields required by this property type
    auto inputs_();
    ///Generates the result fields required by this property type
    auto results_();
}; //class J

//-----------------------------Implementations----------------------------------

template<typename ElementType>
auto J<ElementType>::inputs_() {
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
    rv["Derivative"].set_description("The derivative order");
    return rv;
}

template<typename ElementType>
auto J<ElementType>::results_() {
    auto rv = SDE::declare_result().add_field<tensor_type>("J Matrix");
    rv["J Matrix"].set_description("The computed J Matrix");
    return rv;
}

} //namespace property_types

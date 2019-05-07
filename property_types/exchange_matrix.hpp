#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/** @brief The property type for modules that build the exchange matrix, which
 *         is canonically denoted @f$\mathbf{K}@f$.
 *
 *  While the canonical algorithms for building @f$\mathbf{J}@f$ and
 *  @f$\mathbf{K}@f$ usually have them being built together to avoid recomputing
 *  integrals, modern algorithms often build the two by relying on very
 *  different procedures. This property type is for modules that build
 *  @f$\mathbf{K}@f$. The same module may also build @f$\mathbf{J}@f$, in which
 *  case it should register itself as satisfying both property types and rely
 *  on memoization for "computing" @f$\mathbf{J}@f$.
 *
 *  @tparam ElementType The type of the elements in the returned tensor.
 */
template<typename ElementType = double>
struct ExchangeMatrix : SDE::PropertyType<ExchangeMatrix<ElementType>> {
    ///Typedef for the MOs that accounts for ElementType
    using orbital_type = type::orbitals<ElementType>;
    ///Typedef for the returned tensor that accounts for ElementType
    using tensor_type = type::tensor<ElementType>;
    ///Generates the input fields required by this property type
    auto inputs_();
    ///Generates the result fields required by this property type
    auto results_();
}; //class K

//-----------------------------Implementations----------------------------------

template<typename ElementType>
auto ExchangeMatrix<ElementType>::inputs_() {
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
auto ExchangeMatrix<ElementType>::results_() {
    auto rv = SDE::declare_result().add_field<tensor_type>("Exchange Matrix");
    rv["Exchange Matrix"].set_description("The computed exchange matrix");
    return rv;
}

} //namespace property_types
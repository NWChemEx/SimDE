#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

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
 *  @tparam OrbitalType The type of the input orbital space
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbitals<ElementType>>
struct CoulombMatrix
  : public sde::PropertyType<CoulombMatrix<ElementType, OrbitalType>> {
    /// Type of the returned tesnor that accounts for ElementType
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class J

//-----------------------------Implementations----------------------------------

template<typename ElementType, typename OrbitalType>
auto CoulombMatrix<ElementType, OrbitalType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals")
                .template add_field<const type::basis_set<ElementType>&>("Bra")
                .template add_field<const type::basis_set<ElementType>&>("Ket")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    rv["Bra"].set_description("The basis set used for the bra");
    rv["Ket"].set_description("The basis set used for the ket");
    rv["Derivative"].set_description("The derivative order");
    return rv;
}

template<typename ElementType, typename OrbitalType>
auto CoulombMatrix<ElementType, OrbitalType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>("Coulomb Matrix");
    rv["Coulomb Matrix"].set_description("The computed Coulomb matrix");
    return rv;
}

extern template class CoulombMatrix<double>;
extern template class CoulombMatrix<double, type::orthogonal_orbs<double>>;
extern template class CoulombMatrix<double, type::canonical_mos<double>>;
extern template class CoulombMatrix<float>;
extern template class CoulombMatrix<float, type::orthogonal_orbs<float>>;
extern template class CoulombMatrix<float, type::canonical_mos<float>>;

} // namespace property_types

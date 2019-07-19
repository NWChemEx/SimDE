#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types::integrals {

/** @brief Computes a multipole moment in the AO basis set.
 *
 *  This property type computes integrals of the form
 *  @f$\left\lbrace\mu\middle\mid\vec{r}^n \middle\mid\nu\right\rangle@f$ where
 *  @f$\left\mid\mu\right\rangle$ is an AO basis function, @f$\vec{r}@f$ is the
 *  distance to the origin of the multipole expansion, and @f$n@f$ is the
 *  multipole moment's order.
 *
 * @tparam order The multipole moment order to compute.
 * @tparam ElementType The type to use for storing the tensor's elements
 */
template<std::size_t order, typename ElementType = double>
struct Multipole : sde::PropertyType<Multipole<order, ElementType>> {
    auto inputs_();
    auto results_();
};

template<typename ElementType>
using Dipole = Multipole<1, ElementType>;

template<typename ElementType>
using Quadrupole = Multipole<2, ElementType>;

template<typename ElementType>
using Octopole = Multipole<3, ElementType>;

//------------------------------Implementations---------------------------------

template<std::size_t order, typename ElementType>
auto Multipole<order, ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const type::basis_set&>("Bra")
                .add_field<const type::basis_set&>("Ket")
                .add_field<const std::array<double, 3>>("Origin")
                .template add_field<type::size>("Derivative");

    rv["Molecule"].set_description("The molecular system");
    rv["Bra"].set_description("The basis set used for the bra");
    rv["Ket"].set_description("The basis set used for the ket");
    rv["Origin"].set_description("Origin of the multipole expansion");
    rv["Derivative"].set_description("The derivative order");
    return rv;
}

template<std::size_t order, typename ElementType>
auto Multipole<order, ElementType>::results_() {
    auto rv = sde::declare_result().add_field<tamm::Tensor<ElementType>>(
      "multipole moment");
    rv["multipole moment"].set_description(
      "The multipole moment in the AO basis");
    return rv;
}

extern template class Multipole<1, double>;
extern template class Multipole<2, double>;
extern template class Multipole<3, double>;

} // namespace property_types::integrals

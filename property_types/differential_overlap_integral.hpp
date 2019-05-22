#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

/** @brief API for modules that compute the differential overlap integral
 *
 *  The differential overlap integral (DOI) of two orbitals, @f$f@f$ and
 *  @f$g@f$,each expanded in terms of a set of AOs
 *  @f$\left\lbrace\phi\right\rbrace@f$ is given by:
 *  @f{equation}{
 *  DOI^2 = \sum_{\mu\nu\lambda\sigma}
 *          f_\mu f_\nu g_\lambda g_\sigma
 *          \int dr\phi_{\mu}(r)\phi_{\nu}(r)\phi_{\lambda}\phi_{\sigma},
 *  @f}
 *  where @f$f_\mu@f$ and @f$g_\lambda@f$ are the expansion coefficients.
 *
 *
 * @tparam ElementType The type of the elements in the returned tensor and
 *                     input orbital spaces.
 */
template<typename ElementType = double>
struct DifferentialOverlapIntegral
  : sde::PropertyType<DifferentialOverlapIntegral<ElementType>> {
    /// Type of the orbital spaces taken by this module
    using orbital_type = type::orbitals<ElementType>;
    /// Type of the tensor returned from this module
    using tensor_type = type::tensor<ElementType>;
    /// Generates the input fields required by the property type
    auto inputs_();
    /// Generates the result fields required by the property type
    auto results_();
}; // class DifferentialOverlapIntegral

//------------------------------------Implementations--------------------------

template<typename ElementType>
auto DifferentialOverlapIntegral<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const orbital_type&>("Orbital Space 1")
                .template add_field<const orbital_type&>("Orbital Space 2");
    rv["Molecule"].set_description(
      "The system for which we are computing the DOI");
    rv["Orbital Space 1"].set_description("The orbitals in the first space");
    rv["Orbital Space 2"].set_description("The orbitals in the second space");
    return rv;
}

template<typename ElementType>
auto DifferentialOverlapIntegral<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<tensor_type>(
      "Differential Overlap Integral");
    rv["Differential Overlap Integral"].set_description(
      "The DOIs between among the input orbitals");
    return rv;
}

extern template class DifferentialOverlapIntegral<double>;
extern template class DifferentialOverlapIntegral<float>;

} // namespace property_types

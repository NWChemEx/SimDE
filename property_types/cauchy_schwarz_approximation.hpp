#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

template<typename ElementType = double>
struct CauchySchwarzApprox
  : public sde::PropertyType<CauchySchwarzApprox<ElementType>> {
    /// The type of an std::array of basis sets
    using basis_type = type::basis_set<ElementType>;
    /// The return type
    using return_type = std::vector<std::vector<ElementType>>;
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
}; // class CauchySchwarzApprox

//------------------------Implementations---------------------------------------

template<typename ElementType>
auto CauchySchwarzApprox<ElementType>::inputs_() {
    auto rv = sde::declare_input()
                .add_field<const basis_type&>("Basis1")
                .template add_field<const basis_type&>("Basis2")
                .template add_field<type::size>("Derivative", type::size{0});
    rv["Basis1"].set_description("The first basis set");
    rv["Basis2"].set_description("The second basis set");
    rv["Derivative"].set_description(
      "The derivative order of integrals to be computed");
    return rv;
}

template<typename ElementType>
auto CauchySchwarzApprox<ElementType>::results_() {
    auto rv = sde::declare_result().add_field<return_type>("Screening Matrix");
    rv["Screening Matrix"].set_description(
      "The Cauchy Schwarz screening matrix");
    return rv;
}

extern template class CauchySchwarzApprox<double>;
extern template class CauchySchwarzApprox<float>;

} // namespace property_types
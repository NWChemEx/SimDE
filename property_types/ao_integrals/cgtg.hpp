#pragma once
#include "property_types/types.hpp"
#include <sde/property_type.hpp>

namespace property_types {

template<typename ElementType>
struct CGTGIntegral : public sde::PropertyType<CGTGIntegral<ElementType>> {
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
};

template<typename ElementType>
PROPERTY_TYPE_INPUTS(CGTGIntegral<ElementType>){
  using basis_type = libchemist::AOBasisSet<ElementType>;
  using param_type = std::vector<std::pair<ElementType, ElementType>>;
  auto rv = sde::declare_input()
              .add_field<const basis_type&>("Bra 1")
              .template add_field<const basis_type&>("Bra 2")
              .template add_field<const basis_type&>("Ket 1")
              .template add_field<const basis_type&>("Ket 2")
              .template add_field<const param_type&>("Params");
  rv["Bra 1"].set_description("Basis for i in (ij|f12|kl)");
  rv["Bra 2"].set_description("Basis for j in (ij|f12|kl)");
  rv["Ket 1"].set_description("Basis for k in (ij|f12|kl)");
  rv["Ket 2"].set_description("Basis for l in (ij|f12|kl)");
  rv["Params"]
    .set_description("Vector of coefficient-exponent pairs for the geminal");
  return rv;
}

template<typename ElementType>
PROPERTY_TYPE_RESULTS(CGTGIntegral<ElementType>){
  using tensor_type = TA::TSpArray<ElementType>;
  auto rv = sde::declare_result().add_field<tensor_type>("Integrals");
  rv["Integrals"].set_description("The integral (ij|f12|kl)");
  return rv;
}

template<typename ElementType>
struct CGTGTimesCoulombIntegral :
  public sde::PropertyType<CGTGTimesCoulombIntegral<ElementType>> {
    /// Generates the input fields required by this property type
    auto inputs_();
    /// Generates the result fields required by this property type
    auto results_();
};

template<typename ElementType>
PROPERTY_TYPE_INPUTS(CGTGTimesCoulombIntegral<ElementType>){
  using basis_type = libchemist::AOBasisSet<ElementType>;
  using param_type = std::vector<std::pair<ElementType, ElementType>>;
  auto rv = sde::declare_input()
  .add_field<const basis_type&>("Bra 1")
  .template add_field<const basis_type&>("Bra 2")
  .template add_field<const basis_type&>("Ket 1")
  .template add_field<const basis_type&>("Ket 2")
  .template add_field<const param_type&>("Params");
  rv["Bra 1"].set_description("Basis for i in (ij|f12/r12|kl)");
  rv["Bra 2"].set_description("Basis for j in (ij|f12/r12|kl)");
  rv["Ket 1"].set_description("Basis for k in (ij|f12/r12|kl)");
  rv["Ket 2"].set_description("Basis for l in (ij|f12/r12|kl)");
  rv["Params"]
  .set_description("Vector of coefficient-exponent pairs for the geminal");
  return rv;
}

template<typename ElementType>
PROPERTY_TYPE_RESULTS(CGTGTimesCoulombIntegral<ElementType>){
  using tensor_type = TA::TSpArray<ElementType>;
  auto rv = sde::declare_result().add_field<tensor_type>("Integrals");
  rv["Integrals"].set_description("The integral (ij|f12/r12|kl)");
  return rv;
}


extern template class CGTGIntegral<float>;
extern template class CGTGIntegral<double>;
extern template class CGTGTimesCoulombIntegral<float>;
extern template class CGTGTimesCoulombIntegral<double>;

} // namespace property_types

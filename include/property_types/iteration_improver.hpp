#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that use information across iterations
 *         to improve iterative tensor guesses.
 *
 *  @tparam TensorType the type of the tensors
 */
template<typename TensorType = type::tensor<double>>
DECLARE_TEMPLATED_PROPERTY_TYPE(IterationImprover, TensorType);

template<typename TensorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(IterationImprover, TensorType) {
    auto rv = sde::declare_input()
      .template add_field<const TensorType&>("Initial Tensor")
      .template add_field<const TensorType&>("Current Tensor")
      .template add_field<const TensorType&>("Error Tensor");
    rv["Initial Tensor"].set_description(
      "The initial version of the tensor");
    rv["Current Tensor"].set_description(
      "The version of the tensor from the current iteration");
    rv["Error Tensor"].set_description(
      "Error associated with the current tensor");
    return rv;
}

template<typename TensorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(IterationImprover, TensorType) {
    auto rv = sde::declare_result().template add_field<TensorType>(
      "Improved Tensor");
    rv["Improved Tensor"].set_description(
      "The improved tensor guess");
    return rv;
}

extern template class IterationImprover<type::tensor<double>>;
extern template class IterationImprover<type::tensor<float>>;
extern template class IterationImprover<type::tensor_of_tensors<double>>;
extern template class IterationImprover<type::tensor_of_tensors<float>>;

} // namespace property_types

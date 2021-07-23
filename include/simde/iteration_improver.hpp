#pragma once
#include "simde/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace simde {

/** @brief Property type for modules that use information across iterations
 *         to improve iterative tensor guesses.
 *
 *  @tparam TensorType the type of the tensors
 */
template<typename TensorType = type::tensor>
DECLARE_TEMPLATED_PROPERTY_TYPE(IterationImprover, TensorType);

template<typename TensorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(IterationImprover, TensorType) {
    auto rv = sde::declare_input()
                .template add_field<const TensorType&>("Initial Tensor")
                .template add_field<const TensorType&>("Current Tensor")
                .template add_field<const TensorType&>("Initial Error Tensor")
                .template add_field<const TensorType&>("Current Error Tensor");
    rv["Initial Tensor"].set_description("The initial version of the tensor");
    rv["Current Tensor"].set_description(
      "The version of the tensor from the current iteration");
    rv["Initial Error Tensor"].set_description(
      "Error associated with the initial tensor");
    rv["Current Error Tensor"].set_description(
      "Error associated with the current tensor");
    return rv;
}

template<typename TensorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(IterationImprover, TensorType) {
    auto rv =
      sde::declare_result().template add_field<TensorType>("Improved Tensor");
    rv["Improved Tensor"].set_description("The improved tensor guess");
    return rv;
}

extern template class IterationImprover<type::tensor>;
extern template class IterationImprover<type::tensor_of_tensors>;

} // namespace simde

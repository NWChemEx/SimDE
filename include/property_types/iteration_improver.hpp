#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that use information across iterations
 *         to improve iterative matrix guesses.
 *
 *  @tparam ElementType the type of the elements in the matrices
 */
template<typename ElementType = double>
DECLARE_TEMPLATED_PROPERTY_TYPE(IterationImprover, ElementType);

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(IterationImprover, ElementType) {
    using tensor_type  = type::tensor<ElementType>;

    auto rv = sde::declare_input()
      .template add_field<const tensor_type&>("Initial Matrix")
      .template add_field<const tensor_type&>("Current Matrix")
      .template add_field<const tensor_type&>("Error Matrix");
    rv["Initial Matrix"].set_description(
      "The initial version of the matrix");
    rv["Current Matrix"].set_description(
      "The version of the matrix from the current iteration");
    rv["Error Matrix"].set_description(
      "Error associated with the current matrix");
    return rv;
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(IterationImprover, ElementType) {
    using tensor_type = type::tensor<ElementType>;

    auto rv = sde::declare_result().template add_field<tensor_type>(
      "Improved Matrix");
    rv["Improved Matrix"].set_description(
      "The improved matrix guess");
    return rv;
}

} // namespace property_types

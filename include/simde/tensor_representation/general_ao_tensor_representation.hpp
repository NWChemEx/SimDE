#pragma once
#include <sde/property_type/property_type.hpp>

namespace simde {

template<typename OperatorType, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(GeneralAOTensorRepresentation, OperatorType,
                                ElementType);

template<typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(GeneralAOTensorRepresentation, OperatorType,
                               ElementType) {
    using ao_space_map = std::map<unsigned int, type::ao_space<ElementType>>;
    using sparse_ao_space_map =
      std::map<unsigned int, type::sparse_ao_space<ElementType>>;

    using ao_space_map_t        = const ao_space_map<ElementType>&;
    using sparse_ao_space_map_t = const sparse_ao_space_map<ElementType>&;
    using op                    = const OperatorType&;

    auto rv = sde::declare_inputs()
                .add_field<ao_space_map_t>("AO Spaces")
                .template add_field<sparse_ao_space_map_t>("Sparse AO Spaces")
                .template add_field<op>("Operator");
    return rv;
}

template<typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(GeneralAOTensorRepresentation, OperatorType,
                                ElementType) {
    auto rv = sde::declare_results().add_field<type::tensor_of_tensors>(
      "Tensor representation");
    return rv;
}

template<typename OperatorType>
using GeneralAOTensorRepresentationD =
  GeneralAOTensorRepresentation<OperatorType, double>;

} // namespace simde

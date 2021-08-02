#pragma once
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

template<typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(GeneralAOTensorRepresentation, OperatorType);

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(GeneralAOTensorRepresentation, OperatorType) {
    using ao_space_map        = std::map<unsigned int, type::ao_space>;
    using sparse_ao_space_map = std::map<unsigned int, type::sparse_ao_space>;

    using ao_space_map_t        = const ao_space_map&;
    using sparse_ao_space_map_t = const sparse_ao_space_map&;
    using op                    = const OperatorType&;

    auto rv = pluginplay::declare_input()
                .add_field<ao_space_map_t>("AO Spaces")
                .template add_field<sparse_ao_space_map_t>("Sparse AO Spaces")
                .template add_field<op>("Operator");
    return rv;
}

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(GeneralAOTensorRepresentation, OperatorType) {
    auto rv = pluginplay::declare_result().add_field<type::tensor_of_tensors>(
      "Tensor representation");
    return rv;
}

} // namespace simde

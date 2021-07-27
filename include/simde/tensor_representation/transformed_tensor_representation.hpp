#pragma once

namespace simde {

template<typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(TransformedTensorRepresentation, OperatorType);

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(TransformedTensorRepresentation, OperatorType) {
    using ao_space      = type::ao_space;
    using derived_space = type::derived_space;

    using ao_space_map      = std::map<unsigned int, ao_space>;
    using derived_space_map = std::map<unsigned int, derived_space>;

    using ao_space_map_t      = const ao_space_map&;
    using derived_space_map_t = const derived_space_map&;
    using op_t                = const OperatorType&;

    auto rv = pluginplay::declare_inputs()
                .add_field<ao_space_map_t>("AO spaces")
                .template add_field<derived_space_map_t>("Derived spaces")
                .template add_field<op_t>("Operator");
    return rv;
}

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(TransformedTensorRepresentation, OperatorType) {
    return pluginplay::declare_results().add_field<type::tensor>(
      "Transformed tensor");
}

} // namespace simde

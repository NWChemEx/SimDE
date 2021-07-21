#pragma once

namespace simde {

template<typename OperatorType, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(TransformedTensorRepresentation, OperatorType,
                                ElementType);

template<typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(TransformedTensorRepresentation, OperatorType,
                               ElementType) {
    using ao_space      = type::ao_space<ElementType>;
    using derived_space = type::derived_space<ElementType>;

    using ao_space_map      = std::map<unsigned int, ao_space>;
    using derived_space_map = std::map<unsigned int, derived_space>;

    using ao_space_map_t      = const ao_space_map&;
    using derived_space_map_t = const derived_space_map&;
    using op_t                = const OperatorType&;

    auto rv = sde::declare_inputs()
                .add_field<ao_space_map_t>("AO spaces")
                .template add_field<derived_space_map_t>("Derived spaces")
                .template add_field<op_t>("Operator");
    return rv;
}

template<typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(TransformedTensorRepresentation, OperatorType,
                                ElementType) {
    return sde::declare_results().add_field<type::tensor>("Transformed tensor");
}

template<typename OperatorType>
using TransformedTensorRepresentationD =
  TransformedTensorRepresentation<OperatorType, double>;

} // namespace simde

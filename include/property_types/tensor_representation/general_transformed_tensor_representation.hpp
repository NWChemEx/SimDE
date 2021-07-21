#pragma once

namespace simde {

template<typename OperatorType, typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(GeneralTransformedTensorRepresentation,
                                OperatorType, ElementType);

template<typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(GeneralTransformedTensorRepresentation,
                               OperatorType, ElementType) {
    using ao_space          = type::ao_space<ElementType>;
    using sparse_ao_space   = type::sparse_ao_space<ElementType>;
    using ind_derived_space = type::ind_derived_space<ElementType>;
    using dep_derived_space = type::dep_derived_space<ElementType>;

    using ao_space_map          = std::map<unsigned int, ao_space>;
    using sparse_ao_space_map   = std::map<unsigned int, sparse_ao_space>;
    using ind_derived_space_map = std::map<unsigned int, ind_derived_space>;
    using dep_derived_space_map = std::map<unsigned int, dep_derived_space>;

    using ao_space_map_t          = const ao_space_map&;
    using sparse_ao_space_map_t   = const sparse_ao_space_map&;
    using ind_derived_space_map_t = const ind_derived_space_map&;
    using dep_derived_space_map_t = const dep_derived_space_map&;
    using op_t                    = const OperatorType&;

    auto rv =
      sde::declare_inputs()
        .add_field<ao_space_map_t>("AO spaces")
        .template add_field<sparse_ao_space_map_t>("Sparse AO spaces")
        .template add_field<ind_derived_space_map_t>(
          "Independent derived spaces")
        .template add_field<dep_derived_space_map_t>("Dependent derived spaces")
        .template add_field<op_t>("Operator");
    return rv;
}

template<typename OperatorType, typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(GeneralTransformedTensorRepresentation,
                                OperatorType, ElementType) {
    return sde::declare_results().add_field<type::tensor_of_tensors>(
      "Transformed tensor");
}

template<typename OperatorType>
using TransformedTensorRepresentationD =
  TransformedTensorRepresentation<OperatorType, double>;

} // namespace simde

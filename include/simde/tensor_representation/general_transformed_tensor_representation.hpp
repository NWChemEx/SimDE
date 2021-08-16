#pragma once
#include "simde/tensor_representation/detail_/tensor_rep_traits.hpp"
#include "simde/types.hpp"

namespace simde {

template<typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(GeneralTransformedTensorRepresentation,
                                OperatorType);

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(GeneralTransformedTensorRepresentation,
                               OperatorType) {
    using ao_space        = type::ao_space;
    using sparse_ao_space = type::sparse_ao_space;
    using iderived_space  = type::ind_derived_space;
    using dderived_space  = type::dep_derived_space;

    using ao_traits                = detail_::TensorRepTraits<ao_space>;
    using sparse_ao_traits         = detail_::TensorRepTraits<derived_space>;
    using ind_derived_space_traits = detail_::TensorRepTraits<iderived_space>;
    using dep_derived_space_triats = detail_::TensorRepTraits<dderived_space>;

    using ao_space_map          = typename ao_traits::map_type;
    using sparse_ao_space_map   = typename sparse_ao_traits::map_type;
    using ind_derived_space_map = typename ind_derived_space_traits::map_type;
    using dep_derived_space_map = typename dep_derived_space_traits::map_type;

    using ao_space_map_t          = const ao_space_map&;
    using sparse_ao_space_map_t   = const sparse_ao_space_map&;
    using ind_derived_space_map_t = const ind_derived_space_map&;
    using dep_derived_space_map_t = const dep_derived_space_map&;
    using op_t                    = const OperatorType&;

    auto rv =
      pluginplay::declare_input()
        .add_field<ao_space_map_t>("AO spaces")
        .template add_field<sparse_ao_space_map_t>("Sparse AO spaces")
        .template add_field<ind_derived_space_map_t>(
          "Independent derived spaces")
        .template add_field<dep_derived_space_map_t>("Dependent derived spaces")
        .template add_field<op_t>("Operator");
    return rv;
}

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(GeneralTransformedTensorRepresentation,
                                OperatorType) {
    return pluginplay::declare_result().add_field<type::tensor_of_tensors>(
      "Transformed tensor");
}

} // namespace simde

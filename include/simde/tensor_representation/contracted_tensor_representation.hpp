#pragma once
#include "simde/tensor_representation/detail_/tensor_rep_traits.hpp"
#include "simde/types.hpp"

namespace simde {

/** @brief A contracted tensor type
 *
 *  Some properties result from tensors being contracted with, e.g. density
 *  matrices. A trivial example is the Hartree-Fock total energy. However, in
 *  some case not all indeces are contracted. For example in the Hartree-Fock
 *  gradients the indeces related to the AO orbitals will be integrated out.
 *  Nevertheless, the indeces related to the atom coordinates the energy is
 *  differentiated with respect to will remain. The result is a tensor, but
 *  one where all AO basis indeces have be contracted out, i.e. a
 *  contracted tensor.
 *
 *  This property type is designed to accommodate the kinds of tensors where
 *  a number of indeces (typically over AOs) have been integrated out, but
 *  other indeces remain.
 *
 *  At present this tensor type specifically addresses energy gradients.
 *  However, it should be modified in future to accommodate other properties
 *  such as Hessians, mixed derivatives, etc. The number of AO indeces to
 *  contract over should be clear from the OperatorType. In future the number
 *  of remaining dimensions should become a template parameter.
 */
template<typename OperatorType>
DECLARE_TEMPLATED_PROPERTY_TYPE(ContractedTensorRepresentation, OperatorType);

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ContractedTensorRepresentation, OperatorType) {
    using el_density   = type::el_density;
    using ao_space     = type::ao_space;
    using ao_traits    = detail_::TensorRepTraits<ao_space>;
    using ao_space_map = typename ao_traits::map_type;

    using ao_space_map_t = const ao_space_map&;
    using op_t           = const OperatorType&;
    using density_t      = const el_density&;

    auto rv = pluginplay::declare_input()
                .add_field<ao_space>("Bra AO")          // Bra basis set
                .template add_field<ao_space>("Ket AO") // Ket basis set
                .template add_field<op_t>(
                  "Operator") // The operator implies the surviving indeces
                .template add_field<density_t>("One Electron Density");
    return rv;
}

template<typename OperatorType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ContractedTensorRepresentation, OperatorType) {
    return pluginplay::declare_result().add_field<type::tensor>(
      "Contracted tensor");
}

} // namespace simde

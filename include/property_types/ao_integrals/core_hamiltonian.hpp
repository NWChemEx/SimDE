#pragma once
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/n_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/**
 * @brief The property type for modules that build the core Hamiltonian in the
 *        AO basis set.
 *
 * @tparam ElementType The type of the elements in the returned tensor
 */
template<typename ElementType = double>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(CoreHamiltonian,
                                        ao_integrals::TwoCenter<ElementType>,
                                        ElementType);

//---------------------------Implementations------------------------------------
template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(CoreHamiltonian, ElementType) {
    auto rv = sde::declare_input().add_field<const type::molecule&>("Molecule");
    rv["Molecule"].set_description("The molecular system");
    return rv;
}

template<typename ElementType>
auto CoreHamiltonian<ElementType>::results_() {
    using my_type     = CoreHamiltonian<ElementType>;
    using tensor_type = type::tensor<ElementType>;
    auto key          = ao_integrals::detail_::make_key<my_type>("h");
    auto rv           = sde::declare_result().add_field<tensor_type>(key);
    rv[key].set_description("The computed Core Hamiltonian");
    return rv;
}

extern template class CoreHamiltonian<double>;
extern template class CoreHamiltonian<float>;

} // namespace property_types

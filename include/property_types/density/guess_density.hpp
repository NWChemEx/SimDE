#pragma once
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief Property type for modules that can guess an initial density from a
 *         molecule and basis set.
 *
 *  Particularly for the SCF method, it is necessary to provide an initial
 *  guess for the electronic density. This property type is for modules that are
 *  capable of providing such a guess.
 *
 *  @tparam ElementType The type of the elements in the input basis set
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
template<typename ElementType>
DECLARE_TEMPLATED_PROPERTY_TYPE(GuessDensity, ElementType);

//-------------------------------Implementations--------------------------------
template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_INPUTS(GuessDensity, ElementType) {
    using ham_t      = const type::hamiltonian&;
    using ao_space_t = const type::ao_space<ElementType>&;

    auto rv = sde::declare_input()
                .add_field<ham_t>("System Hamiltonian")
                .template add_field<ao_space_t>("Basis Set");
    return rv;
}

template<typename ElementType>
TEMPLATED_PROPERTY_TYPE_RESULTS(GuessDensity, ElementType>{
    auto rv = sde::declare_result().add_field<type::tensor>("Initial density");
    return rv;
}

extern template class GuessDensity<double>;
extern template class GuessDensity<float>;

} // namespace property_types

#pragma once
#include "simde/types.hpp"
#include <pluginplay/property_type/property_type.hpp>

namespace simde {

/** @brief Property type for modules that can guess an initial density from a
 *         molecule and basis set.
 *
 *  Particularly for the SCF method, it is necessary to provide an initial
 *  guess for the electronic density. This property type is for modules that are
 *  capable of providing such a guess.
 *
 *  @tparam OrbitalType The type of the orbital spaces in the returned map
 */
DECLARE_PROPERTY_TYPE(Guespluginplaynsity);

//-------------------------------Implementations--------------------------------
PROPERTY_TYPE_INPUTS(Guespluginplaynsity) {
    using ham_t      = const type::hamiltonian&;
    using ao_space_t = const type::ao_space&;

    auto rv = pluginplay::declare_input()
                .add_field<ham_t>("System Hamiltonian")
                .template add_field<ao_space_t>("Basis Set");
    return rv;
}

PROPERTY_TYPE_RESULTS(Guespluginplaynsity) {
    auto rv =
      pluginplay::declare_result().add_field<type::tensor>("Initial density");
    return rv;
}

} // namespace simde

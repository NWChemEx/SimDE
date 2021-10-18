#pragma once
#include "simde/types.hpp"

namespace simde {
namespace detail_ {

/// Struct for us to work out the return type w/o contaminating the namespace
struct AtomToCenterTraits {
    /// Type AOBasisSet uses for offsets
    using ao_size_type = typename simde::type::ao_basis_set::size_type;
    /// Type of a set of Center offsets
    using ao_set_type = std::set<ao_size_type>;
    /// Map from atom index to a set of Cernter offsets
    using return_type = std::vector<ao_set_type>;
};

} // namespace detail_

/// For user convenience this is the type returned by AtomToCenter
using atom_to_center_return_type = detail_::AtomToCenterTraits::return_type;

/** @brief Property type defining the API for assigning atoms to centers of AOs.
 *
 *  @note Design-wise we have opted to return indices not objects. This is for
 *        convenience. Since the user must provide us a Molecule and an
 *        AOBasisSet instance this should prove no problem for the user.
 *
 */
DECLARE_PROPERTY_TYPE(AtomToCenter);

PROPERTY_TYPE_INPUTS(AtomToCenter) {
    return pluginplay::declare_input()
      .add_field<const simde::type::molecule&>("Molecule")
      .template add_field<const simde::type::ao_basis_set&>("AO Basis");
}

PROPERTY_TYPE_RESULTS(AtomToCenter) {
    using r_t = atom_to_center_return_type;
    return pluginplay::declare_result().add_field<r_t>("Atom to Center map");
}

} // namespace simde
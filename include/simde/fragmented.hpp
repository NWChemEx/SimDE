#pragma once
#include <libchemist/set_theory/set_theory.hpp>
#include <pluginplay/pluginplay.hpp>

namespace simde {

/** @brief Property type for requesting that an object be Fragmented
 *
 *  Chemistry concepts such as functional groups, polymers, coordination
 *  compounds, etc. are predicated on the idea that we can understand the
 *  chemistry of large systems by understanding the chemistry of the system's
 *  parts. That said there are a lot of different ways to "fragment" a system
 *  (for a molecule with @f$n@f$ atoms there are @f$B_n@f$ partitions where
 *  @f$B_n@f$ is the @f$n@f$-th Bell number). In practice the fragmenting is
 *  usually not arbitrary, but the result of some algorithm which relies on
 *  chemical concepts such as bonds and/or spatial distances to assign the
 *  fragments. Nonetheless, there are still a large number of algorithms and
 *  this property type is for any module which fragments an object into
 *  subobjects. Examples are:
 *  - `Fragmented<Molecule>` for fragmenting a molecular system
 *  - `Fragmented<AOBasisSet<double>>` for fragmenting basis sets
 *
 *  @tparam Type2Fragment The object type we are fragmenting. Expected to be
 *                        set-like although exactly what the module does with
 *                        the type is up to the module.
 */

template<typename Type2Fragment>
DECLARE_TEMPLATED_PROPERTY_TYPE(Fragmented, Type2Fragment);

template<typename Type2Fragment>
PROPERTY_TYPE_INPUTS(Fragmented<Type2Fragment>) {
    return pluginplay::declare_input().add_field<Type2Fragment>(
      "Object to Fragment");
}

template<typename Type2Fragment>
PROPERTY_TYPE_RESULTS(Fragmented<Type2Fragment>) {
    using return_type = libchemist::set_theory::FamilyOfSets<Type2Fragment>;
    return pluginplay::declare_result().add_field<return_type>(
      "Fragmented Object");
}

} // namespace simde

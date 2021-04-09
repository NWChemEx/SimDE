#pragma once
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief The property type for modules that compute a sparse relation.
 *
 *  @tparam IndependType The type of the independent basis.
 *  @tparam DependType The type of the dependent basis.
 */
template<typename IndependType, typename DependType>
DECLARE_TEMPLATED_PROPERTY_TYPE(SparsityRelation, IndependType, DependType);

template<typename IndependType, typename DependType>
TEMPLATED_PROPERTY_TYPE_INPUTS(SparsityRelation, IndependType, DependType) {
    auto rv = sde::declare_input()
                .add_field<const IndependType&>("Independent Basis")
                .template add_field<const DependType&>("Dependent Basis");
    rv["Independent Basis"].set_description("The dense basis");
    rv["Dependent Basis"].set_description("The sparse basis");
    return rv;
}

template<typename IndependType, typename DependType>
TEMPLATED_PROPERTY_TYPE_RESULTS(SparsityRelation, IndependType, DependType) {
    using libchemist::sparse_map::SparseMapEE;
    auto rv = sde::declare_result().add_field<SparseMapEE>("Sparse Map");
    rv["Sparse Map"].set_description(
      "Map from a given member of the independent basis to its"
      " domain in the dependent basis set");
    return rv;
}

} // namespace property_types
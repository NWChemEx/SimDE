#pragma once
#include "simde/types.hpp"

namespace simde::detail_ {

/** @brief Struct used to synchronized input types across the tensor
 *         representation component of SimDE.
 *
 *
 *  @tparam T The orbital space we are generating types for. Assumed to be one
 *            of: type::ao_space, type::sparse_ao_space, type::derived_space,
 *            type::in_derived_space, or type::dep_derived_space.
 */
template<typename T>
struct TensorRepTraits {
    /// Type used to index modes in the intergral
    using mode_type = unsigned int;
    /// Type used to hold a read-only reference to an orbital space of type @p T
    using const_reference = std::reference_wrapper<const T>;
    /// Type of a map from modes to orbital spaces
    using map_type = std::map<mode_type, const_reference>;
};

} // namespace simde::detail_

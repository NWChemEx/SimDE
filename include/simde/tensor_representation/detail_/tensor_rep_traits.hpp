#pragma once
#include "simde/types.hpp"
#include <chemist/orbital_space/orbital_space.hpp>

namespace simde::detail_ {

/** @brief Struct used to synchronized input types across the tensor
 *         representation component of SimDE.
 *
 *
 *  @tparam T The orbital space we are generating types for. Assumed to be one
 *            of (or implicitly convertible to one of):
 *            - type::ao_space,
 *            - type::derived_space,
 *            - type::tot_derived_space, or
 *            - type::independent_space
 *
 */
template<typename T>
struct TensorRepTraits {
private:
    /// Base type for AO spaces
    using ao_space_type = type::ao_space;

    /// Base type for (non-ToT) derived spaces
    using derived_space_type = type::derived_space;

    /// Base type for (ToT) derived spaces
    using tot_space_type = type::tot_derived_space;

public:
    /// Type used to index modes in the intergral
    using mode_type = unsigned int;

    /// Type used to hold a read-only reference to an orbital space of type @p T
    using const_reference = std::reference_wrapper<const T>;

    /// Type of a map from modes to orbital spaces
    using map_type = std::map<mode_type, const_reference>;

    /// Is T an AO space?
    static constexpr bool is_ao_space = std::is_base_of_v<ao_space_type, T>;

    /// Is T a normal, non-ToT, transformation?
    static constexpr bool is_derived = std::is_base_of_v<derived_space_type, T>;

    /// Is T a ToT transformation?
    static constexpr bool is_tot_derived = std::is_base_of_v<tot_space_type, T>;

    /// Is T an independent space?
    static constexpr bool is_independent =
      chemist::orbital_space::is_independent_space_v<T>;
};

} // namespace simde::detail_

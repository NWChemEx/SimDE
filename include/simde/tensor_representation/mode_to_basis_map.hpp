#pragma once
#include <map>
#include <utility> // For reference_wrapper

namespace simde {

/** @brief Stores a mapping from mode index to basis set instances.
 *
 *  This class is primarily meant for use with the property types associated
 *  with tensor representations. When we call a module satisfying one of those
 *  property types we must specify the basis sets for each mode of the tensor.
 *  This is conventionally done by positional arguments (0-th basis set passed
 *  in is for mode 0, 1-st is for mode 1, etc.), but that leads to a lot of
 *  APIs (templating doesn't really help because property types/modules require
 *  you to explicitly instantiate a template per permuation of types).
 *
 *  Our solution is to introduce the ModeToBasisMap class. This class acts like
 *  a std::map<int, const BasisSetType&> where the keys are mode indices and
 *  the values are read-only references to BasiSetType instances. Using the
 *  ModeToBasisMap class property types are defined in terms of number of basis
 *  sets (i.e., the rank of the resulting tensor) and a series of
 *  ModeToBasisMap<T> instances, one ModeToBasisMap instance for each basis set
 *  T the module needs to consider.
 *
 *  In practice the ModeToBasisMap class is a thin wrapper around a std::map,
 *  which also worries about ownership. In particular since this class is meant
 *  for use with property types it recognizes that it sometimes must alias the
 *  basis sets and other times own them. The logic for this is encapsulated in
 *  the ModeToBasisMap class.
 *
 *  @tparam BasisSetType The type being used to model a basis set.
 */
template<typename BasisSetType>
class ModeToBasisMap {
private:
    /// Reference_wrapper to a const @p T, defined to shorten future typedefs
    template<typename T>
    using const_ref_wrapper = std::reference_wrapper<const T>;

public:
    /// Type used for indexing modes, acts like an unsinged integer type
    using mode_type = unsigned int;

    /// Unqualified type of a basis set instance, typedef of BasisSetType
    using basis_set_type = BasisSetType;

    /// Read-only reference to a basis set, typedef of const BasisSetType&
    using const_basis_set_reference = const_ref_wrapper<BasisSetType>;

    /// A std::map from mode offest to const_basis_set_reference
    using map_type = std::map<mode_type, const_basis_set_reference>;

    /// Read-only reference to a "mode, basis set" pair
    using const_reference = typename map_type::const_reference;

    ModeToBasisMap() = default;

    /** @brief Creates a deep copy of @p other.
     *
     *  This function will own deep copies of each basis set in @p other. This
     *  means regardless of whether or not @p other aliased a basis set, the
     *  resulting ModeToBasisMap will own its copy. The basis sets will still
     *  have the same mapping.
     *
     *  @param[in] other The instance being deep-copied.
     */
    ModeToBasisMap(const ModeToBasisMap& other);

    auto size() const noexcept { return m_aliased_bs_.size(); }

    auto count(mode_type i) const noexcept { return m_aliased_bs_.count(i); }

    void emplace(mode_type i, const_basis_set_reference bs);

    /** @brief Returns the basis set for the i-th mode of the tensor.
     *
     *  @param[in] i The tensor mode we are retrieving the basis set for.
     *
     *  @return A read-only reference to the basis set for the @p i -th mode.
     *
     *  @throw std::out_of_range if @p i is not associated with a basis set in
     *                           this instance. Strong throw guarantee.
     */
    const_basis_set_reference at(mode_type i) const;

    /** @brief Returns an iterator to the first mode-basis set pair
     *
     *  @return An iterator pointing to the first mode-bs pair.
     */
    auto begin() const { return m_aliased_bs_.begin(); }

    /** @brief Returns an iterator to just past the last mode-basis set pair.
     *
     *
     *  @return An iterator which points to just past the last mode-basis set
     *          pair. This iterator should not be dereferenced.
     */
    auto end() const { return m_aliased_bs_.end(); }

    bool operator==(const ModeToBasisMap& rhs) const noexcept;

    bool operator!=(const ModeToBasisMap& rhs) const noexcept;

private:
    /// Holds the basis sets we are aliasing (even owned ones are aliased here)
    map_type m_aliased_bs_;

    // Holds the basis sets we own the memory for
    std::map<mode_type, BasisSetType> m_owned_bs_;
};

} // namespace simde

#include "mode_to_basis_map.ipp"

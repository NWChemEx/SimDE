#pragma once
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/n_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief The property type for modules that build the exchange matrix, which
 *         is canonically denoted @f$\mathbf{K}@f$.
 *
 *  While the canonical algorithms for building @f$\mathbf{J}@f$ and
 *  @f$\mathbf{K}@f$ usually have them being built together to avoid recomputing
 *  integrals, modern algorithms often build the two by relying on very
 *  different procedures. This property type is for modules that build
 *  @f$\mathbf{K}@f$. The same module may also build @f$\mathbf{J}@f$, in which
 *  case it should register itself as satisfying both property types and rely
 *  on memoization for "computing" @f$\mathbf{J}@f$.
 *
 *  @tparam ElementType The type of the elements in the returned tensor.
 *  @tparam OrbitalType The type of the input orbital space
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbital_space_t<ElementType>>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(ExchangeMatrix,
                                        ao_integrals::TwoCenter<ElementType>,
                                        ElementType, OrbitalType);

//-----------------------------Implementations----------------------------------

template<typename ElementType, typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_INPUTS(ExchangeMatrix, ElementType, OrbitalType) {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

template<typename ElementType, typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_RESULTS(ExchangeMatrix, ElementType, OrbitalType) {
    using my_type     = ExchangeMatrix<ElementType, OrbitalType>;
    using tensor_type = type::tensor<ElementType>;
    auto key          = ao_integrals::detail_::make_key<my_type>("k");
    auto rv           = sde::declare_result().add_field<tensor_type>(key);
    rv[key].set_description("The computed exchange matrix");
    return rv;
}

extern template class ExchangeMatrix<double>;
extern template class ExchangeMatrix<double, type::derived_space_t<double>>;
extern template class ExchangeMatrix<double, type::canonical_space_t<double>>;
extern template class ExchangeMatrix<float>;
extern template class ExchangeMatrix<float, type::derived_space_t<float>>;
extern template class ExchangeMatrix<float, type::canonical_space_t<float>>;

} // namespace property_types

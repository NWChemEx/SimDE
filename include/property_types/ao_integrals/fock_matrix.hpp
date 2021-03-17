#pragma once
#include "property_types/ao_integrals/detail_/make_key.hpp"
#include "property_types/ao_integrals/n_center.hpp"
#include "property_types/types.hpp"
#include <sde/property_type/property_type.hpp>

namespace property_types {

/** @brief The property type for modules that build Fock matrices in the AO
 *  basis set.
 *
 *  The Fock matrix (or Kohn-Sham matrix for DFT) is an effective one-electron
 *  potential. Modules that satisfy this property type are capable of computing
 *  the Fock matrix in the AO basis set.
 *
 *  @tparam ElementType The type of the elements in the returned tensor.
 *  @tparam OrbitalType The type of the input orbital space
 */
template<typename ElementType = double,
         typename OrbitalType = type::orbital_space_t<ElementType>>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(FockMatrix,
                                        ao_integrals::TwoCenter<ElementType>,
                                        ElementType, OrbitalType);

//-------------------------------------Implementations--------------------------

template<typename ElementType, typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_INPUTS(FockMatrix, ElementType, OrbitalType) {
    auto rv = sde::declare_input()
                .add_field<const type::molecule&>("Molecule")
                .add_field<const OrbitalType&>("Molecular Orbitals");
    rv["Molecule"].set_description("The molecular system");
    rv["Molecular Orbitals"].set_description("The molecular orbitals");
    return rv;
}

template<typename ElementType, typename OrbitalType>
TEMPLATED_PROPERTY_TYPE_RESULTS(FockMatrix, ElementType, OrbitalType) {
    using my_type     = FockMatrix<ElementType, OrbitalType>;
    using tensor_type = type::tensor<ElementType>;
    auto key          = ao_integrals::detail_::make_key<my_type>("f");
    auto rv           = sde::declare_result().add_field<tensor_type>(key);
    rv[key].set_description("The computed Fock Matrix");
    return rv;
}

extern template class FockMatrix<double>;
extern template class FockMatrix<double, type::derived_space_t<double>>;
extern template class FockMatrix<double, type::canonical_space_t<double>>;
extern template class FockMatrix<float>;
extern template class FockMatrix<float, type::derived_space_t<float>>;
extern template class FockMatrix<float, type::canonical_space_t<float>>;

} // namespace property_types

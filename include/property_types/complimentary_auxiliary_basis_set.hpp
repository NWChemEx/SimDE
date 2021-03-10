#pragma once
#include <sde/property_type/property_type.hpp>

namespace property_types {

template<typename ResultBasis, typename InputBasis>
DECLARE_TEMPLATED_PROPERTY_TYPE(ComplimentaryAuxiliaryBasisSet, ResultBasis,
                                InputBasis);

template<typename ResultBasis, typename InputBasis>
TEMPLATED_PROPERTY_TYPE_INPUTS(ComplimentaryAuxiliaryBasisSet, ResultBasis,
                               InputBasis) {
    auto rv =
      sde::declare_input().add_field<const InputBasis&>("orbital basis");
    return rv;
}

template<typename ResultBasis, typename InputBasis>
TEMPLATED_PROPERTY_TYPE_RESULTS(ComplimentaryAuxiliaryBasisSet, ResultBasis,
                                InputBasis) {
    auto rv = sde::declare_result().add_field<ResultBasis>("CABS");
    return rv;
}

} // namespace property_types
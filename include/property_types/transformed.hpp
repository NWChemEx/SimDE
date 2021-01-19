#pragma once
#include <sde/property_type/property_type.hpp>

namespace property_types {

template<typename BaseType>
DECLARE_DERIVED_TEMPLATED_PROPERTY_TYPE(Transformed, BaseType, BaseType);

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Transformed, BaseType) {
    return sde::declare_input();
}

template<typename BaseType>
TEMPLATED_PROPERTY_TYPE_RESULTS(Transformed, BaseType) {
    return sde::declare_result();
}

} // namespace property_types
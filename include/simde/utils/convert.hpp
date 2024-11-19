#pragma once
#include <pluginplay/pluginplay.hpp>

namespace simde {

template<typename ToType, typename FromType>
DECLARE_TEMPLATED_PROPERTY_TYPE(Convert, ToType, FromType);

template<typename ToType, typename FromType>
TEMPLATED_PROPERTY_TYPE_INPUTS(Convert, ToType, FromType) {
    return PropertyType::inputs().template add_field<FromType>(
      "Object to convert from");
}

template<typename ToType, typename FromType>
TEMPLATED_PROPERTY_TYPE_Results(Convert, ToType, FromType) {
    return pluginplay::declare_result().template add_field<ToType>(
      "Converted object");
}

} // namespace simde
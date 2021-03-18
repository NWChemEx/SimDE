#pragma once

namespace property_types {

template<typename OccType, typename VirtType>
DECLARE_TEMPLATED_PROPERTY_TYPE(DoublesResidual, OccType, VirtType);

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_INPUTS(DoublesResidual, OccType, VirtType) {
    auto rv = sde::declare_input()
                .add_field<const OccType&>("occupied space")
                .template add_field<const VirtType&>("virtual space");
    return rv;
}

template<typename OccType, typename VirtType>
TEMPLATED_PROPERTY_TYPE_RESULTS(DoublesResidual, OccType, VirtType) {
    using tensor_type = std::decay_t<decltype(std::declval<OccType>().C())>;
    auto rv           = sde::declare_result().add_field<tensor_type>("R");
    return rv;
}

} // namespace property_types
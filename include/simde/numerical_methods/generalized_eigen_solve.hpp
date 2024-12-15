#pragma once
#include <pluginplay/property_type/property_type.hpp>
#include <simde/types.hpp>

namespace simde {

DECLARE_PROPERTY_TYPE(GeneralizedEigenSolve);

PROPERTY_TYPE_INPUTS(GeneralizedEigenSolve) {
    using input_type = const type::tensor&;
    auto rv          = pluginplay::declare_input()
                .add_field<input_type>("Matrix")
                .template add_field<input_type>("Metric");
    rv["Matrix"].set_description("The matrix to diagonalize.");
    rv["Metric"].set_description("Metric for the basis set of \"Matrix\".");
    return rv;
}

PROPERTY_TYPE_RESULTS(GeneralizedEigenSolve) {
    using result_type = type::tensor;
    auto rv           = pluginplay::declare_result()
                .add_field<result_type>("Eigen values")
                .template add_field<result_type>("Eigen vectors");
    return rv;
}

} // namespace simde
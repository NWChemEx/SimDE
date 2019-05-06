#pragma once
#include "property_types/types.hpp"
#include <SDE/PropertyType.hpp>

namespace property_types {

/**
 * @brief The base class for modules that build energy and energy derivatives
 *
 */

template<typename element_type = double>
struct Energy : public SDE::PropertyType<Energy<element_type>> {
    using molecule_type = Molecule;
    using tensor_type   = tamm::Tensor<element_type>;
    using size_type     = std::size_t;

    auto inputs_() {
        auto
          rv = SDE::declare_input().add_field<const molecule_type&>("Molecule")
          .add_field<size_type>("Derivative");
        rv["Molecule"]
          .set_description("The molecule for which the energy is calculated");
        rv["Derivative"].set_description("The derivative order of the energy");
        return rv;
    }

    auto results_() {
        auto rv = SDE::declare_result().add_field<tensor_type>("Energy");
        rv["Energy"].set_description("The computed energy or derivatives");
        return rv;
    }
};

} //namespace property_types

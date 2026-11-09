/*
 * Copyright 2026 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <pluginplay/pluginplay.hpp>
#include <simde/uncertainty/uq_factory.hpp>

namespace simde {

/** @brief Produces a UQFactory.
 *
 *  Modules which create uncertain values from `double` values, *e.g.*,
 *  integrals, get the factory they use from a submodule of this property
 *  type. The kind of uncertainty is configured on the module satisfying this
 *  property type, so the property type itself has no inputs.
 */
DECLARE_PROPERTY_TYPE(UQInitializer);

PROPERTY_TYPE_INPUTS(UQInitializer) { return pluginplay::declare_input(); }

PROPERTY_TYPE_RESULTS(UQInitializer) {
    auto rv = pluginplay::declare_result().add_field<UQFactory>("UQ Factory");
    rv["UQ Factory"].set_description(
      "A factory that constructs uncertain values of the configured kind");
    return rv;
}

} // namespace simde

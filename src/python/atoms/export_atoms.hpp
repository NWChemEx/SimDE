/*
 * Copyright 2023 NWChemEx-Project
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
#include "../export_simde.hpp"
#include <pluginplay/pluginplay.hpp>
#include <simde/atoms/atoms.hpp>

namespace simde {

inline void export_atomfromz(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(AtomFromZ, m);
}

inline void export_atomfromsym(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(AtomFromSym, m);
}

inline void export_atomdenfromz(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(AtomDenFromZ, m);
}

inline void export_atomdenfromsym(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(AtomDenFromSym, m);
}

inline void export_elecconfigfromz(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(ElecConfigFromZ, m);
}

inline void export_elecconfigfromsym(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(ElecConfigFromSym, m);
}

inline void export_fracconfigfromz(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(FracConfigFromZ, m);
}

inline void export_fracconfigfromsym(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(FracConfigFromSym, m);
}

inline void export_fullconfigfromz(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(FullConfigFromZ, m);
}

inline void export_fullconfigfromsym(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(FullConfigFromSym, m);
}

inline void export_symbolfromz(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(SymbolFromZ, m);
}

inline void export_zfromsymbol(python_module_reference m) {
    EXPORT_PROPERTY_TYPE(ZFromSymbol, m);
}

} // namespace simde

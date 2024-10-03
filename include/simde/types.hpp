/*
 * Copyright 2022 NWChemEx-Project
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
#include <chemist/chemist.hpp>
#include <map>
#include <tensorwrapper/tensorwrapper.hpp>
#include <utility>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in sync with
 *  the remainder of the library.
 */
namespace simde::type {

using tensor = tensorwrapper::Tensor;

// --------------------- Fundamental Types -------------------------------------

/// Typedef of the class used to describe a molecule
using molecule = chemist::Molecule;

/// Typedef of the class which models a nucleus
using atom = typename molecule::atom_type;

/// Typedef of the class which models an atomic symbol
using atomic_symbol = typename atom::name_type;

/// Typedef of the class which models an atomic number
using atomic_number = typename atom::atomic_number_type;

/// Typedef of the class which describes an entire chemical system
using chemical_system = chemist::ChemicalSystem;

/// Typdef of the class representing an electron
using electron = chemist::Electron;

// ------------------------------ Basis Sets -----------------------------------

/// Typedef of the AO Basis Set
using ao_basis_set = chemist::basis_set::AOBasisSetD;

/// Typedef of an Atomic Basis Set
using atomic_basis_set = chemist::basis_set::AtomicBasisSetD;

/// Typdef of a Shell
using shell = chemist::basis_set::ShellD;

/// Typedef of a Contracted Gaussian
using contracted_gaussian = chemist::basis_set::ContractedGaussianD;

/// Typdef of a Primitive
using primitive = chemist::basis_set::PrimitiveD;

/// Typedef of a cartesian point
using point = chemist::Point<double>;

/// Typedef of a full atomic electronic configuration
// using full_elec_conf = std::map<std::pair<size, size>, size>;

// ------------------------- Quantum Mechanics ---------------------------------

/// Type representing an AO space
using ao_space = chemist::wavefunction::AOs;

/// Type representing the electron kinetic operator
using el_kinetic = chemist::qm_operator::Kinetic<electron>;

} // namespace simde::type

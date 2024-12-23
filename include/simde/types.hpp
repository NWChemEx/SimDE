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
#include <utilities/dsl/dsl.hpp>
#include <utility>

/** @file types.hpp
 *
 *  These are typedefs of the fundamental types used in the property types.
 *  Property types are encouraged to use these typedefs to stay in sync with
 *  the remainder of the library.
 */
namespace simde::type {

/// Typedef of the class that represents a tensor
using tensor = tensorwrapper::Tensor;

// --------------------- Fundamental Types -------------------------------------

/// Typedef of the class used to hold a set of point charges
using charges = chemist::Charges<double>;

/// Typedef of the class used to describe an electron
using electron = chemist::Electron;

/// Typedef of the class used to describe a set of electrons
using many_electrons = chemist::ManyElectrons;

/// Typedef of the class used to describe a nucleus
using nucleus = chemist::Nucleus;

/// Typedef of the class describing a set of nucleus objects
using nuclei = chemist::Nuclei;

/// Typedef of the class which models an atom (nucleus + electrons)
using atom = chemist::Atom;

/// Typedef of the class used to describe a set of atom objects
using molecule = chemist::Molecule;

/// Typedef of the class which describes an entire chemical system
using chemical_system = chemist::ChemicalSystem;

/// Typedef of the class which models an atomic symbol
using atomic_symbol = typename atom::name_type;

/// Typedef of the class which models an atomic number
using atomic_number = typename atom::atomic_number_type;

/// Typedef of the electron density
using e_density = chemist::Density<electron>;

/// Typedef of a decomposable electron density
using decomposable_e_density = chemist::DecomposableDensity<electron>;

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

// -------------------------- Quantum Mechanics --------------------------------

template<typename BraType, typename OpType, typename KetType>
using braket = chemist::braket::BraKet<BraType, OpType, KetType>;

/// Typedef of the class used to represent an atomic orbital space
using aos = chemist::wavefunction::AOs;

/// Typedef of the class used to represent a product of atomic orbital spaces
using aos_squared = utilities::dsl::Multiply<aos, aos>;

/// Typedef of the class used to represent transformed AOs
using mos = chemist::wavefunction::MOs;

/// Typedef of the class used to represent the space spanned by the canonical
/// molecular orbitals
using cmos = chemist::wavefunction::CMOs;

/// Typedef of the class for a many-fermion wavefunction
template<typename OrbitalType>
using determinant = chemist::wavefunction::Determinant<OrbitalType>;

/// Typedef of the class for the (restricted) canonical SCF wavefunction
using rscf_wf = determinant<cmos>;

/// Import the operator types
using namespace chemist::qm_operator::types;

/// The one-electron density operator expressed in the CMO basis set
template<typename OrbitalType>
using rho_e = chemist::qm_operator::Density<OrbitalType, electron>;

/// Pull in the Hamiltonian operator in case-consistent manner
using hamiltonian = chemist::qm_operator::Hamiltonian;

/// Pull in the CoreHamiltonian operator in case-consistent manner
using core_hamiltonian = chemist::qm_operator::CoreHamiltonian;

/// Pull in the ElectronicHamiltonian operator in case-consistent manner
using electronic_hamiltonian = chemist::qm_operator::ElectronicHamiltonian;

/// Pull in the Fock operator in case-consistent manner
using fock = chemist::qm_operator::Fock;

} // namespace simde::type

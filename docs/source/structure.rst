.. Copyright 2022 NWChemEx-Project
..
.. Licensed under the Apache License, Version 2.0 (the "License");
.. you may not use this file except in compliance with the License.
.. You may obtain a copy of the License at
..
.. http://www.apache.org/licenses/LICENSE-2.0
..
.. Unless required by applicable law or agreed to in writing, software
.. distributed under the License is distributed on an "AS IS" BASIS,
.. WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
.. See the License for the specific language governing permissions and
.. limitations under the License.

###########################
Structure of the SimDE Repo
###########################

Ultimately there's a lot of property types used throughout an electronic
structure code. To make the user's life easier we have organized the property
types into groups. This page provides an explanation of the groups

*******
Density
*******

Property types focused on computing electron densities. These include property
types for computing and updating guesses for mean-field theories (*i.e.*,
respectively the ``GuessDensity`` and ``UpdateDenstiy`` property types).

******
Energy
******

Property types focused on computing energies. For the most part these property
types differ from one another in terms of the inputs they accept. For example
``Energy`` serves as a base property type which takes a ``ChemicalSystem`` and
computes the energy of it, whereas ``AOEnergy`` takes an ``AOSpace`` and a
``ChemicalSystem``.

**************
Linear Algebra
**************

These are property types related to performing numeric linear algebra on
tensors.

*********
Operators
*********

These are property types which compute operators, for example ``Fock`` takes a
``Hamiltonian`` instance and a one-electron desnity and turns it into a ``Fock``
operator.

**************
Orbital Spaces
**************

These are property types which focus on computing new orbital spaces. For
example ``LocalizedOrbitals`` takes an existing orbital space and localizes it.

**********************
Tensor Representations
**********************

These are property types which deal with formation of tensor representations of
operators. Also included are property types which perform orbital
transformations of tensor representations.

*************
Wavefunctions
*************

These are property types which deal with computing wavefunctions.

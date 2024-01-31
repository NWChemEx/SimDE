.. Copyright 2024 NWChemEx-Project
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

.. _architecture_of_simde:

#####################
Architecture of SimDE
#####################

In :ref:`simde_statement_of_need` we described the needs SimDE was designed
to address. The actual SimDE library is largely a meta-package, i.e., it bundles
a number of development libraries together into a single package. Architecture
and design of those libraries is outside our present scope and falls under the
purview of the respective libraries. The discussions here focus on the
architecture and design of the pieces of SimDE for which development occurs in
the SimDE repo. For the most part, this limits our discussion to computational
chemistry property types.

***************************
Architecture Considerations
***************************

The present architecture of SimDE was developed from the following
considerations.

.. _as_parallel_chemist_architecture:

parallel Chemist architecture
   From a computer science perspective, modules are pure functions. Pure
   functions are maps from inputs to results. Having a module map to multiple
   results has its time and place, but most modules will map to a single result.
   Since these results are usually Chemist objects, there is a natural mapping
   from the architecture of Chemist to the architecture of SimDE.

   - The consequences of this consideration are that developers will have an
     easier time finding things and figuring out where to put things if we
     define the same components as Chemist.

properties beyond Chemist
   While many property types will result in Chemist objects, not all will. For
   example a number of property types will result in plain old data or tensors.

   - The consequence here is that the :ref:`as_parallel_chemist_architecture`
     consideration alone is not sufficient for defining all of SimDE's
     architecture.

.. _as_energies:

energies
   One of the most important properties in computational chemistry are
   "energies". This includes not only total energies, but also relative
   energies, and components of total/relative energies.

********************************
Overview of SimDE's Architecture
********************************

.. _fig_simde_architecture:

.. figure:: assets/architecture.png
   :align: center

   Architecture of the SimDE library.

:numref:`fig_simde_architecture` shows the current architecture of SimDE. At
present SimDE's source consists of a single property type component.

Property Types
==============

Following from :ref:`as_parallel_chemist_architecture`, SimDE's property type
component is structured to contain sub-components for each component of Chemist.

.. note::

   Modules are assumed to wrap algorithms, so property types should only be
   defined when there is a need for an algorithm to convert from the inputs to
   the result. For example, modules should not be used for trivial calls to an
   object's constructor.

Basis Set
---------

Main page: :ref:`design_of_basis_set_property_types`.

Property types in the "Basis Set" sub-component of SimDE define APIs for
creating Chemist objects such as ``AOBasisSet`` and ``AtomicBasisSet``.
Typically these property types are used for modules which go from more
traditional user inputs such as a molecular geometry and an atomic basis set
specification like "6-31G*" to an actual ``AOBasisSet`` object.

Chemical System
---------------

Main page: :ref:`design_of_chemical_system_property_types`.

Property types in the "Chemical System" sub-component of SimDE define APIs for
creating Chemist objects such as ``Molecule`` and ``ChemicalSystem``. Like the
"Basis Set" sub-component, many of these modules are primarily used to convert
from more traditional user inputs like atomic symbols and Cartesian coordinates
to an actual ``Molecule`` object.

Energy
------

Main page: :ref:`design_of_energy_property_types`.

The energy of a chemical system is a fundamental property in computational
chemistry. Unsurprisingly many computational chemistry methods strive to be
black boxes for computing the total energy of a chemical system. The mapping
from a ``ChemicalSystem`` object to a total energy defines the ``TotalEnergy``
property type. In practice, methods often require additional inputs in order
to compute the total energy. The "Energy" sub-component collects property types
for computing the total energy, relative energies, and components of the
other energies.

*******
Summary
*******

:ref:`as_parallel_chemist_architecture`
   The "Property Types" component contains sub-components for each component of
   Chemist.

:ref:`as_energies`
   SimDE's "Property Type" component contains an "Energy" sub-component.

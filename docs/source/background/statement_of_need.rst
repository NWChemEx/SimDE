.. Copyright 2023 NWChemEx-Project
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

.. _simde_statement_of_need:

#######################
SimDE Statement of Need
#######################

The :ref:`simde_motivation` provided some background on developing and working
with modular software and the importance of community standards. Ultimately,
we argue that the creation of a computational chemistry development environment
is needed thus motivating the development of SimDE.

**********************************
Enforcement of Community Standards
**********************************

Modular software is most impactful when paired with interoperability (the
requirement that two components can be swapped out without needing to alter
the calling code). Key to interoperability is the use of standardized
interfaces.


**************
Property Types
**************

The NWChemEx team wrote
`PluginPlay <https://github.com/NWChemEx/PluginPlay>`__ in order to provide the
infrastructure needed to manage software comprised of modular code. In
particular PluginPlay facilitates the: discovery, loading, and selecting of
modules. SimDE is needed because.In PluginPlay parlance these standardized interfaces are called
property types and they are to be defined by the domain experts. Ultimately,
the creation for SimDE was motivated by the need for a centralized location to
store standardized interfaces used in computational chemistry.



TODO: Explain how SimDE eases plugin development

TODO: Other standardization options

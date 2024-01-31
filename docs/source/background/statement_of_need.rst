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

:ref:`simde_motivation` provided some background on developing and working
with modular software and the importance of community standards. The NWChemEx
community has developed a number of software products to serve as the
infrastructure base for developing high-performance computational chemistry
software. Given that said infrastructure is new to the broader community, it is
no surprise that the community has yet to develop standards around it. SimDE
rectifies this problem, by providing a software development kit for writing
plugins within the NWChemEx ecosystem. The specific needs addressed by SimDE
are detailed on this page.

*****************************************
Enforcement of Interoperability Standards
*****************************************

The end goal of modular scientific software should be reusability. Reusability
is greatly enhanced by also striving for interoperability, i.e.,the idea that
two components providing the same feature can be swapped and the code will "just
work". Community standards for data structures and :term:`APIs <API>` are
essential to interoperability efforts, and we need tools to help enforce these
standards.

The establishment of community standards is beyond our scope. Rather we assume
such standards already exist and focus one enforcing these standards within
`PluginPlay <https://github.com/NWChemEx/PluginPlay>`__. In PluginPlay
standardized interfaces are enforced by writing
`property types <http://tinyurl.com/mpunujh6>`__. Thus we have a need to develop
infrastructure for writing computational chemistry property types (think type
traits, for example) and to a need to use this infrastructure to produce
property types for quantities of interest in computational chemistry.

*********************
Property Type Hosting
*********************

PluginPlay strives to make writing property types as easy as possible. Even if
property types are easy to write, best practice is to avoid having the community
need to write the same property type multiple times. To this end, we need a
centralized place for hosting already developed property types. Having a
centralized repo also makes it easier for developers to check if a property
type has already been standardized.

*******************************************
NWChemEx Community Software Development Kit
*******************************************

The NWChemEx software stack is modular, and layered, in order to promote reuse
by other projects. While useful from the perspective of reuse, this complicates
development because developers need to wrangle together several components
before they can begin development. The traditional solution to this problem is
to provide developers a software development kit. After installing the software
development kit, developers are ready to develop, i.e., no need to install the
pieces individually.

***********************************************
Developer Tutorials for Writing Plugins/Modules
***********************************************

PluginPlay is designed to be domain agnostic. Thus we limited PluginPlay's
tutorials to fundamental science concepts in order to appeal to wide set of
potential users. That said, we also realize that many developers may prefer
domain-specific tutorials as they provide less of a cognitive leap from tutorial
to practice. SimDE is the first place in the NWChemEx Community stack which
assumes PluginPlay is being used and that the application is computational
chemistry. SimDE is thus a logical home for tutorials on developing
plugins/modules which leverage computational chemistry concepts.

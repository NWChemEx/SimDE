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

.. _simde_motivation:

################
SimDE Motivation
################

Historically scientific software has been developed somewhat *ad hoc*, i.e.,
without much attention to software engineering practices. Within computational
chemistry the situation is no different. Starting around the beginning of the
21st century there was an increasing realization that computational chemistry
software would tremendously benefit from writing modular and reusable software
packages.

The power of modularity lies in its ability to encapsulate complexity. With
well defined interfaces, users of a piece of modular software need not know the
specifics of the software, i.e., they may treat it as a black-box. This
facilitates among other things:

- Use by non-experts.
- Reasoning about consuming code (reader doesn't get bogged down in details).
- Rapid prototyping (treat modules as building blocks for new algorithms).
- Adoption (code that is easier to use gets adopted faster).
- Reusability (easy to call from different contexts).

Compared to monolithic software packages, software packages assembled from
modular components can face unique challenges. In particular, if each modular
component is developed in relative isolation (e.g., little to no communication
among development teams) the resulting modules are unlikely to be compatible
with each other. Examples of compatibility issues can include the presence of
different:

- input/return orderings,
- data structures,
- implicit conventions,
- resource management strategies, and
- parallel runtime systems.

Left unchecked, developers and maintainers can quickly spend a significant
fraction of their time addressing incompatibilities, thereby negating the
benefits of writing modular software in the first place. Thankfully there is a
straightforward solution, i.e., community standards.

Ultimately the NWChemEx Community develops and maintains SimDE to provide a
resource for members of the computational chemistry community who want to
develop modular software and ensure that software is compatible with other
modular software within the NWChemEx Community.

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

Arguably the largest disadvantage of modular software is that without community
standards developers are unlikely to develop compatible software. In other
words, if each developer writes their modules in isolation, it is very likely
that the resulting modules will rely on different data layouts, argument orders,
conventions, etc. This pitfall is avoided by creating modular software as a
community and adhering to community standards.

As a community it

Many of these pitfalls of modularity can be avoided by adhering to community
standards for data classes and module interfaces.

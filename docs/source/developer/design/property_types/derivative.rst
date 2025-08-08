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

.. _design_of_derivative_property_types:

###################################
Design of Derivative Property Types
###################################

TODO: Motivate need for computing derivatives (i.e., explain why calculus
exists).

*************************
Derivative Considerations
*************************

For simplicity let ``PT`` be the property type of the quantity we want the
derivative of and ``Derivative<PT>`` be the property type for computing the
derivative of ``PT``.

- Common to think about energy with respect to nuclear coordinates, but even
  that can be chain ruled to for example include derivatives involving molecular
  orbital coefficients.
- ``PT`` may return multiple quantities. In this case ``Derivative<PT>`` should
  return the derivative of each quantity.
- ``Derivative<PT>`` minimally needs the same inputs as ``PT``.
- Thinking of the derivative in Leibniz notation (quotient of two
  differentials), the choice for the numerator is fixed by the return(s) of
  ``PT``; there are however an infinite number of choices for the denominator.
  We thus need a mechanism for specifying the denominator.

  - As a corollary, the choice of practical denominators should be limited by
    the inputs to ``PT``, i.e., if you try to take the derivative of ``PT`` with
    respect to a quantity that ``PT`` does not depend on the value is 0.

    - As a corollary to the corollary, one may conceivably want to take the
      derivative with respect to a piece of an input, or an internal quantity
      which stems from an input. An example is the nuclear gradient where the
      input is a ``ChemicalSystem``, but we only want the derivative with
      respect to nuclear coordinates (an object of type ``PointSet``).

  - Will need to specify the value at which to take the derivative, i.e. need to
    take as an input an object of the denominator type.

- Consistent with general PT philosophy PTs should be for one derivative at a
  time, e.g., if one wants say the kinetic energy gradient with respect to the
  nuclear positions and the nuclear gradient of the electron-nuclear attraction
  this should be two separate PTs.

  - Can rely on memoization and satisfying multiple PTs to avoid duplicate
    work.

- Ambiguity arises when/if we are taking the derivative with respect to an
  object of type ``T`` and ``PT`` takes more than one ``T``.

  - Could decorate ``T``, e.g., ``WithRespectTo<1, T>`` means take the
    derivative with respect to the second ``T`` object (recall C++ is 0-based).
  - Could use strong types. Say the first ``T`` is the old one and the second
    ``T`` is the new one, then could make a type ``NewT`` which represents the
    second ``T`` and use that instead of ``T``.

*****************
Derivative Design
*****************

  - Decided on ``Derivative<PropertyType, WithRespectTo, ReturnType>``.

    - ``PropertyType`` defines the quantity (and the API for obtaining the
      quantity) we are taking the derivative of, i.e., the numerator in Leibniz
      notation.
    - ``WithRespectTo`` defines the quantity the derivative is with respect to,
      i.e., the denominator in Leibniz notation.
    - ``ReturnType`` is how the derivative is returned. Eventually this Will
      default to our tensor object, but in the mean time we leave it up to the
      downstream modules to decide.

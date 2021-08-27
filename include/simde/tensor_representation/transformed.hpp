#pragma once
#include "simde/types.hpp"

namespace simde {

using TransformedERI3 = TransformedTensorRepresentation<3, type::el_el_coulomb>;
using TransformedERI4 = TransformedTensorRepresentation<4, type::el_el_coulomb>;
using TransformedExchange = TransformedTensorRepresentation<2, type::el_scf_k>;
using TransformedF12Commutator =
  TransformedTensorRepresentation<4, type::el_el_f12_commutator>;
using TransformedFock = TransformedTensorRepresentation<2, type::fock>;
using TransformedSTG4 = TransformedTensorRepresentation<4, type::el_el_stg>;
using TransformedYukawa4 =
  TransformedTensorRepresentation<4, type::el_el_yukawa>;

} // namespace simde

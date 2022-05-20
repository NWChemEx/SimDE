#pragma once
#include "simde/tensor_representation/general_transformed_tensor_representation.hpp"
#include "simde/types.hpp"
namespace simde {

using TransformedERI3 = TransformedTensorRepresentation<3, type::el_el_coulomb>;
using TransformedERI4 = TransformedTensorRepresentation<4, type::el_el_coulomb>;
using TransformedExchange = TransformedTensorRepresentation<2, type::el_scf_k>;
using TransformedF12Commutator =
  TransformedTensorRepresentation<4, type::el_el_f12_commutator>;
using TransformedFock = TransformedTensorRepresentation<2, type::fock>;
using TransformedOverlap =
  TransformedTensorRepresentation<2, type::el_identity>;
using TransformedSTG4 = TransformedTensorRepresentation<4, type::el_el_stg>;
using TransformedYukawa4 =
  TransformedTensorRepresentation<4, type::el_el_yukawa>;

using TransformedLocalERI4 =
  GeneralTransformedTensorRepresentation<4, type::el_el_coulomb>;

using TransformedLocalOverlap =
  GeneralTransformedTensorRepresentation<2, type::el_identity>;

using EOverlap_Nuclear =
  ContractedTensorRepresentation<type::el_identity_nuc>;

using EKinetic_Nuclear =
  ContractedTensorRepresentation<type::el_kinetic_nuc>;

using ENuclear_Nuclear =
  ContractedTensorRepresentation<type::el_nuc_coulomb_nuc>;

using ENRE_Nuclear =
  ContractedTensorRepresentation<type::nuc_coulomb_nuc>;

using EERI_Nuclear =
  ContractedTensorRepresentation<type::el_el_coulomb_nuc>;

} // namespace simde

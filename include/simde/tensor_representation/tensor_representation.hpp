#pragma once
#include "simde/tensor_representation/ao_integrals.hpp"
#include "simde/tensor_representation/ao_tensor_representation.hpp"
#include "simde/tensor_representation/correlation_energy.hpp"
#include "simde/tensor_representation/general_ao_tensor_representation.hpp"
#include "simde/tensor_representation/general_transformed_tensor_representation.hpp"
#include "simde/tensor_representation/tensor_representation_fxn.hpp"
#include "simde/tensor_representation/transformed.hpp"
#include "simde/tensor_representation/transformed_tensor_representation.hpp"
#include "simde/tensor_representation/type_traits.hpp"
#include "simde/tensor_representation/wavefunction_energy.hpp"

namespace simde {

template<typename T>
using space_map_t = typename detail_::TensorRepTraits<T>::map_type;

using WfEnergy = WavefunctionEnergy<type::canonical_reference>;
using CanonicalCorrelationEnergy =
  CorrelationEnergy<type::canonical_reference, type::canonical_many_body>;

} // namespace simde

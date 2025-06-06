/*
 * Copyright 2022 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <pluginplay/property_type/property_type.hpp>
#include <simde/types.hpp>

namespace simde {

template<typename BraKetType>
DECLARE_TEMPLATED_PROPERTY_TYPE(EvaluateBraKet, BraKetType);

template<typename BraKetType>
TEMPLATED_PROPERTY_TYPE_INPUTS(EvaluateBraKet, BraKetType) {
    using const_braket_t = const BraKetType&;
    return pluginplay::declare_input().add_field<const_braket_t>("BraKet");
}

template<typename BraKetType>
TEMPLATED_PROPERTY_TYPE_RESULTS(EvaluateBraKet, BraKetType) {
    using result_type = typename BraKetType::result_type;
    return pluginplay::declare_result().add_field<result_type>(
      "tensor representation");
}

template<typename BraType, typename OpType, typename KetType>
using eval_braket = EvaluateBraKet<type::braket<BraType, OpType, KetType>>;

#define EBK(bra, op, ket) eval_braket<bra, op, ket>

using aos_op_base_aos = EBK(type::aos, type::op_base_type, type::aos);
using aos_s_e_aos     = EBK(type::aos, type::s_e_type, type::aos);
using aos_t_e_aos     = EBK(type::aos, type::t_e_type, type::aos);
using aos_v_en_aos    = EBK(type::aos, type::v_en_type, type::aos);
using aos_h_e_aos     = EBK(type::aos, type::core_hamiltonian, type::aos);
using aos_f_e_aos     = EBK(type::aos, type::fock, type::aos);
using aos_j_e_aos     = EBK(type::aos, type::j_e_type, type::aos);
using aos_k_e_aos     = EBK(type::aos, type::k_e_type, type::aos);
using aos_xc_e_aos    = EBK(type::aos, type::xc_e_type, type::aos);

// One electron density templated on the representation of the density operator
template<typename OrbitalType>
using aos_rho_e_aos = EBK(type::aos, type::rho_e<OrbitalType>, type::aos);

using ERI2 = EBK(type::aos, type::v_ee_type, type::aos);
using ERI3 = EBK(type::aos, type::v_ee_type, type::aos_squared);
using ERI4 = EBK(type::aos_squared, type::v_ee_type, type::aos_squared);

template<typename OrbitalType>
using ESCF = EBK(type::determinant<OrbitalType>, type::hamiltonian,
                 type::determinant<OrbitalType>);
#undef EBK

} // namespace simde

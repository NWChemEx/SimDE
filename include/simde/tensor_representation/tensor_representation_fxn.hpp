#pragma once
#include "simde/tensor_representation/detail_/ao_dispatch.hpp"
#include "simde/tensor_representation/detail_/split_basis_op.hpp"
#include "simde/tensor_representation/detail_/tensor_rep_parser.hpp"
#include "simde/tensor_representation/general_ao_tensor_representation.hpp"
#include "simde/tensor_representation/general_transformed_tensor_representation.hpp"
#include "simde/tensor_representation/transformed_tensor_representation.hpp"
#include "simde/types.hpp"
#include <libchemist/libchemist.hpp>

namespace simde {

/** @brief Syntactic sugar for computing a tensor filled with integrals.
 *
 *  Quantum chemistry deals with a lot of tensors. Standard notation represents
 *  an element of the tensor using braket notation with one index per mode. The
 *  index used typically corresponds to the basis set for that mode (*e.g.*, it
 *  is common to use i,j,k... for occupied MOs and a,b,c... for virtual MOs).
 *  In the spirit of the standard notation, the tensor_representation function
 *  allows a user to request an integral tensor by specifying the basis sets
 *  for each mode of the tensor (and the operator). For example,
 *
 *  @code
 *  auto i     = get_occupied_orbitals();
 *  auto a     = get_virtual_orbitals();
 *  auto r_hat = get_dipole_operator();
 *  auto mod   = get_dipole_module();
 *
 *  auto [r_ia] = tensor_representation(mod, i, r_hat, a);
 *  @endcode
 *
 *  would compute the transition dipole moment. The underlying modules will
 *  automatically take care of building and transforming the integrals as
 *  needed (re-using them when possible); you just have to use the result!!!
 *
 *  @tparam Args The types of the arguments being used to specify the integral.
 *               For an N-center integral there should be N+1 types in parameter
 *               pack (the types of the basis functions for each of the N
 *               centers plus the type of the operator). Types are expected to
 *               be orbital spaces or derived from libchemist::OperatorBase.
 *
 * @param[in] mod The module which actually computes the integral.
 *
 * @param[in] args The specification of the integral. For two-electron integrals
 *                 chemist notation is used ("bra" indices are for electron 1,
 *                 "ket" indices are for electron 2).
 *
 * @return The tensor representation of the operator, in the specified basis
 *         set.
 *
 * @throw std::runtime_error if we can't figure out what integral you are trying
 *                           to compute. Strong throw guarantee.
 */
template<typename... Args>
auto tensor_representation(pluginplay::Module& mod, const Args&... args) {
    constexpr auto n_add_args = sizeof...(Args); // # of additional arguments
    constexpr auto n_center   = n_add_args - 1;  // One arg is an operator

    // Basic compile-time error checking
    static_assert(n_center >= 2, "Minimally must be a two-center integral");
    static_assert(n_center <= 4, "Only support up to four-center integrals");

    auto&& [op, bases] = detail_::split_basis_op(args...);

    constexpr bool has_dependent =
      (libchemist::orbital_space::is_dependent_v<std::decay_t<Args>> || ...);

    constexpr bool has_independent =
      (libchemist::orbital_space::is_independent_v<std::decay_t<Args>> || ...);

    constexpr bool makes_tot = has_dependent || has_independent;

    detail_::TensorRepParser p(bases);

    const auto n_ao_spaces          = p.m_ao_spaces.size();
    const auto n_sparse_ao_spaces   = p.m_sparse_ao_spaces.size();
    const auto n_derived_spaces     = p.m_derived_spaces.size();
    const auto n_ind_spaces         = p.m_ind_spaces.size();
    const auto n_dep_spaces         = p.m_dep_spaces.size();
    const auto total_ao             = n_ao_spaces + n_sparse_ao_spaces;
    const auto total_sparse_derived = n_ind_spaces + n_dep_spaces;

    const bool all_ao    = (n_center == n_ao_spaces);
    const bool sparse_ao = (n_center == total_ao);
    const bool derived   = (n_center == (n_ao_spaces + n_derived_spaces));
    const bool sparse    = (n_center == (total_ao + total_sparse_derived));

    using op_type = std::decay_t<decltype(op)>;

    if constexpr(makes_tot) {
        if(sparse_ao) {
            using pt = GeneralAOTensorRepresentation<op_type>;
            return mod.run_as<pt>(p.m_ao_spaces, p.m_sparse_ao_spaces, op);
        } else if(sparse) {
            using pt = GeneralTransformedTensorRepresentation<op_type>;
            return mod.run_as<pt>(p.m_ao_spaces, p.m_sparse_ao_spaces,
                                  p.m_ind_spaces, p.m_dep_spaces, op);
        } else {
            throw std::runtime_error("Unrecognized scenario");
        }
    } else {
        if(all_ao) {
            return detail_::ao_dispatch<n_center, op_type>(mod, p.m_ao_spaces,
                                                           op);
        } else if(derived) {
            using pt = TransformedTensorRepresentation<op_type>;
            return mod.run_as<pt>(p.m_ao_spaces, p.m_derived_spaces, op);
        } else {
            throw std::runtime_error("Unrecognized scenario");
        }
    }
}

} // namespace simde

#pragma once
#include "simde/tensor_representation/detail_/ao_dispatch.hpp"
#include "simde/tensor_representation/detail_/split_basis_op.hpp"
#include "simde/tensor_representation/detail_/tensor_rep_parser.hpp"
#include "simde/tensor_representation/general_ao_tensor_representation.hpp"
#include "simde/tensor_representation/general_transformed_tensor_representation.hpp"
#include "simde/tensor_representation/transformed_tensor_representation.hpp"
#include "simde/types.hpp"

namespace simde {

template<typename... Args>
auto tensor_representation(pluginplay::Module& mod, const Args&... args) {
    constexpr auto n_add_args = sizeof...(Args); // # of additional arguments
    constexpr auto n_center   = n_add_args - 1;  // One arg is an operator

    // Basic compile-time error checking
    static_assert(n_center >= 2, "Minimally must be a two-center integral");
    static_assert(n_center <= 4, "Only support up to four-center integrals");

    auto& [op, bases] = detail_::split_basis_op(args...);

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

    if(all_ao) {
        return detail_::ao_dispatch<n_center, op_type>(mod, p.m_ao_spaces, op);
    } else if(sparse_ao) {
        using pt = GeneralAOTensorRepresentation<op_type>;
        return mod.run_as<pt>(p.m_ao_spaces, p.m_sparse_ao_spaces, op);
    } else if(derived) {
        using pt = TransformedTensorRepresentation<op_type>;
        return mod.run_as<pt>(p.m_ao_spaces, p.m_derived_spaces, op);
    } else if(sparse) {
        using pt = GeneeralTransformedTensorRepresentation<op_type>;
        return mod.run_as<pt>(p.m_ao_spaces, p.m_sparse_ao_spaces,
                              p.m_ind_spaces, p.m_dep_spaces, op);
    } else {
        throw std::runtime_error("Unrecognized scenario");
    }
}

} // namespace simde

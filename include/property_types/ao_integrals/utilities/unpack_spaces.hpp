#pragma once
#include "property_types/ao_integrals/n_center.hpp"
#include "property_types/types.hpp"

namespace property_types::ao_integrals {

/** @brief Given the inputs to a module unpacks the spaces for the integral.
 *
 *  This function wraps the logic required to unpack the spaces provided to an
 *  integral module.
 *
 *  @tparam N The number of centers in the integral
 *  @tparam ElementType The scalar type used for basis set parameters.
 *
 *  @input[in] inputs The input map provided to the module. The spaces will be
 *                    unpacked from this object.
 *
 *  @return An std::vector whose elements are spaces for the integrals. The
 *          orderis left to right across the braket, e.g., the return for the
 *          ERI integral (i|ab) would be the space for i, the space for a, and
 *          then the space for b.
 *
 *  @throw std::bad_alloc if there is insufficient memory to create the return.
 *                        Strong throw guarantee.
 *  @throw std::runtime_error if the inputs do not contain the correct keys.
 *                            Strong throw guarantee.
 */
template<std::size_t N, typename ElementType>
auto unpack_spaces(const sde::type::input_map& inputs) {
    using n_center_t = NCenter<N, ElementType>;
    using ao_vec_t   = std::vector<type::ao_space_t<ElementType>>;

    if constexpr(N == 2) {
        const auto& [b, k] = n_center_t::unwrap_inputs(inputs);
        return ao_vec_t{b, k};
    } else if constexpr(N == 3) {
        const auto& [b, k1, k2] = n_center_t::unwrap_inputs(inputs);
        return ao_vec_t{b, k1, k2};
    } else if constexpr(N == 4) {
        const auto& [b1, b2, k1, k2] = n_center_t::unwrap_inputs(inputs);
        return ao_vec_t{b1, b2, k1, k2};
    } else {
        // Can't get here b/c n_center_t would fail to compile
    }
}

} // namespace property_types::ao_integrals
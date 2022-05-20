#pragma once

namespace simde {

template<std::size_t N, typename OperatorType>
class AO_NuclearTileRepresentation;

template<typename T>
struct NCenters;

template<std::size_t N, typename OperatorType>
struct NCenters<AO_NuclearTileRepresentation<N, OperatorType>>
  : std::integral_constant<std::size_t, N> {};

template<typename T>
struct OperatorType;

template<std::size_t N, typename OpType>
struct OperatorType<AO_NuclearTileRepresentation<N, OpType>> {
    using type = OpType;
};

template<typename T>
static constexpr std::size_t n_centers_v = NCenters<T>::value;

template<typename T>
using operator_t = typename OperatorType<T>::type;

} // namespace simde

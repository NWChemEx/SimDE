#include "property_types/embedding_partition.hpp"

namespace property_types {

template class EmbedPartition<double>;
template class EmbedPartition<double, type::derived_space_t<double>>;
template class EmbedPartition<double, type::canonical_space_t<double>>;
template class EmbedPartition<float>;
template class EmbedPartition<float, type::derived_space_t<float>>;
template class EmbedPartition<float, type::canonical_space_t<float>>;

} // namespace property_types

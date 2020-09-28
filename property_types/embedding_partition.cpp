#include "property_types/embedding_partition.hpp"

namespace property_types {

template class EmbedPartition<double>;
template class EmbedPartition<double, type::orthogonal_orbs<double>>;
template class EmbedPartition<double, type::canonical_mos<double>>;
template class EmbedPartition<float>;
template class EmbedPartition<float, type::orthogonal_orbs<float>>;
template class EmbedPartition<float, type::canonical_mos<float>>;

} // namespace property_types

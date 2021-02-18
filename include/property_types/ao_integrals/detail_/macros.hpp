#pragma once

#define MULTICENTER_AO_INTEGRAL_TYPEDEFS(PT_NAME)          \
    template<typename ElementType>                         \
    using PT_NAME##2C = PT_NAME<TwoCenter<ElementType>>;   \
                                                           \
    template<typename ElementType>                         \
    using PT_NAME##3C = PT_NAME<ThreeCenter<ElementType>>; \
                                                           \
    template<typename ElementType>                         \
    using PT_NAME##4C = PT_NAME<FourCenter<ElementType>>

#define MULTICENTER_AO_INTEGRAL_EXTERNS(PT_NAME)        \
    extern template class PT_NAME<TwoCenter<double>>;   \
    extern template class PT_NAME<TwoCenter<float>>;    \
    extern template class PT_NAME<ThreeCenter<double>>; \
    extern template class PT_NAME<ThreeCenter<float>>;  \
    extern template class PT_NAME<FourCenter<double>>;  \
    extern template class PT_NAME<FourCenter<float>>
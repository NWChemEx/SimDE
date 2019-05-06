set(PROP_TYPE_INCLUDES aointegral.hpp
                       types.hpp
)

cpp_add_library(
    property_types
    INCLUDES ${PROP_TYPE_INCLUDES}
    DEPENDS sde::sde CMakeBuild tamm libchemist
)


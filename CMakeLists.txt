cmake_minimum_required(VERSION 3.10)
project(property_types VERSION 1.0.0)

set(
    CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake"
    CACHE STRING "" FORCE
)

include(get_cpp)

### Options ###
option(BUILD_TESTING "Should we build the tests?" OFF)
option(BUILD_PYBINDINGS "Should we build Python3 bindings?" ON)

cpp_find_or_build_dependency(
    NAME CMakeBuild
    URL github.com/NWChemEx-Project/CMakeBuild
    PRIVATE
    CMAKE_ARGS BUILD_TESTS=OFF
)

cpp_find_or_build_dependency(
    NAME tamm
    URL github.com/NWChemEx-Project/TAMM
    PRIVATE
    DEPENDS CMakeBuild
    CMAKE_ARGS BUILD_TESTS=OFF
)

cpp_find_or_build_dependency(
    NAME sde
    URL github.com/NWChemEx-Project/SDE
    PRIVATE
    CMAKE_ARGS BUILD_TESTS=OFF
)

cpp_find_or_build_dependency(
    NAME libchemist
    URL github.com/NWChemEx-Project/LibChemist
    PRIVATE
    CMAKE_ARGS BUILD_TESTS=OFF
)

cpp_add_library(
    property_types
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/libproperty_types"
    INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/libproperty_types"
    DEPENDS nwx::sde libchemist tamm
)

### Testing ###
if("${BUILD_TESTING}")
    cpp_find_or_build_dependency(
        Catch2
        URL github.com/catchorg/Catch2
        BUILD_TARGET Catch2
        FIND_TARGET Catch2::Catch2
    )
    cpp_add_tests(
        test_property_types
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/tests"
        INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/libproperty_types"
        DEPENDS Catch2::Catch2 property_types
    )
endif()

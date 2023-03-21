# Copyright 2022 NWChemEx-Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.14)
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/version.txt" VERSION)
project(simde VERSION "${VERSION}" LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        nwx_cmake
        GIT_REPOSITORY https://github.com/NWChemEx-Project/NWXCMake
)
FetchContent_MakeAvailable(nwx_cmake)
list(APPEND CMAKE_MODULE_PATH "${nwx_cmake_SOURCE_DIR}/cmake")

set(
    CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake"
    CACHE STRING "" FORCE
)

include(get_cpp)
include(nwx_cxx_api_docs)

nwx_cxx_api_docs("${CMAKE_CURRENT_SOURCE_DIR}/src" 
                 "${CMAKE_CURRENT_SOURCE_DIR}/include")

### Options ###
option(BUILD_TESTING "Should we build the tests?" OFF)
option(BUILD_PYBINDINGS "Should we build Python3 bindings?" ON)

cpp_find_or_build_dependency(
    chemist
    URL github.com/NWChemEx-Project/chemist
    PRIVATE TRUE
    BUILD_TARGET chemist
    FIND_TARGET nwx::chemist
    CMAKE_ARGS BUILD_TESTING=OFF
)

cpp_find_or_build_dependency(
    pluginplay
    URL github.com/NWChemEx-Project/pluginplay
    PRIVATE TRUE
    BUILD_TARGET pluginplay
    FIND_TARGET nwx::pluginplay
    CMAKE_ARGS BUILD_TESTING=OFF
)

cpp_add_library(
    ${PROJECT_NAME}
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/${PROJECT_NAME}"
    INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME}"
    DEPENDS nwx::chemist nwx::pluginplay
)

include(nwx_python_mods)
cppyy_make_python_package(PACKAGE simde NAMESPACES simde DEPPACKAGES chemist pluginplay )

if("${BUILD_TESTING}")
    cpp_find_or_build_dependency(
        Catch2
        URL github.com/catchorg/Catch2
        BUILD_TARGET Catch2
        VERSION v2.x
        FIND_TARGET Catch2::Catch2
    )
    cpp_add_tests(
        test_${PROJECT_NAME}
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/tests/${PROJECT_NAME}"
        INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/${PROJECT_NAME}"
        DEPENDS Catch2::Catch2 ${PROJECT_NAME}
    )
endif()

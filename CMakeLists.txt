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

#Downloads common CMake modules used throughout NWChemEx
include(cmake/get_nwx_cmake.cmake)

#Sets the version to whatever git thinks it is
include(get_version_from_git)
get_version_from_git(simde_version "${CMAKE_CURRENT_LIST_DIR}")
project(simde VERSION "${simde_version}" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include(get_cmaize)
include(nwx_cxx_api_docs)

### Paths ###
set(SIMDE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SIMDE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SIMDE_TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(SIMDE_EXP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/experimental")

nwx_cxx_api_docs("${SIMDE_SOURCE_DIR}" "${SIMDE_INCLUDE_DIR}")

### Options ###
cmaize_option_list(
    BUILD_TESTING OFF "Should we build the tests?"
    BUILD_PYBIND11_PYBINDINGS ON "Build pybind11 python3 bindings?"
    ENABLE_SIGMA OFF "Should we enable Sigma for uncertainty tracking?"
)

include(get_chemist)

include(get_pluginplay)

cmaize_add_library(
    ${PROJECT_NAME}
    SOURCE_DIR "${SIMDE_SOURCE_DIR}/${PROJECT_NAME}"
    INCLUDE_DIRS "${SIMDE_INCLUDE_DIR}/${PROJECT_NAME}"
    DEPENDS chemist pluginplay
)

# N.B. this is a no-op if BUILD_PYBIND11_PYBINDINGS is not turned on
include(nwx_pybind11)
nwx_add_pybind11_module(
    ${PROJECT_NAME}
    SOURCE_DIR "${SIMDE_SOURCE_DIR}/python"
    DEPENDS "${PROJECT_NAME}"
)

if("${BUILD_TESTING}")
    set(CXX_TEST_DIR ${SIMDE_TESTS_DIR}/cxx)
    set(PYTHON_TEST_DIR ${SIMDE_TESTS_DIR}/python)

    include(get_catch2)

    cmaize_add_tests(
        test_unit_${PROJECT_NAME}
        SOURCE_DIR "${CXX_TEST_DIR}/unit_tests"
        INCLUDE_DIRS "${SIMDE_SOURCE_DIR}/${PROJECT_NAME}"
        DEPENDS Catch2 ${PROJECT_NAME}
    )

    # N.B. these are no-ops if BUILD_PYBIND11_PYBINDINGS is not turned on
    nwx_pybind11_tests(
        py_simde "${PYTHON_TEST_DIR}/unit_tests/test_simde.py"
        SUBMODULES pluginplay chemist parallelzone
    )
endif()

cmaize_add_package(
    ${PROJECT_NAME} NAMESPACE nwx::
)

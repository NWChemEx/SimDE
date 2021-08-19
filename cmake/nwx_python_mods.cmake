# This function will skim a CMake target and create a file __init__.py that
# should be placed next to the shared library created by that target. This
# function assumes the target's:
#
# * public header files are in the ``PUBLIC_HEADER`` property
# * include paths are in the ``INTERFACE_INCLUDE_DIRECTORIES`` property
# * dependencies are targets and in the ``INTERFACE_LINK_LIBRAIRES`` property
#
#
# :param target: The target name we are creating bindings for. Must be a valid
#                target.
#
# :Additional Named Arguments:
#     * *NAMESPACE* - The C++ namespace that your bindings live in. Will be used
#       as the name of the Python module for the resulting package.
#     * *PREFIX* - The path relative to header include root. Typically the name
#       of the directory that the target was added in. Defaults to the directory
#       this function was called from (note it's just the directory,not the full
#       path).
#     * *OUTPUT_DIR* - The build-time directory where the resulting file should
#       be placed. By default assumed to be the binary directory with the PREFIX
#       appended to it.
function(cppyy_make_python_package _cmpp_target)
    #---------------------------------------------------------------------------
    #-------------------------Basic error-checking------------------------------
    #---------------------------------------------------------------------------
    if("${_cmpp_target}" STREQUAL "")
        message(FATAL_ERROR "Target name may not be empty.")
    endif()
    if(NOT TARGET ${_cmpp_target})
        message(FATAL_ERROR "${_cmpp_target} is not a target.")
    endif()

    #---------------------------------------------------------------------------
    #--------------------------Argument Parsing---------------------------------
    #---------------------------------------------------------------------------
    set(_cmpp_options NAMESPACE PREFIX OUTPUT_DIR TEST)
    cmake_parse_arguments(_cmpp "" "${_cmpp_options}" "" ${ARGN})
    if("${_cmpp_PREFIX}" STREQUAL "")
        get_filename_component(_cmpp_PREFIX ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
        string(TOLOWER ${_cmpp_PREFIX} _cmpp_PREFIX)
    endif()
    if("${_cmpp_OUTPUT_DIR}" STREQUAL "")
        set(_cmpp_OUTPUT_DIR "${CMAKE_BINARY_DIR}/PyNWChemEx")
    endif()

    #---------------------------------------------------------------------------
    #------------Collect the information we need off the target-----------------
    #---------------------------------------------------------------------------
    #List of include directories, usually a generator
    get_target_property(
            _cmpp_inc_dir ${_cmpp_target} SOURCE_DIR)
    #Add dependent libraries
    list(APPEND _cmpp_inc_dir ${utilities_SOURCE_DIR} ${libchemist_SOURCE_DIR}/include)
    list(APPEND _cmpp_inc_dir ${simde_SOURCE_DIR}/include ${pluginplay_SOURCE_DIR}/include)
    list(APPEND _cmpp_inc_dir ${parallelzone_SOURCE_DIR}/include)
    list(APPEND _cmpp_inc_dir ${cereal_SOURCE_DIR}/include ${BPHash_SOURCE_DIR})
    list(APPEND _cmpp_inc_dir ${MADNESS_SOURCE_DIR}/src ${MADNESS_BINARY_DIR}/src)
    if(${BTAS_USE_BLAS_LAPACK} STREQUAL "ON")
        set(_cmpp_def_file_name "${_cmpp_OUTPUT_DIR}/NWX_defines.hpp")
        set(_cmpp_def_file "#define BTAS_HAS_BLAS_LAPACK\n")
        file(GENERATE OUTPUT ${_cmpp_def_file_name} CONTENT "${_cmpp_def_file}")
        list(APPEND _cmpp_inc_dir ${blaspp_BINARY_DIR}/include ${blaspp_SOURCE_DIR}/include)
        list(APPEND _cmpp_inc_dir ${lapackpp_SOURCE_DIR}/include)
    endif()
    list(APPEND _cmpp_inc_dir ${BTAS_SOURCE_DIR})
    list(APPEND _cmpp_inc_dir ${TiledArray_SOURCE_DIR}/src ${TiledArray_BINARY_DIR}/src)
    if(${TILEDARRAY_HAS_SCALAPACK})
        list(APPEND _cmpp_inc_dir ${blacspp_SOURCE_DIR}/include ${scalapackpp_SOURCE_DIR}/include)
    endif()
    list(APPEND _cmpp_inc_dir ${MPI_CXX_HEADER_DIR}) 
    get_property(EIGEN3_INCLUDE_DIRS TARGET TiledArray_Eigen PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
    list(APPEND _cmpp_inc_dir ${EIGEN3_INCLUDE_DIRS})
    #The library name (obviously a generator...)
    set(_cmpp_lib "$<TARGET_FILE_NAME:${_cmpp_target}>")

    #---------------------------------------------------------------------------
    #-----------------Generate __init__.py file contents------------------------
    #---------------------------------------------------------------------------
    set(_cmpp_file_name "${_cmpp_OUTPUT_DIR}/__init__.py")
    set(_cmpp_file "import cppyy\n\n")
    if(${BTAS_USE_BLAS_LAPACK} STREQUAL "ON")
        set(_cmpp_file "${_cmpp_file}cppyy.include(\"${_cmpp_def_file_name}\")\n")
    endif()
    foreach(_item ${_cmpp_inc_dir})
          set(_cmpp_file "${_cmpp_file}cppyy.add_include_path(\"${_item}\")\n")
    endforeach()
    set(_cmpp_file "${_cmpp_file}cppyy.cppdef(\"\"\"\\ \n")
    set(_cmpp_file "${_cmpp_file}\#define thread_local\n")
    set(_cmpp_file "${_cmpp_file}\#define is_server_thread \*_cling_is_server_thread()\n")
    set(_cmpp_file "${_cmpp_file}\#include \"${MADNESS_SOURCE_DIR}/src/madness/world/worldrmi.h\"\n")
    set(_cmpp_file "${_cmpp_file}\#undef thread_local\n")
    set(_cmpp_file "${_cmpp_file}\"\"\")\n")
    set(_cmpp_file "${_cmpp_file}cppyy.include(\"${libchemist_SOURCE_DIR}/include/libchemist/libchemist.hpp\")\n")
    set(_cmpp_file "${_cmpp_file}cppyy.include(\"${pluginplay_SOURCE_DIR}/include/pluginplay/module_manager.hpp\")\n")
    set(_cmpp_file "${_cmpp_file}cppyy.include(\"${simde_SOURCE_DIR}/include/simde/types.hpp\")\n")
    set(_cmpp_file "${_cmpp_file}\ncppyy.load_library(\"${CMAKE_BINARY_DIR}/${_cmpp_lib}\")\n\n")
    set(_cmpp_file "${_cmpp_file}from cppyy.gbl import simde, pluginplay, libchemist, TA\n")
    set(_cmpp_file "${_cmpp_file}from cppyy.gbl.std import array, vector\n")
    set(_cmpp_file "${_cmpp_file}from ctypes import c_int\n\n")
    set(_cmpp_file "${_cmpp_file}if not TA.initialized():\n")
    set(_cmpp_file "${_cmpp_file}    world = TA.initialize(c_int(0),c_int(0),True)\n\n")
    set(_cmpp_file "${_cmpp_file}import atexit\n\n")
    set(_cmpp_file "${_cmpp_file}@atexit.register\n")
    set(_cmpp_file "${_cmpp_file}def finalizeTA():\n")
    set(_cmpp_file "${_cmpp_file}    TA.finalize()\n\n")
    set(_cmpp_file "${_cmpp_file}def pythonize_class(klass, name):\n")
    set(_cmpp_file "${_cmpp_file}    def x_init(self, *args, **kwds):\n")
    set(_cmpp_file "${_cmpp_file}        newargs = list(args)\n")
    set(_cmpp_file "${_cmpp_file}        for kw, value in kwds.items():\n")
    set(_cmpp_file "${_cmpp_file}            try:\n")
    set(_cmpp_file "${_cmpp_file}                newargs.append(getattr(klass, kw)(value))\n")
    set(_cmpp_file "${_cmpp_file}            except AttributeError as e:\n")
    set(_cmpp_file "${_cmpp_file}                break\n")
    set(_cmpp_file "${_cmpp_file}        else:\n")
    set(_cmpp_file "${_cmpp_file}            return self.__orig_init__(*newargs)\n")
    set(_cmpp_file "${_cmpp_file}        raise TypeError(\"__init__\(\) got an unexpected keyword argument \'\%s\'\" \% kw)\n\n")
    set(_cmpp_file "${_cmpp_file}    klass.__orig_init__ = klass.__init__\n")
    set(_cmpp_file "${_cmpp_file}    klass.__init__ = x_init\n\n")
    set(_cmpp_file "${_cmpp_file}cppyy.py.add_pythonization(pythonize_class, \"libchemist\")\n")
    #Write it out
    file(GENERATE OUTPUT ${_cmpp_file_name} CONTENT "${_cmpp_file}")
endfunction()

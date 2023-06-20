.. Copyright 2023 NWChemEx-Project
..
.. Licensed under the Apache License, Version 2.0 (the "License");
.. you may not use this file except in compliance with the License.
.. You may obtain a copy of the License at
..
.. http://www.apache.org/licenses/LICENSE-2.0
..
.. Unless required by applicable law or agreed to in writing, software
.. distributed under the License is distributed on an "AS IS" BASIS,
.. WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
.. See the License for the specific language governing permissions and
.. limitations under the License.

################
Installing SimDE
################

For the purposes of this tutorial we will assume you want to make a local
installation of SimDE (and its dependencies). To that end, we assume you have
created a directory ``nwx_workspace`` where you would like to install SimDE and
other NWChemEx projects. The full path to ``nwx_workspace`` will be denoted as
``${NWX_WORKSPACE}`` in the following code snippets.

***********************************
Pre-Requisites for Installing SimDE
***********************************

.. note::

   Pre-installing TiledArray is presently required to avoid RPATH issues. When
   those issues are resolved, pre-installing TiledArray will be optional.

Before we can build SimDE we must build TiledArray. TiledArray depends on
several common dependencies, dependencies it can not install. These
dependencies are:

- MPI (Ubuntu package: libopenmpi-dev)
- BLAS (Ubuntu package: libopenblas-dev)
- LAPACK (Ubuntu package: liblapack-dev)

For convenience we have listed the name of the Ubuntu package which provides the
dependency; however, we also stress that while packages provided by most package
managers will provide adequate performance, they usually suffer from a
performance penalty associated with their portability. Point being, if you are
doing performance critical work, you may want install these dependencies
yourself. Also note these are very common libraries in the HPC community and
are likely already installed (in a performant configuration) on most clusters
you may run on.

It is assumed that you have previously installed these dependencies and that
CMake is able to find these dependencies, either because they are installed to
a location where CMake looks by default (*e.g.*, ``/usr/lib``) or because you
will ensure that their install locations are part of ``CMAKE_PREFIX_PATH``.
To install TiledArray:

.. code-block:: terminal

   git clone https://github.com/valeevgroup/tiledarray
   cd tiledarray
   git checkout ${NWX_TILEDARRAY_VERSION}
   cmake -H. \
         -Bbuild \
         -DCMAKE_INSTALL_PREFIX:PATH=${NWX_WORKSPACE}/tiledarray \
         -DBUILD_SHARED_LIBS:BOOL=TRUE \
   	     -DCMAKE_INSTALL_RPATH="\$ORIGIN"
    cmake --build build --target install --parallel 2

where ``${NWX_TILEDARRAY_VERSION}`` should be replaced by the value of the
CMake variable specified `here <bit.ly/3pcmGme>`__ and you should feel free to
change the ``2`` on the last line to the number of CPU cores on your computer
(the ``2`` specifies how many CPU cores will be used to compile).

***********************
Installing SimDE Proper
***********************

After a successful installation of TiledArray we are ready to install SimDE
proper. First we obtain the source for SimDE:

.. code-block:: terminal

   git clone https://github.com/NWChemEx-Project/SimDE
   cd SimDE

Now we strongly recommend making a toolchain file (see
`here <bit.ly/43PXmBx>`__ for more details). We will assume that you have
called your toolchain file ``toolchain.cmake``, that you made it inside the
``SimDE`` directory you just cloned, and that the toolchain minimally contains:

.. code-block:: cmake

   set(NWX_WORKSPACE #[[The full path to nwx_workspace goes here #]])
   set(CMAKE_PREFIX_PATH ${NWX_WORKSPACE}/tiledarray)
   set(BUILD_PYBIND11_PYBINDINGS ON) # Highly recommended
   set(BUILD_SHARED_LIBRARIES TRUE)  # Needed for Python bindings

   # This is where NWChemEx Python modules will be installed
   set(NWX_MODULE_DIR ${NWX_WORKSPACE}/nwx_modules)

Now we are ready to compile SimDE:

.. code-block:: terminal

    cmake -H. \
         -Bbuild \
         -DCMAKE_INSTALL_PREFIX:PATH=${NWX_WORKSPACE}/simde \
         -DCMAKE_TOOLCHAIN_FILE:PATH=${PWD}/toolchain.cmake
    cmake --build build --target install --parallel 2

Here ``${PWD}`` is the full path to the current directory (this variable is set
by default by most Linux shells), and again you may increase ``2`` if your
system has more CPU cores available.

**********************
Hello World With SimDE
**********************

After executing the above commands you should have a working SimDE installation,
this can be tested by creating a Python script, ``run_simde.py``,  containing:

.. code-block:: python

   import simde

   print("Getting here means Python found SimDE, oh and Hello World!!!")


This script can then be run by:

.. code-block:: terminal

   PYTHONPATH=${NWX_WORKSPACE}/nwx_modules python3 run_simde.py

(assuming ``${NWX_WORKSPACE}`` isn't already included in your Python path).

*****************************
Troubleshooting SimDE Install
*****************************

The contents of the toolchain above are fairly minimal. Depending on how far
your system differs from ideality you may need to set additional variables. The
most common ones are:


- ``CMAKE_C_COMPILER``/ ``CMAKE_CXX_COMPILER`` the full path to your C and C++
  compilers, respectively.
- ``CMAIZE_GITHUB_TOKEN`` this needs to be set to a GitHub PAT while the
  NWChemEx repos are still private.
- ``Python3_EXECUTABLE`` point this to the Python command you want to use.

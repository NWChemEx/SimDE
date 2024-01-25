<!--
  ~ Copyright 2022 NWChemEx-Project
  ~
  ~ Licensed under the Apache License, Version 2.0 (the "License");
  ~ you may not use this file except in compliance with the License.
  ~ You may obtain a copy of the License at
  ~
  ~ http://www.apache.org/licenses/LICENSE-2.0
  ~
  ~ Unless required by applicable law or agreed to in writing, software
  ~ distributed under the License is distributed on an "AS IS" BASIS,
  ~ WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ~ See the License for the specific language governing permissions and
  ~ limitations under the License.
-->

![SimDE Logo](docs/source/assets/logo.png)

[Documentation](https://nwchemex.github.io/SimDE)

[![Citation Badge](https://api.juleskreuer.eu/citation-badge.php?doi=10.1109/MCSE.2018.2884921)](https://juleskreuer.eu/projekte/citation-badge/)

The Simulation Development Environment (SimDE) is the...

# Features

# Installation

SimDE ultimately uses CMake for configuring and building. This means that
installation is usually achieved via a variation on:

```.sh
git clone https://github.com/NWChemEx/simde
cd simde
cmake -H. -Bbuild -D...
cmake --build build --target install
```
More detailed install instructions can be found
[here](https://nwchemex.github.io/simde/install.html).

# Contributing

- [Contributor Guidelines](https://github.com/NWChemEx/.github/blob/1a883d64519f62da7c8ba2b28aabda7c6f196b2c/.github/CONTRIBUTING.md)
- [Contributor License Agreement](https://github.com/NWChemEx/.github/blob/master/.github/CONTRIBUTING.md#contributor-license-agreement-cla)
- [Developer Documentation](https://nwchemex.github.io/PluginPlay/developer/index.html)
- [Code of Conduct](https://github.com/NWChemEx/.github/blob/master/.github/CODE_OF_CONDUCT.md)

# Acknowledgments

This research was supported by the Exascale Computing Project (17-SC-20-SC), a collaborative effort of the U.S. Department of Energy Office of Science and the National Nuclear Security Administration.

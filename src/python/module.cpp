#include "energy/export_energy.hpp"
#include "export_simde.hpp"

namespace simde {

PYBIND11_MODULE(simde, m) {
    m.doc() =
      "PySimDE: Python bindings for the Simulation development environment";

    export_energy(m);
}

} // namespace simde

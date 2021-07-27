#pragma once

namespace simde {

DECLARE_MODULE(SystemHamiltonian);

MODULE_INPUTS(SystemHamiltonian) {
    using system = const type::chemical_system&;
    auto rv = pluginplay::declare_inputs().add_field<system>("Chemical System");
    return rv;
}

MODULE_RESULTS(SystemHamiltonian) {
    return pluginplay::declare_results().add_field<type::hamiltonian>(
      "Hamiltonian");
}

} // namespace simde

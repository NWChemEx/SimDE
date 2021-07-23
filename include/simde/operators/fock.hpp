#pragma once

namespace simde {

DECLARE_MODULE(Fock);

MODULE_INPUTS(Fock) {
    using ham         = const type::hamiltonian&;
    using tensor_type = const type::tensor&;

    auto rv = sde::declare_inputs()
                .add_field<ham>("System Hamiltonian")
                .template add_field<tensor_type>("Density");
    return rv;
}

MODULE_RESULTS(Fock) {
    return sde::declare_results().add_field<type::fock>("Fock operator");
}

} // namespace simde

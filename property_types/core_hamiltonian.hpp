#pragma once

namespace {

/**
 * @brief The base class for modules that build the core Hamiltonian in the AO
 * basis set.
 *
 */
template<typename element_type = double>
struct CoreHamiltonian : public SDE::PropertyType<CoreHamiltonian<element_type>> {
    using tensor_type    = tamm::Tensor<element_type>;
    using molecule_type  = Molecule;
    using basis_set_type = AOBasisSet;
    using size_type      = std::size_t;

    auto inputs_() {
        auto rv = SDE::declare_input().add_field<const molecule_type&>("Molecule")
          .add_field<const basis_set_type&>("Bra")
          .add_field<const basis_set_type&>("Ket")
          .add_field<size_type>("Derivative");
        rv["Molecule"].set_description("The molecule for which the Core Hamiltonian matrix is build");
        rv["Bra"].set_description("The basis set used for the bra of the Core Hamiltonian matrix");
        rv["Ket"].set_description("The basis set used for the ket of the Core Hamiltonian matrix");
        rv["Derivative"].set_description("The derivative order of the Core Hamiltonian matrix");
        return rv;
    }

    auto results_() {
        auto rv = SDE::declare_result().add_field<tensor_type>("Core Hamiltonian");
        rv["Core Hamiltonian"].set_description("The matrix of the computed Core Hamiltonian");
        return rv;
    }


} //End namespace

#pragma once

namespace property_types {

/**
 * @brief The base class for modules that build Fock matrices in the AO
 * basis set.
 *
 */

template<typename element_type = double>
struct FockBuilder : public SDE::PropertyType<FockBuilder<element_type>> {
    using tensor_type    = tamm::Tensor<element_type>;
    using molecule_type  = Molecule;
    using orbital_type   = OrbitalSpace<element_type>;
    using basis_set_type = AOBasisSet;
    using size_type      = std::size_t;

    auto inputs_() {
        auto rv = SDE::declare_input().add_field<const molecule_type&>("Molecule")
          .add_field<const orbital_type&>("Molecular Orbitals")
          .template add_field<const basis_set_type&>("Bra")
          .template add_field<const basis_set_type&>("Ket")
          .template add_field<size_type>("Derivative");
        rv["Molecule"].set_description("The molecule for which the Fock Matrix is build");
        rv["Molecular Orbitals"].set_description("The molecular orbitals used to build the Fock Matrix");
        rv["Bra"].set_description("The basis set used for the bra of the matrices and integrals");
        rv["Ket"].set_description("The basis set used for the ket of the matrices and integrals");
        rv["Derivative"].set_description("The derivative order of the Fock Matrix");
        return rv;
    }

    auto results_() {
        auto rv = SDE::declare_result().add_field<tensor_type>("Fock Matrix");
        rv["Fock Matrix"].set_description("The computed Fock Matrix");
        return rv;
    }

};

} //namespace property_types

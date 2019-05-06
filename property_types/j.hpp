#pragma once

namespace {

/**
 * @brief The base class for modules that build the J and K matrices in the AO
 * basis set.
 *
 * In order to take advantage of integral re-use J and K are typically built
 * together.  This class is designed to build a series of Js and Ks given a
 * series of densities.
 *
 */
template<typename element_type = double>
struct JKMatrices : public SDE::PropertyType<JKMatrices<element_type>> {
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
        rv["Molecule"].set_description("The molecule for which J and K matrices are build in AO basis");
        rv["Molecular Orbitals"].set_description("The molecular orbitals used to build the J and K matrices");
        rv["Bra"].set_description("The basis set used for the bra of the matrices and integrals");
        rv["Ket"].set_description("The basis set used for the ket of the matrices and integrals");
        rv["Derivative"].set_description("The derivative order of the J and K matrices");
        return rv;
    }

    auto results_() {
        auto rv = SDE::declare_result().add_field<tensor_type>("J Matrix")
          .template add_field<tensor_type>("K Matrix");
        rv["J Matrix"].set_description("The computed J Matrix");
        rv["K Matrix"].set_description("The computed K Matrix");
        return rv;
    }

};

} //End namespace

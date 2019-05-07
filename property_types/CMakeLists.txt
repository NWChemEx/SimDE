set(PROP_TYPE_INCLUDES aointegral.hpp
                       core_hamiltonian.hpp
                       coulomb_matrix.hpp
                       energy.hpp
                       exchange_matrix.hpp
                       fock_matrix.hpp
                       guess_density.hpp
                       reference_wavefunction.hpp
                       scf_iteration.hpp
                       types.hpp
                       update_guess.hpp
                       xc_quantities.hpp
)

cpp_add_library(
    property_types
    INCLUDES ${PROP_TYPE_INCLUDES}
    DEPENDS sde::sde CMakeBuild tamm libchemist::chemist
)


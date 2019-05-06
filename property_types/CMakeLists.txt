set(PROP_TYPE_INCLUDES aointegral.hpp
                       core_hamiltonian.hpp
                       energy.hpp
                       fock_matrix.hpp
                       guess_density.hpp
                       j.hpp
                       k.hpp
                       reference_wavefunction.hpp
                       types.hpp
                       update_guess.hpp
)

cpp_add_library(
    property_types
    INCLUDES ${PROP_TYPE_INCLUDES}
    DEPENDS sde::sde CMakeBuild tamm libchemist::chemist
)


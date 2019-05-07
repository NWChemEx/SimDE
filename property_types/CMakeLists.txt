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
set(PROP_TYPE_SOURCES aointegral.cpp
                      core_hamiltonian.cpp
                      coulomb_matrix.cpp
                      energy.cpp
                      exchange_matrix.cpp
                      fock_matrix.cpp
                      guess_density.cpp
                      reference_wavefunction.cpp
                      scf_iteration.cpp
                      update_guess.cpp
                      update_mos.cpp
                      xc_quantities.cpp
)

cpp_add_library(
    property_types
    SOURCES ${PROP_TYPE_SOURCES}
    INCLUDES ${PROP_TYPE_INCLUDES}
    DEPENDS sde::sde CMakeBuild tamm libchemist::chemist
)

cpp_install(TARGETS property_types)

set(PROP_TYPE_INCLUDES aointegral.hpp
                       bunchkaufman.hpp
                       cholesky.hpp
                       core_hamiltonian.hpp
                       coulomb_matrix.hpp
                       df_coefficients.hpp
                       differential_overlap_integral.hpp
                       eigen_solver.hpp
                       energy.hpp
                       exchange_matrix.hpp
                       fock_matrix.hpp
                       guess_density.hpp
                       linear_solver.hpp
                       localized_orbitals.hpp
                       lu.hpp
                       matrix_inverse.hpp
                       matrix_properties.hpp
                       qr.hpp
                       reference_wavefunction.hpp
                       scf_iteration.hpp
                       types.hpp
                       update_guess.hpp
                       update_mos.hpp
                       xc_quantities.hpp
)
set(PROP_TYPE_SOURCES aointegral.cpp
                      bunchkaufman.cpp
                      cholesky.cpp
                      core_hamiltonian.cpp
                      coulomb_matrix.cpp
                      df_coefficients.cpp
                      differential_overlap_integral.cpp
                      eigen_solver.cpp
                      energy.cpp
                      exchange_matrix.cpp
                      fock_matrix.cpp
                      guess_density.cpp
                      linear_solver.cpp
                      localized_orbitals.cpp
                      lu.cpp
                      matrix_inverse.cpp
                      qr.cpp
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

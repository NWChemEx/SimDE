set(PROP_TYPE_INCLUDES aointegral.hpp
                       core_hamiltonian.hpp
                       coulomb_matrix.hpp
                       df_coefficients.hpp
                       differential_overlap_integral.hpp
                       embedding_partition.hpp
                       energy.hpp
                       exchange_matrix.hpp
                       fock_matrix.hpp
                       guess_density.hpp
                       linear_algebra/eigen_solver.hpp
                       linear_algebra/hermitian_triangular_factorization.hpp
                       linear_algebra/linear_solver.hpp
                       linear_algebra/lu.hpp
                       linear_algebra/matrix_inverse.hpp
                       linear_algebra/matrix_properties.hpp
                       linear_algebra/positive_definite_triangular_factorization.hpp
                       linear_algebra/qr.hpp
                       localized_orbitals.hpp
                       reference_wavefunction.hpp
                       scf_iteration.hpp
                       singular_value_decomposition.hpp
                       types.hpp
                       update_guess.hpp
                       update_mos.hpp
                       xc_quantities.hpp
)
set(PROP_TYPE_SOURCES aointegral.cpp
                      core_hamiltonian.cpp
                      coulomb_matrix.cpp
                      df_coefficients.cpp
                      differential_overlap_integral.cpp
                      embedding_partition.cpp
                      energy.cpp
                      exchange_matrix.cpp
                      fock_matrix.cpp
                      guess_density.cpp
                      linear_algebra/eigen_solver.cpp
                      linear_algebra/hermitian_triangular_factorization.cpp
                      linear_algebra/linear_solver.cpp
                      linear_algebra/lu.cpp
                      linear_algebra/matrix_inverse.cpp
                      linear_algebra/positive_definite_triangular_factorization.cpp
                      linear_algebra/qr.cpp
                      localized_orbitals.cpp
                      reference_wavefunction.cpp
                      scf_iteration.cpp
                      singular_value_decomposition.cpp
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

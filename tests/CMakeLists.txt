set(TEST_SRCS test_main.cpp
              aointegral.cpp
              core_hamiltonian.cpp
              energy.cpp
              fock_matrix.cpp
              guess_density.cpp
              j.cpp
              k.cpp
              reference_wavefunction.cpp
              scf_iteration.cpp
              update_guess.cpp
              update_mos.cpp
              xc_quantities.cpp
)

cpp_add_executable(
    test_property_types
    SOURCES ${TEST_SRCS}
    DEPENDS property_types Catch2::Catch2
)

add_test(NAME test_property_types COMMAND test_property_types)

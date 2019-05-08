set(TEST_SRCS test_main.cpp
              aointegral.cpp
              core_hamiltonian.cpp
              coulomb_matrix.cpp
              energy.cpp
              exchange_matrix.cpp
              fock_matrix.cpp
              guess_density.cpp
              reference_wavefunction.cpp
              scf_iteration.cpp
              types.cpp
              update_guess.cpp
              update_mos.cpp
              xc_quantities.cpp
)

cpp_add_executable(
    test_property_types
    SOURCES ${TEST_SRCS}
    DEPENDS property_types Catch2::Catch2
)

target_include_directories(
    test_property_types PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_test(NAME test_property_types COMMAND test_property_types)

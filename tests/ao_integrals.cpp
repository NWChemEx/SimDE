#include "tests/test_property_type.hpp"
#include <property_types/ao_integrals/kinetic.hpp>
#include <property_types/ao_integrals/overlap.hpp>
#include <property_types/ao_integrals/nuclear.hpp>
#include <property_types/ao_integrals/emultipole.hpp>
#include <property_types/ao_integrals/electron_repulsion.hpp>
#include <property_types/ao_integrals/stg.hpp>
#include <property_types/ao_integrals/yukawa.hpp>

TEST_CASE("KineticIntegral"){
test_property_type<property_types::KineticIntegral<>>(
{"Molecule", "Bra", "Ket", "Derivative"},
{"Kinetic Integrals"}
);
}

TEST_CASE("OverlapIntegral"){
    test_property_type<property_types::OverlapIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative"},
            {"Overlap Integrals"}
    );
}

TEST_CASE("NuclearIntegral"){
    test_property_type<property_types::NuclearIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative"},
            {"Nuclear Integrals"}
    );
}

TEST_CASE("EDipoleIntegral"){
    test_property_type<property_types::EDipoleIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative", "Origin"},
            {"EDipole Integrals"}
    );
}

TEST_CASE("EQuadrupoleIntegral"){
    test_property_type<property_types::EQuadrupoleIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative", "Origin"},
            {"EQuadrupole Integrals"}
    );
}

TEST_CASE("EOctopoleIntegral"){
    test_property_type<property_types::EOctopoleIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative", "Origin"},
            {"EOctopole Integrals"}
    );
}

TEST_CASE("ERI2CIntegral"){
    test_property_type<property_types::ERI2CIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative"},
            {"ERIs"}
    );
}

TEST_CASE("ERI3CIntegral"){
    test_property_type<property_types::ERI3CIntegral<>>(
            {"Molecule", "Bra", "Ket1", "Ket2", "Derivative"},
            {"ERIs"}
    );
}

TEST_CASE("ERI4CIntegral"){
    test_property_type<property_types::ERI4CIntegral<>>(
            {"Molecule", "Bra1", "Bra2", "Ket1", "Ket2", "Derivative"},
            {"ERIs"}
    );
}

TEST_CASE("STG2CIntegral"){
    test_property_type<property_types::STG2CIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative", "STG Exponent"},
            {"STG Integrals"}
    );
}

TEST_CASE("STG3CIntegral"){
    test_property_type<property_types::STG3CIntegral<>>(
            {"Molecule", "Bra", "Ket1", "Ket2", "Derivative", "STG Exponent"},
            {"STG Integrals"}
    );
}

TEST_CASE("STG4CIntegral"){
    test_property_type<property_types::STG4CIntegral<>>(
            {"Molecule", "Bra1", "Bra2", "Ket1", "Ket2", "Derivative", "STG Exponent"},
            {"STG Integrals"}
    );
}

TEST_CASE("Yukawa2CIntegral"){
    test_property_type<property_types::Yukawa2CIntegral<>>(
            {"Molecule", "Bra", "Ket", "Derivative", "STG Exponent"},
            {"Yukawa Integrals"}
    );
}

TEST_CASE("Yukawa3CIntegral"){
    test_property_type<property_types::Yukawa3CIntegral<>>(
            {"Molecule", "Bra", "Ket1", "Ket2", "Derivative", "STG Exponent"},
            {"Yukawa Integrals"}
    );
}

TEST_CASE("Yukawa4CIntegral"){
    test_property_type<property_types::Yukawa4CIntegral<>>(
            {"Molecule", "Bra1", "Bra2", "Ket1", "Ket2", "Derivative", "STG Exponent"},
            {"Yukawa Integrals"}
    );
}
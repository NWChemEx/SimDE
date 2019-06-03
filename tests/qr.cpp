#include "test_property_type.hpp"
#include <property_types/qr.hpp>

TEST_CASE("QR"){
    test_property_type<property_types::QRFactorization<double>>(
      {"Input Matrix"},
      {"Q", "R"}
    );
}


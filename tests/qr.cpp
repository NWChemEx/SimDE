#include "test_property_type.hpp"
#include <property_types/linear_algebra/qr.hpp>

TEST_CASE("QR"){
    test_property_type<property_types::QRFactorization<double>>(
      {"Input Matrix"},
      {"Q", "R"}
    );
}


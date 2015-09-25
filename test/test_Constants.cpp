#include "common.h"

using namespace avidmath::constants;

TEST_CASE("Constants", "[Constants]")
{
    SECTION("Value of pi")
    {
        REQUIRE(pi<float>() == Approx(3.14159f));
        REQUIRE(pi<double>() == Approx(3.14159));
    }

    SECTION("Compile time evaluation")
    {
        REQUIRE(noexcept(pi<double>()));
    }
}


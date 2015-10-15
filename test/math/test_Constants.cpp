#include "../common.h"

using namespace ail::math;

TEST_CASE("Constants", "[Constants]")
{
    SECTION("Value of pi")
    {
        REQUIRE(pi<float>() == Approx(3.14159f));
        REQUIRE(pi<double>() == Approx(3.14159));
    }
}

// Check that all the constexpr functions can be evaluated at compile-time.
// A failure will typically result in an error message in the function itself.
static_assert(pi<float>() || true, "Compile-time evaluation check");


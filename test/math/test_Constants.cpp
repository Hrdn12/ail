/** \file test_Constants.cpp
    \brief Unit testing for the constant values.

    Depends on the Catch framework: https://github.com/philsquared/Catch

    Part of the Avid Insight Library (avidinsight.uk/ail).
    Copyright (C) 2015-16 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include "../common.h"

using namespace ail::math;

TEST_CASE("Constants", "[Constants]")
{
    SECTION("Value of pi")
    {
        CHECK(pi<float>() == Approx(3.14159f));
        CHECK(pi<double>() == Approx(3.14159));
    }
}

// Check that all the constexpr functions can be evaluated at compile-time.
// A failure will typically result in an error message in the function itself.
static_assert(pi<float>() || true, "Compile-time evaluation check");


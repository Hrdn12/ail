/** \file test_tmod.cpp
    \brief Unit testing for the mod template utility.

    Depends on the Catch framework: https://github.com/philsquared/Catch

    Part of the Avid Insight Library (avidinsight.uk/ail).
    Copyright (C) 2015-16 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include "../common.h"

using namespace ail::math;

TEST_CASE("tmod - templated modulus", "[tmod]")
{
    SECTION("Integer")
    {
        // No remainder.
        CHECK(tmod<int>::mod(0, 1) == 0);
        CHECK(tmod<int>::mod(35, 1) == 0);
        CHECK(tmod<int>::mod(-15, 1) == 0);
        CHECK(tmod<int>::mod(18, -1) == 0);
        CHECK(tmod<int>::mod(-26, -1) == 0);

        // Positive remainder.
        CHECK(tmod<int>::mod(13, 14) == 13);
        CHECK(tmod<int>::mod(13, -14) == 13);
        CHECK(tmod<int>::mod(14, 13) == 1);
        CHECK(tmod<int>::mod(14, -13) == 1);
        CHECK(tmod<int>::mod(6, 317) == 6);
        CHECK(tmod<int>::mod(6, -317) == 6);
        CHECK(tmod<int>::mod(317, 6) == 5);
        CHECK(tmod<int>::mod(317, -6) == 5);

        // Negative remainder.
        CHECK(tmod<int>::mod(-13, 14) == -13);
        CHECK(tmod<int>::mod(-13, -14) == -13);
        CHECK(tmod<int>::mod(-14, 13) == -1);
        CHECK(tmod<int>::mod(-14, -13) == -1);
        CHECK(tmod<int>::mod(-6, 317) == -6);
        CHECK(tmod<int>::mod(-6, -317) == -6);
        CHECK(tmod<int>::mod(-317, 6) == -5);
        CHECK(tmod<int>::mod(-317, -6) == -5);

        // Check that the function can be called with various types.
        CHECK(tmod<std::int8_t>::mod(3, 2) == 1);
        CHECK(tmod<std::uint8_t>::mod(3, 2) == 1);
        CHECK(tmod<std::int16_t>::mod(3, 2) == 1);
        CHECK(tmod<std::uint16_t>::mod(3, 2) == 1);
        CHECK(tmod<std::int32_t>::mod(3, 2) == 1);
        CHECK(tmod<std::uint32_t>::mod(3, 2) == 1);
        CHECK(tmod<std::int64_t>::mod(3, 2) == 1);
        CHECK(tmod<std::uint64_t>::mod(3, 2) == 1);
    }

    SECTION("Floating point")
    {
        // No remainder.
        CHECK(tmod<double>::mod(0.0, 1.0) == Approx(0.0));
        CHECK(tmod<double>::mod(42.0, 1.0) == Approx(0.0));
        CHECK(tmod<double>::mod(-83.0, 1.0) == Approx(0.0));
        CHECK(tmod<double>::mod(11.0, -1.0) == Approx(0.0));
        CHECK(tmod<double>::mod(-29.0, -1.0) == Approx(0.0));

        // Positive remainder.
        CHECK(tmod<double>::mod(29.35, 1.0) == Approx(0.35));
        CHECK(tmod<double>::mod(29.35, -1.0) == Approx(0.35));
        CHECK(tmod<double>::mod(5.02, 1.0) == Approx(0.02));
        CHECK(tmod<double>::mod(5.02, -1.0) == Approx(0.02));
        CHECK(tmod<double>::mod(37.6, 52.8) == Approx(37.6));
        CHECK(tmod<double>::mod(37.6, -52.8) == Approx(37.6));
        CHECK(tmod<double>::mod(52.8, 37.6) == Approx(15.2));
        CHECK(tmod<double>::mod(52.8, -37.6) == Approx(15.2));
        CHECK(tmod<double>::mod(251.93, 7.81) == Approx(2.01));
        CHECK(tmod<double>::mod(251.93, -7.81) == Approx(2.01));

        // Negative remainder.
        CHECK(tmod<double>::mod(-29.35, 1.0) == Approx(-0.35));
        CHECK(tmod<double>::mod(-29.35, -1.0) == Approx(-0.35));
        CHECK(tmod<double>::mod(-5.02, 1.0) == Approx(-0.02));
        CHECK(tmod<double>::mod(-5.02, -1.0) == Approx(-0.02));
        CHECK(tmod<double>::mod(-37.6, 52.8) == Approx(-37.6));
        CHECK(tmod<double>::mod(-37.6, -52.8) == Approx(-37.6));
        CHECK(tmod<double>::mod(-52.8, 37.6) == Approx(-15.2));
        CHECK(tmod<double>::mod(-52.8, -37.6) == Approx(-15.2));
        CHECK(tmod<double>::mod(-251.93, 7.81) == Approx(-2.01));
        CHECK(tmod<double>::mod(-251.93, -7.81) == Approx(-2.01));

        // Check that the function can be called with various types.
        CHECK(tmod<float>::mod(4.5f, 2.1f) == Approx(0.3f));
        CHECK(tmod<double>::mod(4.5, 2.1) == Approx(0.3));
        CHECK(tmod<long double>::mod(4.5, 2.1) == Approx(0.3));
    }
}

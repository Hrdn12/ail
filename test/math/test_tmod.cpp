#include "../common.h"

using namespace ail::math;

TEST_CASE("tmod - templated modulus", "[tmod]")
{
    SECTION("Integer")
    {
        // No remainder.
        REQUIRE(tmod<int>::mod(0, 1) == 0);
        REQUIRE(tmod<int>::mod(35, 1) == 0);
        REQUIRE(tmod<int>::mod(-15, 1) == 0);
        REQUIRE(tmod<int>::mod(18, -1) == 0);
        REQUIRE(tmod<int>::mod(-26, -1) == 0);

        // Positive remainder.
        REQUIRE(tmod<int>::mod(13, 14) == 13);
        REQUIRE(tmod<int>::mod(13, -14) == 13);
        REQUIRE(tmod<int>::mod(14, 13) == 1);
        REQUIRE(tmod<int>::mod(14, -13) == 1);
        REQUIRE(tmod<int>::mod(6, 317) == 6);
        REQUIRE(tmod<int>::mod(6, -317) == 6);
        REQUIRE(tmod<int>::mod(317, 6) == 5);
        REQUIRE(tmod<int>::mod(317, -6) == 5);

        // Negative remainder.
        REQUIRE(tmod<int>::mod(-13, 14) == -13);
        REQUIRE(tmod<int>::mod(-13, -14) == -13);
        REQUIRE(tmod<int>::mod(-14, 13) == -1);
        REQUIRE(tmod<int>::mod(-14, -13) == -1);
        REQUIRE(tmod<int>::mod(-6, 317) == -6);
        REQUIRE(tmod<int>::mod(-6, -317) == -6);
        REQUIRE(tmod<int>::mod(-317, 6) == -5);
        REQUIRE(tmod<int>::mod(-317, -6) == -5);

        // Check that the function can be called with various types.
        REQUIRE(tmod<std::int8_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::uint8_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::int16_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::uint16_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::int32_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::uint32_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::int64_t>::mod(3, 2) == 1);
        REQUIRE(tmod<std::uint64_t>::mod(3, 2) == 1);
    }

    SECTION("Floating point")
    {
        // No remainder.
        REQUIRE(tmod<double>::mod(0.0, 1.0) == Approx(0.0));
        REQUIRE(tmod<double>::mod(42.0, 1.0) == Approx(0.0));
        REQUIRE(tmod<double>::mod(-83.0, 1.0) == Approx(0.0));
        REQUIRE(tmod<double>::mod(11.0, -1.0) == Approx(0.0));
        REQUIRE(tmod<double>::mod(-29.0, -1.0) == Approx(0.0));

        // Positive remainder.
        REQUIRE(tmod<double>::mod(29.35, 1.0) == Approx(0.35));
        REQUIRE(tmod<double>::mod(29.35, -1.0) == Approx(0.35));
        REQUIRE(tmod<double>::mod(5.02, 1.0) == Approx(0.02));
        REQUIRE(tmod<double>::mod(5.02, -1.0) == Approx(0.02));
        REQUIRE(tmod<double>::mod(37.6, 52.8) == Approx(37.6));
        REQUIRE(tmod<double>::mod(37.6, -52.8) == Approx(37.6));
        REQUIRE(tmod<double>::mod(52.8, 37.6) == Approx(15.2));
        REQUIRE(tmod<double>::mod(52.8, -37.6) == Approx(15.2));
        REQUIRE(tmod<double>::mod(251.93, 7.81) == Approx(2.01));
        REQUIRE(tmod<double>::mod(251.93, -7.81) == Approx(2.01));

        // Negative remainder.
        REQUIRE(tmod<double>::mod(-29.35, 1.0) == Approx(-0.35));
        REQUIRE(tmod<double>::mod(-29.35, -1.0) == Approx(-0.35));
        REQUIRE(tmod<double>::mod(-5.02, 1.0) == Approx(-0.02));
        REQUIRE(tmod<double>::mod(-5.02, -1.0) == Approx(-0.02));
        REQUIRE(tmod<double>::mod(-37.6, 52.8) == Approx(-37.6));
        REQUIRE(tmod<double>::mod(-37.6, -52.8) == Approx(-37.6));
        REQUIRE(tmod<double>::mod(-52.8, 37.6) == Approx(-15.2));
        REQUIRE(tmod<double>::mod(-52.8, -37.6) == Approx(-15.2));
        REQUIRE(tmod<double>::mod(-251.93, 7.81) == Approx(-2.01));
        REQUIRE(tmod<double>::mod(-251.93, -7.81) == Approx(-2.01));

        // Check that the function can be called with various types.
        REQUIRE(tmod<float>::mod(4.5f, 2.1f) == Approx(0.3f));
        REQUIRE(tmod<double>::mod(4.5, 2.1) == Approx(0.3));
        REQUIRE(tmod<long double>::mod(4.5, 2.1) == Approx(0.3));
    }
}

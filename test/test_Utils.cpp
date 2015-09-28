#include "common.h"

using namespace avidmath;
using namespace avidmath::constants;

TEST_CASE("Utils - Angle conversion", "[Utils]")
{
    SECTION("Degrees to other angles")
    {
        // Degrees to Radians
        REQUIRE(degToRad(0.0) == Approx(0.0));
        REQUIRE(degToRad(45.0) == Approx(0.7853981634));
        REQUIRE(degToRad(-45.0) == Approx(-0.7853981634));
        REQUIRE(degToRad(105.97) == Approx(1.8495254083));
        REQUIRE(degToRad(-105.97) == Approx(-1.8495254083));
        REQUIRE(degToRad(180.0) == Approx(3.1415926536));
        REQUIRE(degToRad(-180.0) == Approx(-3.1415926536));
        REQUIRE(degToRad(491.224) == Approx(8.5734761648));
        REQUIRE(degToRad(-491.224) == Approx(-8.5734761648));

        // Degrees to Gradians
        REQUIRE(degToGrad(0.0) == Approx(0.0));
        REQUIRE(degToGrad(45.0) == Approx(50.0));
        REQUIRE(degToGrad(-45.0) == Approx(-50.0));
        REQUIRE(degToGrad(105.97) == Approx(117.74444444));
        REQUIRE(degToGrad(-105.97) == Approx(-117.74444444));
        REQUIRE(degToGrad(180.0) == Approx(200.0));
        REQUIRE(degToGrad(-180.0) == Approx(-200.0));
        REQUIRE(degToGrad(491.224) == Approx(545.80444444));
        REQUIRE(degToGrad(-491.224) == Approx(-545.80444444));

        // Degress to Turns
        REQUIRE(degToTurn(0.0) == Approx(0.0));
        REQUIRE(degToTurn(45.0) == Approx(0.125));
        REQUIRE(degToTurn(-45.0) == Approx(-0.125));
        REQUIRE(degToTurn(105.97) == Approx(0.29436111111));
        REQUIRE(degToTurn(-105.97) == Approx(-0.29436111111));
        REQUIRE(degToTurn(180.0) == Approx(0.5));
        REQUIRE(degToTurn(-180.0) == Approx(-0.5));
        REQUIRE(degToTurn(491.224) == Approx(1.3645111111));
        REQUIRE(degToTurn(-491.224) == Approx(-1.3645111111));
    }

    SECTION("Radians to other angles")
    {
        // Radians to Degrees
        REQUIRE(radToDeg(0.0)           == Approx(0.0));
        REQUIRE(radToDeg(0.7853981634)  == Approx(45.0));
        REQUIRE(radToDeg(-0.7853981634) == Approx(-45.0));
        REQUIRE(radToDeg(1.8495254083)  == Approx(105.97));
        REQUIRE(radToDeg(-1.8495254083) == Approx(-105.97));
        REQUIRE(radToDeg(3.1415926536)  == Approx(180.0));
        REQUIRE(radToDeg(-3.1415926536) == Approx(-180.0));
        REQUIRE(radToDeg(8.5734761648)  == Approx(491.224));
        REQUIRE(radToDeg(-8.5734761648) == Approx(-491.224));

        // Radians to Gradians
        REQUIRE(radToGrad(0.0) == Approx(0.0));
        REQUIRE(radToGrad(0.7853981634) == Approx(50.0));
        REQUIRE(radToGrad(-0.7853981634) == Approx(-50.0));
        REQUIRE(radToGrad(1.8495254083) == Approx(117.74444444));
        REQUIRE(radToGrad(-1.8495254083) == Approx(-117.74444444));
        REQUIRE(radToGrad(3.1415926536) == Approx(200.0));
        REQUIRE(radToGrad(-3.1415926536) == Approx(-200.0));
        REQUIRE(radToGrad(8.5734761648) == Approx(545.80444444));
        REQUIRE(radToGrad(-8.5734761648) == Approx(-545.80444444));

        // Radians to Turns
        REQUIRE(radToTurn(0.0) == Approx(0.0));
        REQUIRE(radToTurn(0.7853981634) == Approx(0.125));
        REQUIRE(radToTurn(-0.7853981634) == Approx(-0.125));
        REQUIRE(radToTurn(1.8495254083) == Approx(0.29436111111));
        REQUIRE(radToTurn(-1.8495254083) == Approx(-0.29436111111));
        REQUIRE(radToTurn(3.1415926536) == Approx(0.5));
        REQUIRE(radToTurn(-3.1415926536) == Approx(-0.5));
        REQUIRE(radToTurn(8.5734761648) == Approx(1.3645111111));
        REQUIRE(radToTurn(-8.5734761648) == Approx(-1.3645111111));
    }

    SECTION("Gradians to other angles")
    {
        // Gradians to Degrees
        REQUIRE(gradToDeg(0.0) == Approx(0.0));
        REQUIRE(gradToDeg(50.0) == Approx(45.0));
        REQUIRE(gradToDeg(-50.0) == Approx(-45.0));
        REQUIRE(gradToDeg(117.74444444) == Approx(105.97));
        REQUIRE(gradToDeg(-117.74444444) == Approx(-105.97));
        REQUIRE(gradToDeg(200.0) == Approx(180.0));
        REQUIRE(gradToDeg(-200.0) == Approx(-180.0));
        REQUIRE(gradToDeg(545.80444444) == Approx(491.224));
        REQUIRE(gradToDeg(-545.80444444) == Approx(-491.224));

        // Gradians to Radians
        REQUIRE(gradToRad(0.0) == Approx(0.0));
        REQUIRE(gradToRad(50.0) == Approx(0.7853981634));
        REQUIRE(gradToRad(-50.0) == Approx(-0.7853981634));
        REQUIRE(gradToRad(117.74444444) == Approx(1.8495254083));
        REQUIRE(gradToRad(-117.74444444) == Approx(-1.8495254083));
        REQUIRE(gradToRad(200.0) == Approx(3.1415926536));
        REQUIRE(gradToRad(-200.0) == Approx(-3.1415926536));
        REQUIRE(gradToRad(545.80444444) == Approx(8.5734761648));
        REQUIRE(gradToRad(-545.80444444) == Approx(-8.5734761648));

        // Gradians to Turns
        REQUIRE(gradToTurn(0.0) == Approx(0.0));
        REQUIRE(gradToTurn(50.0) == Approx(0.125));
        REQUIRE(gradToTurn(-50.0) == Approx(-0.125));
        REQUIRE(gradToTurn(117.74444444) == Approx(0.29436111111));
        REQUIRE(gradToTurn(-117.74444444) == Approx(-0.29436111111));
        REQUIRE(gradToTurn(200.0) == Approx(0.5));
        REQUIRE(gradToTurn(-200.0) == Approx(-0.5));
        REQUIRE(gradToTurn(545.80444444) == Approx(1.3645111111));
        REQUIRE(gradToTurn(-545.80444444) == Approx(-1.3645111111));
    }

    SECTION("Turns to other angles")
    {
        // Turns to Degrees
        REQUIRE(turnToDeg(0.0) == Approx(0.0));
        REQUIRE(turnToDeg(0.125) == Approx(45.0));
        REQUIRE(turnToDeg(-0.125) == Approx(-45.0));
        REQUIRE(turnToDeg(0.29436111111) == Approx(105.97));
        REQUIRE(turnToDeg(-0.29436111111) == Approx(-105.97));
        REQUIRE(turnToDeg(0.5) == Approx(180.0));
        REQUIRE(turnToDeg(-0.5) == Approx(-180.0));
        REQUIRE(turnToDeg(1.3645111111) == Approx(491.224));
        REQUIRE(turnToDeg(-1.3645111111) == Approx(-491.224));

        // Turns to Radians
        REQUIRE(turnToRad(0.0) == Approx(0.0));
        REQUIRE(turnToRad(0.125) == Approx(0.7853981634));
        REQUIRE(turnToRad(-0.125) == Approx(-0.7853981634));
        REQUIRE(turnToRad(0.29436111111) == Approx(1.8495254083));
        REQUIRE(turnToRad(-0.29436111111) == Approx(-1.8495254083));
        REQUIRE(turnToRad(0.5) == Approx(3.1415926536));
        REQUIRE(turnToRad(-0.5) == Approx(-3.1415926536));
        REQUIRE(turnToRad(1.3645111111) == Approx(8.5734761648));
        REQUIRE(turnToRad(-1.3645111111) == Approx(-8.5734761648));

        // Turns to Gradians
        REQUIRE(turnToGrad(0.0) == Approx(0.0));
        REQUIRE(turnToGrad(0.125) == Approx(50.0));
        REQUIRE(turnToGrad(-0.125) == Approx(-50.0));
        REQUIRE(turnToGrad(0.29436111111) == Approx(117.74444444));
        REQUIRE(turnToGrad(-0.29436111111) == Approx(-117.74444444));
        REQUIRE(turnToGrad(0.5) == Approx(200.0));
        REQUIRE(turnToGrad(-0.5) == Approx(-200.0));
        REQUIRE(turnToGrad(1.3645111111) == Approx(545.80444444));
        REQUIRE(turnToGrad(-1.3645111111) == Approx(-545.80444444));
    }
}

TEST_CASE("Utils - Comparisons", "[Utils]")
{
    SECTION("Approximate equality - integers")
    {
        // Exact matches
        REQUIRE(isApproxEqual(0, 0, 0));
        REQUIRE(isApproxEqual(0, 0, 2));
        REQUIRE(isApproxEqual(-303, -303, 5));
        REQUIRE(isApproxEqual(774, 774, 1));

        // Approximate matches
        REQUIRE(isApproxEqual(-6, 0, 10));
        REQUIRE(isApproxEqual(4, 0, 6));
        REQUIRE(isApproxEqual(-138, -136, 3));
        REQUIRE(isApproxEqual(214, 215, 2));

        // Approximate matches crossing zero
        REQUIRE(isApproxEqual(-2, 3, 5));
        REQUIRE(isApproxEqual(2, -5, 7));
        
        // Small mismatches crossing zero
        REQUIRE_FALSE(isApproxEqual(-3, 3, 5));
        REQUIRE_FALSE(isApproxEqual(3, -5, 7));

        // No confusion between positive/negative
        REQUIRE_FALSE(isApproxEqual(-198, 198, 4));
        REQUIRE_FALSE(isApproxEqual(122, -122, 35));

        // Big mismatches
        REQUIRE_FALSE(isApproxEqual(-325, -280, 23));
        REQUIRE_FALSE(isApproxEqual(830, 716, 47));
        REQUIRE_FALSE(isApproxEqual(-2765, 2108, 247));
        REQUIRE_FALSE(isApproxEqual(5862, -9735, 2008));

        // Boundary matches
        REQUIRE(isApproxEqual(9, 10, 1));
        REQUIRE(isApproxEqual(11, 10, 1));
        REQUIRE(isApproxEqual(-9, -10, 1));
        REQUIRE(isApproxEqual(-11, -10, 1));
        REQUIRE(isApproxEqual(42, 63, 21));
        REQUIRE(isApproxEqual(84, 63, 21));
        REQUIRE(isApproxEqual(-42, -63, 21));
        REQUIRE(isApproxEqual(-84, -63, 21));

        // Boundary mismatches
        REQUIRE_FALSE(isApproxEqual(8, 10, 1));
        REQUIRE_FALSE(isApproxEqual(12, 10, 1));
        REQUIRE_FALSE(isApproxEqual(-8, -10, 1));
        REQUIRE_FALSE(isApproxEqual(-12, -10, 1));
        REQUIRE_FALSE(isApproxEqual(41, 63, 21));
        REQUIRE_FALSE(isApproxEqual(85, 63, 21));
        REQUIRE_FALSE(isApproxEqual(-41, -63, 21));
        REQUIRE_FALSE(isApproxEqual(-85, -63, 21));
    }

    SECTION("Approximate equality - floating point")
    {
        // Exact matches
        REQUIRE(isApproxEqual(0.0, 0.0, 0.0));
        REQUIRE(isApproxEqual(0.0, 0.0, 1.23));
        REQUIRE(isApproxEqual(-194.56, -194.56, 3.6));
        REQUIRE(isApproxEqual(871.02, 871.02, 4.901));

        // Approximate matches
        REQUIRE(isApproxEqual(-13.6, -14.9, 2.76));
        REQUIRE(isApproxEqual(24.54, 27.0, 3.0));
        REQUIRE(isApproxEqual(-6594.34, -6402.939, 353.4));
        REQUIRE(isApproxEqual(1390.114, 1253.332, 250.0));

        // Approximate matches crossing zero
        REQUIRE(isApproxEqual(-5.49, 2.48, 11.88));
        REQUIRE(isApproxEqual(6.97, -3.74, 15.6));

        // Small mismatches crossing zero
        REQUIRE_FALSE(isApproxEqual(-8.112, 2.48, 6.91));
        REQUIRE_FALSE(isApproxEqual(5.901, -4.446, 7.27));

        // No confusion between positive/negative
        REQUIRE_FALSE(isApproxEqual(-314.23, 314.23, 3.19));
        REQUIRE_FALSE(isApproxEqual(461.39, -461.39, 41.36));

        // Big mismatches
        REQUIRE_FALSE(isApproxEqual(-386.13, -963.41, 27.041));
        REQUIRE_FALSE(isApproxEqual(136.36, 549.36, 27.041));
        REQUIRE_FALSE(isApproxEqual(37896.27, -2902.847, 1326.94));
        REQUIRE_FALSE(isApproxEqual(-29653.165, 9572.187, 3618.2));

        // Boundary matches
        // (be careful of floating point accuracy with these tests)
        REQUIRE(isApproxEqual(74.31, 74.32, 0.0101));
        REQUIRE(isApproxEqual(74.33, 74.32, 0.0101));
        REQUIRE(isApproxEqual(-74.31, -74.32, 0.0101));
        REQUIRE(isApproxEqual(-74.33, -74.32, 0.0101));
        REQUIRE(isApproxEqual(64.92, 58.67, 6.2501));
        REQUIRE(isApproxEqual(52.42, 58.67, 6.2501));
        REQUIRE(isApproxEqual(-64.92, -58.67, 6.2501));
        REQUIRE(isApproxEqual(-52.42, -58.67, 6.2501));

        // Boundary mismatches
        // (be careful of floating point accuracy with these tests)
        REQUIRE_FALSE(isApproxEqual(74.3098, 74.32, 0.0101));
        REQUIRE_FALSE(isApproxEqual(74.3302, 74.32, 0.0101));
        REQUIRE_FALSE(isApproxEqual(-74.3098, -74.32, 0.0101));
        REQUIRE_FALSE(isApproxEqual(-74.3302, -74.32, 0.0101));
        REQUIRE_FALSE(isApproxEqual(64.9202, 58.67, 6.2501));
        REQUIRE_FALSE(isApproxEqual(52.4199, 58.67, 6.2501));
        REQUIRE_FALSE(isApproxEqual(-64.9202, -58.67, 6.2501));
        REQUIRE_FALSE(isApproxEqual(-52.4198, -58.67, 6.2501));
    }

    SECTION("Approximate equality to zero - integers")
    {
        // Exact matches
        REQUIRE(isApproxZero(0, 0));
        REQUIRE(isApproxZero(0, 1));

        // Approximate matches
        REQUIRE(isApproxZero(-2, 3));
        REQUIRE(isApproxZero(2, 3));
        REQUIRE(isApproxZero(-5, 10));
        REQUIRE(isApproxZero(5, 10));

        // Boundary matches
        REQUIRE(isApproxZero(-1, 1));
        REQUIRE(isApproxZero(1, 1));
        REQUIRE(isApproxZero(-28, 28));
        REQUIRE(isApproxZero(28, 28));

        // Boundary mismatches
        REQUIRE_FALSE(isApproxZero(-2, 1));
        REQUIRE_FALSE(isApproxZero(2, 1));
        REQUIRE_FALSE(isApproxZero(-41, 40));
        REQUIRE_FALSE(isApproxZero(41, 40));

        // Big mismatches
        REQUIRE_FALSE(isApproxZero(-47, 23));
        REQUIRE_FALSE(isApproxZero(93, 38));
    }

    SECTION("Approximate equality to zero - floating point")
    {
        // Exact matches
        REQUIRE(isApproxZero(0.0, 0.0));
        REQUIRE(isApproxZero(0.0, 1.0));

        // Approximate matches
        REQUIRE(isApproxZero(-2.2, 3.1));
        REQUIRE(isApproxZero(2.2, 3.1));
        REQUIRE(isApproxZero(-5.6, 6.3));
        REQUIRE(isApproxZero(5.6, 6.2));

        // Boundary matches
        REQUIRE(isApproxZero(-1.4, 1.4));
        REQUIRE(isApproxZero(1.4, 1.4));
        REQUIRE(isApproxZero(-37.16, 37.16));
        REQUIRE(isApproxZero(37.16, 37.16));

        // Boundary mismatches
        REQUIRE_FALSE(isApproxZero(-2.6, 2.58));
        REQUIRE_FALSE(isApproxZero(2.6, 2.58));
        REQUIRE_FALSE(isApproxZero(-52.85, 52.83));
        REQUIRE_FALSE(isApproxZero(52.85, 52.83));

        // Big mismatches
        REQUIRE_FALSE(isApproxZero(-63.281, 14.107));
        REQUIRE_FALSE(isApproxZero(947.682, 37.869));
    }

    // TODO: isInRange
}

// Check that all the constexpr functions can be evaluated at compile-time.
// A failure will typically result in an error message in the function itself.
static_assert(degToRad(0.0) || true, "Compile-time evaluation check");
static_assert(degToGrad(0.0) || true, "Compile-time evaluation check");
static_assert(degToTurn(0.0) || true, "Compile-time evaluation check");

static_assert(radToDeg(0.0) || true, "Compile-time evaluation check");
static_assert(radToGrad(0.0) || true, "Compile-time evaluation check");
static_assert(radToTurn(0.0) || true, "Compile-time evaluation check");

static_assert(gradToDeg(0.0) || true, "Compile-time evaluation check");
static_assert(gradToRad(0.0) || true, "Compile-time evaluation check");
static_assert(gradToTurn(0.0) || true, "Compile-time evaluation check");

static_assert(turnToDeg(0.0) || true, "Compile-time evaluation check");
static_assert(turnToRad(0.0) || true, "Compile-time evaluation check");
static_assert(turnToGrad(0.0) || true, "Compile-time evaluation check");

static_assert(isApproxEqual(0, 0, 1) || true, "Compile-time evaluation check");
static_assert(isApproxZero(0, 1) || true, "Compile-time evaluation check");
static_assert(isInRange(1, 2, 3) || true, "Compile-time evaluation check");

static_assert(diff(1, 2) == 0 || true, "Compile-time evaluation check");
static_assert(clamp(1, 2, 3) == 0 || true, "Compile-time evaluation check");
static_assert(lerp(1.0, 2.0, 3.0) || true, "Compile-time evaluation check");
static_assert(lerpClamp(1.0, 2.0, 3.0) || true, "Compile-time evaluation check");

// TODO: diff
// TODO: clamp
// TODO: wrap
// TODO: lerp
// TODO: lerpClamp


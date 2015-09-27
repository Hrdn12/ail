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
        REQUIRE_FALSE(isApproxEqual(-3, 3, 5));
        REQUIRE(isApproxEqual(2, -5, 7));
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
    }

    // TODO: isApproxZero
    // TODO: isInRange
}

// TODO: diff
// TODO: clamp
// TODO: wrap
// TODO: lerp
// TODO: lerpClamp


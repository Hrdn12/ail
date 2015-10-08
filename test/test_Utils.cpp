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
    SECTION("isApproxEqual - integers")
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

    SECTION("isApproxEqual - floating point")
    {
        // Exact matches
        REQUIRE(isApproxEqual(0.0, 0.0, 0.0));
        REQUIRE(isApproxEqual(0.0, 0.0, 1.23));
        REQUIRE(isApproxEqual(-194.56, -194.56, 3.6));
        REQUIRE(isApproxEqual(871.02, 871.02, 4.901));

        // Approximate matches
        REQUIRE(isApproxEqual(1.5, 1.4, 0.2));
        REQUIRE(isApproxEqual(-3.8, -4.1, 0.4));
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

    SECTION("isApproxZero - integers")
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

    SECTION("isApproxZero - floating point")
    {
        // Exact matches
        REQUIRE(isApproxZero(0.0, 0.0));
        REQUIRE(isApproxZero(0.0, 1.0));

        // Approximate matches
        REQUIRE(isApproxZero(0.4, 0.9));
        REQUIRE(isApproxZero(-0.3, 0.7));
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

    SECTION("Range checking - integer")
    {
        // Zero range.
        REQUIRE(isInRange(0, 0, 0));
        REQUIRE(isInRange(382, 382, 382));
        REQUIRE(isInRange(-48, -48, -48));

        // Comfortably in range.
        REQUIRE(isInRange(23, 0, 40));
        REQUIRE(isInRange(23, 40, 0));
        REQUIRE(isInRange(502, 389, 1930));
        REQUIRE(isInRange(502, 1930, 389));
        REQUIRE(isInRange(-38, 0, -50));
        REQUIRE(isInRange(-38, -50, 0));
        REQUIRE(isInRange(-283, -102, -819));
        REQUIRE(isInRange(-283, -819, -102));

        // Comfortably in range - boundaries straddling zero.
        REQUIRE(isInRange(0, -299, 391));
        REQUIRE(isInRange(0, 391, -299));
        REQUIRE(isInRange(13, -58, 962));
        REQUIRE(isInRange(13, 962, -58));
        REQUIRE(isInRange(-28, -98, 442));
        REQUIRE(isInRange(-28, 442, -98));

        // In range - exactly on boundary.
        REQUIRE(isInRange(40, 40, 91));
        REQUIRE(isInRange(40, 91, 40));
        REQUIRE(isInRange(91, 40, 91));
        REQUIRE(isInRange(91, 91, 40));
        REQUIRE(isInRange(-211, -38, -211));
        REQUIRE(isInRange(-211, -211, -38));
        REQUIRE(isInRange(-38, -38, -211));
        REQUIRE(isInRange(-38, -211, -38));

        // Out of range - just outside boundary.
        REQUIRE_FALSE(isInRange(42, 43, 56));
        REQUIRE_FALSE(isInRange(42, 56, 43));
        REQUIRE_FALSE(isInRange(57, 43, 56));
        REQUIRE_FALSE(isInRange(57, 56, 43));
        REQUIRE_FALSE(isInRange(-66, -67, -78));
        REQUIRE_FALSE(isInRange(-66, -78, -67));
        REQUIRE_FALSE(isInRange(-79, -67, -78));
        REQUIRE_FALSE(isInRange(-79, -78, -67));

        // Comfortably out of range.
        REQUIRE_FALSE(isInRange(45, 50, 60));
        REQUIRE_FALSE(isInRange(45, 60, 50));
        REQUIRE_FALSE(isInRange(36, 2, 11));
        REQUIRE_FALSE(isInRange(36, 11, 2));
        REQUIRE_FALSE(isInRange(-9, -28, -14));
        REQUIRE_FALSE(isInRange(-9, -14, -28));
        REQUIRE_FALSE(isInRange(-102, -47, -15));
        REQUIRE_FALSE(isInRange(-102, -15, -47));
    }

    SECTION("Range checking - floating point")
    {
        // Zero range.
        REQUIRE(isInRange(0.0, 0.0, 0.0));
        REQUIRE(isInRange(14.6, 14.6, 14.6));
        REQUIRE(isInRange(-38.1, -38.1, -38.1));

        // Comfortably in range.
        REQUIRE(isInRange(52.4, 0.0, 82.06));
        REQUIRE(isInRange(52.4, 82.06, 0.0));
        REQUIRE(isInRange(12.6, 12.4, 12.9));
        REQUIRE(isInRange(12.6, 12.9, 12.4));
        REQUIRE(isInRange(294.51, 119.93, 479.22));
        REQUIRE(isInRange(294.51, 479.22, 119.93));
        REQUIRE(isInRange(-99.4, 0.0, -140.5));
        REQUIRE(isInRange(-99.4, -140.5, 0.0));
        REQUIRE(isInRange(-47.0, -46.8, -47.3));
        REQUIRE(isInRange(-47.0, -47.3, -46.8));
        REQUIRE(isInRange(-497.94, -226.3, -855.1));
        REQUIRE(isInRange(-497.94, -855.1, -226.3));

        // Comfortably in range - boundaries straddling zero.
        REQUIRE(isInRange(0.0, -53.5, 193.6));
        REQUIRE(isInRange(0.0, 193.6, -53.5));
        REQUIRE(isInRange(48.92, -951.8, 364.2));
        REQUIRE(isInRange(48.92, 364.2, -951.8));
        REQUIRE(isInRange(-66.8, -354.9, 1001.2));
        REQUIRE(isInRange(-66.8, 1001.2, -354.9));

        // In range - exactly on boundary.
        REQUIRE(isInRange(28.5, 28.5, 37.7));
        REQUIRE(isInRange(28.5, 37.7, 28.5));
        REQUIRE(isInRange(37.7, 28.5, 37.7));
        REQUIRE(isInRange(37.7, 37.7, 28.5));
        REQUIRE(isInRange(-48.3, -9.9, -62.7));
        REQUIRE(isInRange(-48.3, -62.7, -9.9));
        REQUIRE(isInRange(-62.7, -9.9, -62.7));
        REQUIRE(isInRange(-62.7, -62.7, -9.9));

        // Out of range - just outside boundary.
        REQUIRE_FALSE(isInRange(58.2, 58.3, 58.9));
        REQUIRE_FALSE(isInRange(58.2, 58.9, 58.3));
        REQUIRE_FALSE(isInRange(59.0, 58.3, 58.9));
        REQUIRE_FALSE(isInRange(59.0, 58.9, 58.3));
        REQUIRE_FALSE(isInRange(-13.5, -13.6, -20.8));
        REQUIRE_FALSE(isInRange(-13.5, -20.8, -13.6));
        REQUIRE_FALSE(isInRange(-20.9, -13.6, -20.8));
        REQUIRE_FALSE(isInRange(-20.9, -20.8, -13.6));

        // Comfortably out of range.
        REQUIRE_FALSE(isInRange(38.2, 14.63, 24.222));
        REQUIRE_FALSE(isInRange(38.2, 24.222, 14.63));
        REQUIRE_FALSE(isInRange(59.9, 1035.48, 2094.99));
        REQUIRE_FALSE(isInRange(59.9, 2094.99, 1035.48));
        REQUIRE_FALSE(isInRange(-16.2, -37.1, -19.65));
        REQUIRE_FALSE(isInRange(-16.2, -19.65, -37.1));
        REQUIRE_FALSE(isInRange(-49.02, -3.01, -12.8));
        REQUIRE_FALSE(isInRange(-49.02, -12.8, -3.01));
    }
}

TEST_CASE("Utils - General numerical", "[Utils]")
{
    SECTION("diff")
    {
        // Signed integer
        REQUIRE(diff(0, 0) == 0);
        REQUIRE(diff(0, 139) == 139);
        REQUIRE(diff(0, -40) == 40);
        REQUIRE(diff(57, 0) == 57);
        REQUIRE(diff(-98, 0) == 98);
        REQUIRE(diff(141, 296) == 155);
        REQUIRE(diff(301, 112) == 189);
        REQUIRE(diff(-53, -95) == 42);
        REQUIRE(diff(-77, -12) == 65);
        REQUIRE(diff(-23, 492) == 515);
        REQUIRE(diff(101, -344) == 445);

        // Unsigned integer
        REQUIRE(diff<unsigned int>(108, 215) == 107);
        REQUIRE(diff<unsigned int>(76, 2) == 74);

        // Floating point
        REQUIRE(diff(0.2, 0.54) == Approx(0.34));
        REQUIRE(diff(24.412, 21.194) == Approx(3.218));
        REQUIRE(diff(-1.91, -2.501) == Approx(0.591));
        REQUIRE(diff(-44.5, -13.74) == Approx(30.76));
    }

    SECTION("clamp - integer")
    {
        // Zero range.
        REQUIRE(clamp(0, 0, 0) == 0);
        REQUIRE(clamp(95, 56, 56) == 56);
        REQUIRE(clamp(56, 56, 56) == 56);
        REQUIRE(clamp(41, 56, 56) == 56);
        REQUIRE(clamp(-14, -32, -32) == -32);
        REQUIRE(clamp(-32, -32, -32) == -32);
        REQUIRE(clamp(-63, -32, -32) == -32);

        // In range (no clamp).
        REQUIRE(clamp(25, 2, 51) == 25);
        REQUIRE(clamp(25, 51, 2) == 25);
        REQUIRE(clamp(-13, -4, -99) == -13);
        REQUIRE(clamp(-13, -99, -4) == -13);

        // In range (no clamp) - mixing positive/negative.
        REQUIRE(clamp(12, -34, 30) == 12);
        REQUIRE(clamp(12, 30, -34) == 12);
        REQUIRE(clamp(-5, -20, 19) == -5);
        REQUIRE(clamp(-5, 19, -20) == -5);

        // Clamp to lower boundary.
        REQUIRE(clamp(10, 23, 56) == 23);
        REQUIRE(clamp(10, 56, 23) == 23);
        REQUIRE(clamp(22, 23, 56) == 23);
        REQUIRE(clamp(22, 56, 23) == 23);
        REQUIRE(clamp(-103, -44, -95) == -95);
        REQUIRE(clamp(-103, -95, -44) == -95);
        REQUIRE(clamp(-96, -44, -95) == -95);
        REQUIRE(clamp(-96, -95, -44) == -95);

        // Clamp to upper boundary.
        REQUIRE(clamp(92, 5, 21) == 21);
        REQUIRE(clamp(92, 21, 5) == 21);
        REQUIRE(clamp(22, 5, 21) == 21);
        REQUIRE(clamp(22, 21, 5) == 21);
        REQUIRE(clamp(-1, -16, -44) == -16);
        REQUIRE(clamp(-1, -44, -16) == -16);
        REQUIRE(clamp(-15, -16, -44) == -16);
        REQUIRE(clamp(-15, -44, -16) == -16);
    }

    SECTION("clamp - floating point")
    {
        // Zero range.
        REQUIRE(clamp(0.0, 0.0, 0.0) == 0.0);
        REQUIRE(clamp(84.2, 62.99, 62.99) == 62.99);
        REQUIRE(clamp(62.99, 62.99, 62.99) == 62.99);
        REQUIRE(clamp(31.05, 62.99, 62.99) == 62.99);
        REQUIRE(clamp(-2.78, -17.84, -17.84) == -17.84);
        REQUIRE(clamp(-17.84, -17.84, -17.84) == -17.84);
        REQUIRE(clamp(-29.941, -17.84, -17.84) == -17.84);

        // In range (no clamp).
        REQUIRE(clamp(1.43, 1.38, 1.55) == 1.43);
        REQUIRE(clamp(1.43, 1.55, 1.38) == 1.43);
        REQUIRE(clamp(-3.926, -3.85, -4.22) == -3.926);
        REQUIRE(clamp(-3.926, -4.22, -3.85) == -3.926);

        // In range (no clamp) - mixing positive/negative.
        REQUIRE(clamp(54.049, -11.06, 61.9) == 54.049);
        REQUIRE(clamp(54.049, 61.9, -11.06) == 54.049);
        REQUIRE(clamp(-0.727, -1.2, 0.88) == -0.727);
        REQUIRE(clamp(-0.727, 0.88, -1.2) == -0.727);

        // Clamp to lower boundary.
        REQUIRE(clamp(1.1, 2.9, 4.6) == 2.9);
        REQUIRE(clamp(1.1, 4.6, 2.9) == 2.9);
        REQUIRE(clamp(2.88, 2.9, 4.6) == 2.9);
        REQUIRE(clamp(2.88, 4.6, 2.9) == 2.9);
        REQUIRE(clamp(-80.02, -74.45, -32.46) == -74.45);
        REQUIRE(clamp(-80.02, -32.46, -74.45) == -74.45);
        REQUIRE(clamp(-74.47, -74.45, -32.46) == -74.45);
        REQUIRE(clamp(-74.47, -32.46, -74.45) == -74.45);

        // Clamp to upper boundary.
        REQUIRE(clamp(16.8, 9.51, 10.002) == 10.002);
        REQUIRE(clamp(16.8, 10.002, 9.51) == 10.002);
        REQUIRE(clamp(10.01, 9.51, 10.002) == 10.002);
        REQUIRE(clamp(10.01, 10.002, 9.51) == 10.002);
        REQUIRE(clamp(-2.0, -4.6, -8.132) == -4.6);
        REQUIRE(clamp(-2.0, -8.132, -4.6) == -4.6);
        REQUIRE(clamp(-4.58, -4.6, -8.132) == -4.6);
        REQUIRE(clamp(-4.58, -8.132, -4.6) == -4.6);
    }

    SECTION("lerp")
    {
        // Boundaries.
        REQUIRE(lerp(0.0, 19.1, 28.22) == Approx(19.1));
        REQUIRE(lerp(1.0, 19.1, 28.22) == Approx(28.22));
        REQUIRE(lerp(0.0, 28.22, 19.1) == Approx(28.22));
        REQUIRE(lerp(1.0, 28.22, 19.1) == Approx(19.1));
        REQUIRE(lerp(0.0, -11.88, -2.41) == Approx(-11.88));
        REQUIRE(lerp(1.0, -11.88, -2.41) == Approx(-2.41));
        REQUIRE(lerp(0.0, -2.41, -11.88) == Approx(-2.41));
        REQUIRE(lerp(1.0, -2.41, -11.88) == Approx(-11.88));
        REQUIRE(lerp(0.0, -90.4, 33.21) == Approx(-90.4));
        REQUIRE(lerp(1.0, -90.4, 33.21) == Approx(33.21));
        REQUIRE(lerp(0.0, 33.21, -90.4) == Approx(33.21));
        REQUIRE(lerp(1.0, 33.21, -90.4) == Approx(-90.4));

        // Interpolation (in range).
        REQUIRE(lerp(0.2, 35.7, 42.9) == Approx(37.14));
        REQUIRE(lerp(0.2, 42.9, 35.7) == Approx(41.46));
        REQUIRE(lerp(0.65, 24.99, 106.012) == Approx(77.6543));
        REQUIRE(lerp(0.65, 106.012, 24.99) == Approx(53.3477));
        REQUIRE(lerp(0.18, -51.15, -10.38) == Approx(-43.8114));
        REQUIRE(lerp(0.18, -10.38, -51.15) == Approx(-17.7186));
        REQUIRE(lerp(0.76, -109.9, -84.443) == Approx(-90.55268));
        REQUIRE(lerp(0.76, -84.443, -109.9) == Approx(-103.79032));
        REQUIRE(lerp(0.47, -61.3, 152.61) == Approx(39.2377));
        REQUIRE(lerp(0.47, 152.61, -61.3) == Approx(52.0723));

        // Extrapolation (out of range).
        REQUIRE(lerp(1.51, 15.6, 48.91) == Approx(65.8981));
        REQUIRE(lerp(1.51, 48.91, 15.6) == Approx(-1.3881));
        REQUIRE(lerp(-2.93, 142.07, 203.4) == Approx(-37.6269));
        REQUIRE(lerp(-2.93, 203.4, 142.07) == Approx(383.0969));
        REQUIRE(lerp(3.8, -85.22, -11.39) == Approx(195.334));
        REQUIRE(lerp(3.8, -11.39, -85.22) == Approx(-291.944));
        REQUIRE(lerp(-1.6, -173.2, -92.5) == Approx(-302.32));
        REQUIRE(lerp(-1.6, -92.5, -173.2) == Approx(36.62));
        REQUIRE(lerp(2.33, -38.5, 10.77) == Approx(76.2991));
        REQUIRE(lerp(2.33, 10.77, -38.5) == Approx(-104.0291));
        REQUIRE(lerp(-4.83, -2.6, 14.9) == Approx(-87.125));
        REQUIRE(lerp(-4.83, 14.9, -2.6) == Approx(99.425));

        // Zero range.
        REQUIRE(lerp(0.0, 0.0, 0.0) == Approx(0.0));
        REQUIRE(lerp(47.2, 0.0, 0.0) == Approx(0.0));
        REQUIRE(lerp(5.4, 57.24, 57.24) == Approx(57.24));
        REQUIRE(lerp(-24.35, 3581.38, 3581.38) == Approx(3581.38));
        REQUIRE(lerp(2.9, -994.1, -994.1) == Approx(-994.1));
    }

    SECTION("lerpClamp")
    {
        // These tests are copied from lerp.
        // The results are simply modified to account for the clamp where appropriate.

        // Boundaries.
        REQUIRE(lerpClamp(0.0, 19.1, 28.22) == Approx(19.1));
        REQUIRE(lerpClamp(1.0, 19.1, 28.22) == Approx(28.22));
        REQUIRE(lerpClamp(0.0, 28.22, 19.1) == Approx(28.22));
        REQUIRE(lerpClamp(1.0, 28.22, 19.1) == Approx(19.1));
        REQUIRE(lerpClamp(0.0, -11.88, -2.41) == Approx(-11.88));
        REQUIRE(lerpClamp(1.0, -11.88, -2.41) == Approx(-2.41));
        REQUIRE(lerpClamp(0.0, -2.41, -11.88) == Approx(-2.41));
        REQUIRE(lerpClamp(1.0, -2.41, -11.88) == Approx(-11.88));
        REQUIRE(lerpClamp(0.0, -90.4, 33.21) == Approx(-90.4));
        REQUIRE(lerpClamp(1.0, -90.4, 33.21) == Approx(33.21));
        REQUIRE(lerpClamp(0.0, 33.21, -90.4) == Approx(33.21));
        REQUIRE(lerpClamp(1.0, 33.21, -90.4) == Approx(-90.4));

        // Interpolation (in range).
        REQUIRE(lerpClamp(0.2, 35.7, 42.9) == Approx(37.14));
        REQUIRE(lerpClamp(0.2, 42.9, 35.7) == Approx(41.46));
        REQUIRE(lerpClamp(0.65, 24.99, 106.012) == Approx(77.6543));
        REQUIRE(lerpClamp(0.65, 106.012, 24.99) == Approx(53.3477));
        REQUIRE(lerpClamp(0.18, -51.15, -10.38) == Approx(-43.8114));
        REQUIRE(lerpClamp(0.18, -10.38, -51.15) == Approx(-17.7186));
        REQUIRE(lerpClamp(0.76, -109.9, -84.443) == Approx(-90.55268));
        REQUIRE(lerpClamp(0.76, -84.443, -109.9) == Approx(-103.79032));
        REQUIRE(lerpClamp(0.47, -61.3, 152.61) == Approx(39.2377));
        REQUIRE(lerpClamp(0.47, 152.61, -61.3) == Approx(52.0723));

        // Extrapolation (out of range).
        REQUIRE(lerpClamp(1.51, 15.6, 48.91) == Approx(48.91));
        REQUIRE(lerpClamp(1.51, 48.91, 15.6) == Approx(15.6));
        REQUIRE(lerpClamp(-2.93, 142.07, 203.4) == Approx(142.07));
        REQUIRE(lerpClamp(-2.93, 203.4, 142.07) == Approx(203.4));
        REQUIRE(lerpClamp(3.8, -85.22, -11.39) == Approx(-11.39));
        REQUIRE(lerpClamp(3.8, -11.39, -85.22) == Approx(-85.22));
        REQUIRE(lerpClamp(-1.6, -173.2, -92.5) == Approx(-173.2));
        REQUIRE(lerpClamp(-1.6, -92.5, -173.2) == Approx(-92.5));
        REQUIRE(lerpClamp(2.33, -38.5, 10.77) == Approx(10.77));
        REQUIRE(lerpClamp(2.33, 10.77, -38.5) == Approx(-38.5));
        REQUIRE(lerpClamp(-4.83, -2.6, 14.9) == Approx(-2.6));
        REQUIRE(lerpClamp(-4.83, 14.9, -2.6) == Approx(14.9));

        // Zero range.
        REQUIRE(lerpClamp(0.0, 0.0, 0.0) == Approx(0.0));
        REQUIRE(lerpClamp(47.2, 0.0, 0.0) == Approx(0.0));
        REQUIRE(lerpClamp(5.4, 57.24, 57.24) == Approx(57.24));
        REQUIRE(lerpClamp(-24.35, 3581.38, 3581.38) == Approx(3581.38));
        REQUIRE(lerpClamp(2.9, -994.1, -994.1) == Approx(-994.1));
    }

    SECTION("wrap - integer")
    {
        // Parameters: value, rangeMin, rangeMax.
        // Requirements:
        //  - Wrap will always be inclusive of rangeMin and exclusive of rangeMax.
        //  - rangeMin and rangeMax will be automatically swapped if rangeMin > rangeMax (i.e. order of range values doesn't affect result).
        //  - Works for any built-in integer and floating point type.
        //  - Works for any combination of negative and positive values.

        // Zero range.
        REQUIRE(wrap(0, 0, 0) == 0);
        REQUIRE(wrap(18, 0, 0) == 0);
        REQUIRE(wrap(-51, 0, 0) == 0);
        REQUIRE(wrap(0, 14, 14) == 14);
        REQUIRE(wrap(22, 14, 14) == 14);
        REQUIRE(wrap(-46, 14, 14) == 14);
        REQUIRE(wrap(0, -99, -99) == -99);
        REQUIRE(wrap(22, -99, -99) == -99);
        REQUIRE(wrap(-46, -99, -99) == -99);

        // In range.
        REQUIRE(wrap(2, 0, 10) == 2);
        REQUIRE(wrap(2, 10, 0) == 2);
        REQUIRE(wrap(-7, -25, 0) == -7);
        REQUIRE(wrap(-7, 0, -25) == -7);
        REQUIRE(wrap(148, 98, 259) == 148);
        REQUIRE(wrap(148, 259, 98) == 148);
        REQUIRE(wrap(-88, -101, -50) == -88);
        REQUIRE(wrap(-88, -50, -101) == -88);
        REQUIRE(wrap(42, -85, 52) == 42);
        REQUIRE(wrap(42, 52, -85) == 42);
        REQUIRE(wrap(-31, -85, 52) == -31);
        REQUIRE(wrap(-31, 52, -85) == -31);

        // Boundary.
        REQUIRE(wrap(0, 0, 11) == 0);
        REQUIRE(wrap(0, 11, 0) == 0);
        REQUIRE(wrap(10, 0, 11) == 10);
        REQUIRE(wrap(10, 11, 0) == 10);
        REQUIRE(wrap(-18, -18, 0) == -18);
        REQUIRE(wrap(-18, 0, -18) == -18);
        REQUIRE(wrap(-1, -18, 0) == -1);
        REQUIRE(wrap(-1, 0, -18) == -1);
        REQUIRE(wrap(43, 43, 77) == 43);
        REQUIRE(wrap(43, 77, 43) == 43);
        REQUIRE(wrap(76, 43, 77) == 76);
        REQUIRE(wrap(76, 77, 43) == 76);
        REQUIRE(wrap(-328, -328, -162) == -328);
        REQUIRE(wrap(-328, -162, -328) == -328);
        REQUIRE(wrap(-163, -328, -162) == -163);
        REQUIRE(wrap(-163, -162, -328) == -163);
        REQUIRE(wrap(-101, -101, 94) == -101);
        REQUIRE(wrap(-101, 94, -101) == -101);
        REQUIRE(wrap(93, -101, 94) == 93);
        REQUIRE(wrap(93, 94, -101) == 93);
        
        // Off top of range.
        REQUIRE(wrap(7, 0, 7) == 0);
        REQUIRE(wrap(7, 7, 0) == 0);
        REQUIRE(wrap(53, 0, 7) == 4);
        REQUIRE(wrap(53, 7, 0) == 4);
        REQUIRE(wrap(0, -13, 0) == -13);
        REQUIRE(wrap(0, 0, -13) == -13);
        REQUIRE(wrap(21, -13, 0) == -5);
        REQUIRE(wrap(21, 0, -13) == -5);
        REQUIRE(wrap(41, 29, 41) == 29);
        REQUIRE(wrap(41, 41, 29) == 29);
        REQUIRE(wrap(68, 29, 41) == 32);
        REQUIRE(wrap(68, 41, 29) == 32);
        REQUIRE(wrap(-87, -94, -87) == -94);
        REQUIRE(wrap(-87, -87, -94) == -94);
        REQUIRE(wrap(-44, -94, -87) == -93);
        REQUIRE(wrap(-44, -87, -94) == -93);
        REQUIRE(wrap(50, -75, 50) == -75);
        REQUIRE(wrap(50, 50, -75) == -75);
        REQUIRE(wrap(99, -75, 50) == -26);
        REQUIRE(wrap(99, 50, -75) == -26);

        // Off bottom of range.
        REQUIRE(wrap(-1, 0, 7) == 6);
        REQUIRE(wrap(-1, 7, 0) == 6);
        REQUIRE(wrap(-12, 0, 7) == 2);
        REQUIRE(wrap(-12, 7, 0) == 2);
        REQUIRE(wrap(-14, -13, 0) == -1);
        REQUIRE(wrap(-14, 0, -13) == -1);
        REQUIRE(wrap(-48, -13, 0) == -9);
        REQUIRE(wrap(-48, 0, -13) == -9);
        REQUIRE(wrap(28, 29, 41) == 40);
        REQUIRE(wrap(28, 41, 29) == 40);
        REQUIRE(wrap(2, 29, 41) == 38);
        REQUIRE(wrap(2, 41, 29) == 38);
        REQUIRE(wrap(-95, -94, -87) == -88);
        REQUIRE(wrap(-95, -87, -94) == -88);
        REQUIRE(wrap(-115, -94, -87) == -94);
        REQUIRE(wrap(-115, -87, -94) == -94);
        REQUIRE(wrap(-76, -75, 50) == 49);
        REQUIRE(wrap(-76, 50, -75) == 49);
        REQUIRE(wrap(-231, -75, 50) == 19);
        REQUIRE(wrap(-231, 50, -75) == 19);
    }

    SECTION("wrap - floating point")
    {
        // Zero range.
        REQUIRE(wrap(0.0, 0.0, 0.0) == 0.0);
        REQUIRE(wrap(24.6, 0.0, 0.0) == 0.0);
        REQUIRE(wrap(-19.41, 0.0, 0.0) == 0.0);
        REQUIRE(wrap(0.0, 27.72, 27.72) == 27.72);
        REQUIRE(wrap(56.94, 27.72, 27.72) == 27.72);
        REQUIRE(wrap(-89.44, 27.72, 27.72) == 27.72);
        REQUIRE(wrap(0.0, -33.802, -33.802) == -33.802);
        REQUIRE(wrap(16.88, -33.802, -33.802) == -33.802);
        REQUIRE(wrap(-101.4, -33.802, -33.802) == -33.802);

        // In range.
        REQUIRE(wrap(0.64, 0.0, 0.9) == 0.64);
        REQUIRE(wrap(0.64, 0.9, 0.0) == 0.64);
        REQUIRE(wrap(-4.1, -12.44, 0.0) == -4.1);
        REQUIRE(wrap(-4.1, 0.0, -12.44) == -4.1);
        REQUIRE(wrap(64.35, 57.81, 91.1) == 64.35);
        REQUIRE(wrap(64.35, 91.1, 57.81) == 64.35);
        REQUIRE(wrap(-99.33, -162.3, -87.4) == -99.33);
        REQUIRE(wrap(-99.33, -87.4, -162.3) == -99.33);
        REQUIRE(wrap(19.6, -3.4, 27.8) == 19.6);
        REQUIRE(wrap(19.6, 27.8, -3.4) == 19.6);
        REQUIRE(wrap(-11.46, -29.92, 48.7) == -11.46);
        REQUIRE(wrap(-11.46, 48.7, -29.92) == -11.46);

        // Boundary.
        REQUIRE(wrap(0.0, 0.0, 2.4) == 0);
        REQUIRE(wrap(0.0, 2.4, 0.0) == 0);
        REQUIRE(wrap(2.35, 0.0, 2.4) == 2.35);
        REQUIRE(wrap(2.35, 2.4, 0.0) == 2.35);
        REQUIRE(wrap(-69.3, -69.3, 0.0) == -69.3);
        REQUIRE(wrap(-69.3, 0.0, -69.3) == -69.3);
        REQUIRE(wrap(-0.1, -3.4, 0.0) == -0.1);
        REQUIRE(wrap(-0.1, 0.0, -3.4) == -0.1);
        REQUIRE(wrap(19.65, 19.65, 106.2) == 19.65);
        REQUIRE(wrap(19.65, 106.2, 19.65) == 19.65);
        REQUIRE(wrap(106.1, 19.65, 106.2) == 106.1);
        REQUIRE(wrap(106.1, 106.2, 19.65) == 106.1);
        REQUIRE(wrap(-88.7, -88.7, -88.3) == -88.7);
        REQUIRE(wrap(-88.7, -88.3, -88.7) == -88.7);
        REQUIRE(wrap(-88.31, -88.7, -88.3) == -88.31);
        REQUIRE(wrap(-88.31, -88.3, -88.7) == -88.31);
        REQUIRE(wrap(-5.17, -5.17, 2.65) == -5.17);
        REQUIRE(wrap(-5.17, 2.65, -5.17) == -5.17);
        REQUIRE(wrap(2.64, -5.17, 2.65) == 2.64);
        REQUIRE(wrap(2.64, 2.65, -5.17) == 2.64);

        // Off top of range.
        REQUIRE(wrap(12.6, 0.0, 12.6) == Approx(0.0));
        REQUIRE(wrap(12.6, 12.6, 0.0) == Approx(0.0));
        REQUIRE(wrap(27.1, 0.0, 12.6) == Approx(1.9));
        REQUIRE(wrap(27.1, 12.6, 0.0) == Approx(1.9));
        REQUIRE(wrap(0.0, -8.9, 0.0) == Approx(-8.9));
        REQUIRE(wrap(0.0, 0.0, -8.9) == Approx(-8.9));
        REQUIRE(wrap(11.3, -8.9, 0.0) == Approx(-6.5));
        REQUIRE(wrap(11.3, 0.0, -8.9) == Approx(-6.5));
        REQUIRE(wrap(33.4, 10.6, 33.4) == Approx(10.6));
        REQUIRE(wrap(33.4, 33.4, 10.6) == Approx(10.6));
        REQUIRE(wrap(62.33, 10.6, 33.4) == Approx(16.73));
        REQUIRE(wrap(62.33, 33.4, 10.6) == Approx(16.73));
        REQUIRE(wrap(-46.5, -73.7, -46.5) == Approx(-73.7));
        REQUIRE(wrap(-46.5, -46.5, -73.7) == Approx(-73.7));
        REQUIRE(wrap(-21.1, -73.7, -46.5) == Approx(-48.3));
        REQUIRE(wrap(-21.1, -46.5, -73.7) == Approx(-48.3));
        REQUIRE(wrap(13.9, -15.4, 13.9) == Approx(-15.4));
        REQUIRE(wrap(13.9, 13.9, -15.4) == Approx(-15.4));
        REQUIRE(wrap(156.3, -15.4, 13.9) == Approx(9.8));
        REQUIRE(wrap(156.3, 13.9, -15.4) == Approx(9.8));

        // Off bottom of range.
        REQUIRE(wrap(-0.1, 0.0, 12.6) == Approx(12.5));
        REQUIRE(wrap(-0.1, 12.6, 0.0) == Approx(12.5));
        REQUIRE(wrap(-36.61, 0.0, 12.6) == Approx(1.19));
        REQUIRE(wrap(-36.61, 12.6, 0.0) == Approx(1.19));
        REQUIRE(wrap(-8.95, -8.9, 0.0) == Approx(-0.05));
        REQUIRE(wrap(-8.95, 0.0, -8.9) == Approx(-0.05));
        REQUIRE(wrap(-11.55, -8.9, 0.0) == Approx(-2.65));
        REQUIRE(wrap(-11.55, 0.0, -8.9) == Approx(-2.65));
        REQUIRE(wrap(10.5, 10.6, 33.4) == Approx(33.3));
        REQUIRE(wrap(10.5, 33.4, 10.6) == Approx(33.3));
        REQUIRE(wrap(-1.3, 10.6, 33.4) == Approx(21.5));
        REQUIRE(wrap(-1.3, 33.4, 10.6) == Approx(21.5));
        REQUIRE(wrap(-73.8, -73.7, -46.5) == Approx(-46.6));
        REQUIRE(wrap(-73.8, -46.5, -73.7) == Approx(-46.6));
        REQUIRE(wrap(-259.22, -73.7, -46.5) == Approx(-68.82));
        REQUIRE(wrap(-259.22, -46.5, -73.7) == Approx(-68.82));
        REQUIRE(wrap(-15.5, -15.4, 13.9) == Approx(13.8));
        REQUIRE(wrap(-15.5, 13.9, -15.4) == Approx(13.8));
        REQUIRE(wrap(-41.63, -15.4, 13.9) == Approx(-12.33));
        REQUIRE(wrap(-41.63, 13.9, -15.4) == Approx(-12.33));
    }
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

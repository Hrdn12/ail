/** \file test_Vector2d.cpp
    \brief Unit testing for the Vector2d class.

    Depends on the Catch framework: https://github.com/philsquared/Catch

    Part of the Avid Insight Library (avidinsight.uk/ail).
    Copyright (C) 2015-16 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include "../common.h"

using namespace ail::math;

TEST_CASE("Vector2d - construction and assignment", "[math::Vector2d]")
{
    SECTION("Default construction to 0")
    {
        Vector2d<int> vi;
        CHECK(vi.x == 0);
        CHECK(vi.y == 0);

        Vector2d<double> vd;
        CHECK(vd.x == 0.0);
        CHECK(vd.y == 0.0);
    }

    SECTION("Construction - integers")
    {
        Vector2d<int> v1(81, -4);
        CHECK(v1.x == 81);
        CHECK(v1.y == -4);

        Vector2d<int> v2(-33, 10);
        CHECK(v2.x == -33);
        CHECK(v2.y == 10);
    }

    SECTION("Construction - floating point")
    {
        Vector2d<double> v1(12.34, -56.78);
        CHECK(v1.x == Approx(12.34));
        CHECK(v1.y == Approx(-56.78));

        Vector2d<double> v2(-0.38, 0.45);
        CHECK(v2.x == Approx(-0.38));
        CHECK(v2.y == Approx(0.45));
    }

    SECTION("Uniform initialisation - integer")
    {
        Vector2d<int> v1 {81, -4};
        CHECK(v1.x == 81);
        CHECK(v1.y == -4);

        Vector2d<int> v2 {-33, 10};
        CHECK(v2.x == -33);
        CHECK(v2.y == 10);

        Vector2d<int> v3 {};
        CHECK(v3.x == 0);
        CHECK(v3.y == 0);
    }

    SECTION("Uniform initialisation - floating point")
    {
        Vector2d<double> v1 {12.34, -56.78};
        CHECK(v1.x == Approx(12.34));
        CHECK(v1.y == Approx(-56.78));

        Vector2d<double> v2 {-0.38, 0.45};
        CHECK(v2.x == Approx(-0.38));
        CHECK(v2.y == Approx(0.45));

        Vector2d<double> v3 {};
        CHECK(v3.x == 0.0);
        CHECK(v3.y == 0.0);
    }

    SECTION("Uniform initialisation - wrong size")
    {
        CHECK_THROWS(Vector2d<int> {14});
        CHECK_THROWS((Vector2d<int> {26, 53, 12}));

        CHECK_THROWS(Vector2d<double> {1.25});
        CHECK_THROWS((Vector2d<double> {5.96, 4.67, 9.001}));
    }

    SECTION("Copy construction")
    {
        Vector2d<int> vi1(27, -1);
        Vector2d<int> vi2(vi1);
        CHECK(vi2.x == vi1.x);
        CHECK(vi2.y == vi1.y);

        Vector2d<double> vd1(34.21, 78.56);
        Vector2d<double> vd2(vd1);
        CHECK(vd2.x == vd1.x);
        CHECK(vd2.y == vd1.y);
    }

    SECTION("Copy assignment")
    {
        Vector2d<int> vi1(-44, 2);
        Vector2d<int> vi2;
        vi2 = vi1;
        CHECK(vi2.x == vi1.x);
        CHECK(vi2.y == vi1.y);

        Vector2d<double> vd1(43.21, 87.65);
        Vector2d<double> vd2;
        vd2 = vd1;
        CHECK(vd2.x == vd1.x);
        CHECK(vd2.y == vd1.y);
    }

    SECTION("set() modifier")
    {
        Vector2d<int> vi;
        Vector2d<double> vd;

        vi.set(132, 53);
        CHECK(vi.x == 132);
        CHECK(vi.y == 53);

        vd.set(5.13, -4.98);
        CHECK(vd.x == 5.13);
        CHECK(vd.y == -4.98);
    }
}

TEST_CASE("Vector2d - comparison operators", "[math::Vector2d]")
{
    const Vector2d<int>
        vi1(22, -87),
        vi2(22, -87),
        vi3(66, 15);

    const Vector2d<double>
        vd1(34.5, 23.4),
        vd2(34.5, 23.4),
        vd3(-12.3, 45.6);

    SECTION("Equality - integers")
    {
        CHECK(vi1 == vi1);
        CHECK(vi1 == vi2);
        CHECK(vi2 == vi1);
        CHECK_FALSE(vi1 == vi3);
        CHECK_FALSE(vi2 == vi3);
        CHECK_FALSE(vi3 == vi1);
        CHECK_FALSE(vi3 == vi2);
    }

    SECTION("Equality - floating point")
    {
        CHECK(vd1 == vd1);
        CHECK(vd1 == vd2);
        CHECK(vd2 == vd1);
        CHECK_FALSE(vd1 == vd3);
        CHECK_FALSE(vd2 == vd3);
        CHECK_FALSE(vd3 == vd1);
        CHECK_FALSE(vd3 == vd2);
    }

    SECTION("Inequality - integers")
    {
        CHECK_FALSE(vi1 != vi1);
        CHECK_FALSE(vi1 != vi2);
        CHECK_FALSE(vi2 != vi1);
        CHECK(vi1 != vi3);
        CHECK(vi2 != vi3);
        CHECK(vi3 != vi1);
        CHECK(vi3 != vi2);
    }

    SECTION("Inequality - floating point")
    {
        CHECK_FALSE(vi1 != vi1);
        CHECK_FALSE(vi1 != vi2);
        CHECK_FALSE(vi2 != vi1);
        CHECK(vi1 != vi3);
        CHECK(vi2 != vi3);
        CHECK(vi3 != vi1);
        CHECK(vi3 != vi2);
    }
}

TEST_CASE("Vector2d - integer arithmetic", "[math::Vector2d]")
{
    Vector2d<int>
        v1(0, 0),       v2(15, 26),
        v3(-31, 11),    v4(29, -5),
        v5(-41, -18),   v6(301, 297);

    const int s1 = 0, s2 = 33, s3 = -7;

    SECTION("Vector addition")
    {
        v1 = v1 + v2;
        CHECK(v1.x == 15);
        CHECK(v1.y == 26);

        v3 = v3 + v4;
        CHECK(v3.x == -2);
        CHECK(v3.y == 6);

        v5 = v5 + v6;
        CHECK(v5.x == 260);
        CHECK(v5.y == 279);
    }

    SECTION("Vector addition assignment")
    {
        v1 += v2;
        CHECK(v1.x == 15);
        CHECK(v1.y == 26);

        v3 += v4;
        CHECK(v3.x == -2);
        CHECK(v3.y == 6);

        v5 += v6;
        CHECK(v5.x == 260);
        CHECK(v5.y == 279);
    }

    SECTION("Vector subtraction")
    {
        v1 = v1 - v2;
        CHECK(v1.x == -15);
        CHECK(v1.y == -26);

        v3 = v3 - v4;
        CHECK(v3.x == -60);
        CHECK(v3.y == 16);

        v5 = v5 - v6;
        CHECK(v5.x == -342);
        CHECK(v5.y == -315);
    }

    SECTION("Vector subtraction assignment")
    {
        v1 -= v2;
        CHECK(v1.x == -15);
        CHECK(v1.y == -26);

        v3 -= v4;
        CHECK(v3.x == -60);
        CHECK(v3.y == 16);

        v5 -= v6;
        CHECK(v5.x == -342);
        CHECK(v5.y == -315);
    }

    SECTION("Scalar multiplication")
    {
        v2 = v2 * s1;
        CHECK(v2.x == 0);
        CHECK(v2.y == 0);

        v4 = v4 * s2;
        CHECK(v4.x == 957);
        CHECK(v4.y == -165);

        v6 = s3 * v6; // scalar first
        CHECK(v6.x == -2107);
        CHECK(v6.y == -2079);
    }

    SECTION("Scalar multiplication assignment")
    {
        v2 *= s1;
        CHECK(v2.x == 0);
        CHECK(v2.y == 0);

        v4 *= s2;
        CHECK(v4.x == 957);
        CHECK(v4.y == -165);

        v6 *= s3;
        CHECK(v6.x == -2107);
        CHECK(v6.y == -2079);
    }

    SECTION("Scalar division")
    {
        v2 = v2 / s3;
        CHECK(v2.x == -2);
        CHECK(v2.y == -3);

        v3 = s2 / v3; // scalar first
        CHECK(v3.x == -1);
        CHECK(v3.y == 3);

        v6 = v6 / s2;
        CHECK(v6.x == 9);
        CHECK(v6.y == 9);
    }

    SECTION("Scalar division assignment")
    {
        v2 /= s3;
        CHECK(v2.x == -2);
        CHECK(v2.y == -3);

        v3 /= s2;
        CHECK(v3.x == 0);
        CHECK(v3.y == 0);

        v6 /= s2;
        CHECK(v6.x == 9);
        CHECK(v6.y == 9);
    }

    SECTION("Negation")
    {
        v1 = -v1;
        CHECK(v1.x == 0);
        CHECK(v1.y == 0);

        v3 = -v3;
        CHECK(v3.x == 31);
        CHECK(v3.y == -11);

        v5 = -v5;
        CHECK(v5.x == 41);
        CHECK(v5.y == 18);
    }

    SECTION("Combined arithmetic")
    {
        v1 -= v2 * s2 + v3 - v6 / s3 + s1 / v5;

        CHECK(v1.x == -507);
        CHECK(v1.y == -911);
    }
}

TEST_CASE("Vector2d - floating point arithmetic", "[math::Vector2d]")
{
    Vector2d<double>
        v1(0.0, 0.0), v2(0.59, 0.22),
        v3(-14.6, 21.4), v4(30.05, -8.4),
        v5(-10.6, -41.11), v6(204.109, 571.99);

    const double s1 = 0.0, s2 = 5.6, s3 = -2.5;

    SECTION("Vector addition")
    {
        v1 = v1 + v2;
        CHECK(v1.x == Approx(0.59));
        CHECK(v1.y == Approx(0.22));

        v3 = v3 + v4;
        CHECK(v3.x == Approx(15.45));
        CHECK(v3.y == Approx(13.0));

        v5 = v5 + v6;
        CHECK(v5.x == Approx(193.509));
        CHECK(v5.y == Approx(530.88));
    }

    SECTION("Vector addition assignment")
    {
        v1 += v2;
        CHECK(v1.x == Approx(0.59));
        CHECK(v1.y == Approx(0.22));

        v3 += v4;
        CHECK(v3.x == Approx(15.45));
        CHECK(v3.y == Approx(13.0));

        v5 += v6;
        CHECK(v5.x == Approx(193.509));
        CHECK(v5.y == Approx(530.88));
    }

    SECTION("Vector subtraction")
    {
        v1 = v1 - v2;
        CHECK(v1.x == Approx(-0.59));
        CHECK(v1.y == Approx(-0.22));

        v3 = v3 - v4;
        CHECK(v3.x == Approx(-44.65));
        CHECK(v3.y == Approx(29.8));

        v5 = v5 - v6;
        CHECK(v5.x == Approx(-214.709));
        CHECK(v5.y == Approx(-613.1));
    }

    SECTION("Vector subtraction assignment")
    {
        v1 -= v2;
        CHECK(v1.x == Approx(-0.59));
        CHECK(v1.y == Approx(-0.22));

        v3 -= v4;
        CHECK(v3.x == Approx(-44.65));
        CHECK(v3.y == Approx(29.8));

        v5 -= v6;
        CHECK(v5.x == Approx(-214.709));
        CHECK(v5.y == Approx(-613.1));
    }

    SECTION("Scalar multiplication")
    {
        v2 = v2 * s1;
        CHECK(v2.x == Approx(0.0));
        CHECK(v2.y == Approx(0.0));

        v4 = v4 * s2;
        CHECK(v4.x == Approx(168.28));
        CHECK(v4.y == Approx(-47.04));

        v6 = s3 * v6; // scalar first
        CHECK(v6.x == Approx(-510.2725));
        CHECK(v6.y == Approx(-1429.975));
    }

    SECTION("Scalar multiplication assignment")
    {
        v2 *= s1;
        CHECK(v2.x == Approx(0.0));
        CHECK(v2.y == Approx(0.0));

        v4 *= s2;
        CHECK(v4.x == Approx(168.28));
        CHECK(v4.y == Approx(-47.04));

        v6 *= s3;
        CHECK(v6.x == Approx(-510.2725));
        CHECK(v6.y == Approx(-1429.975));
    }

    SECTION("Scalar division")
    {
        v2 = v2 / s3;
        CHECK(v2.x == Approx(-0.236));
        CHECK(v2.y == Approx(-0.088));

        v3 = s2 / v3; // scalar first
        CHECK(v3.x == Approx(-0.38356164));
        CHECK(v3.y == Approx(0.26168224));

        v6 = v6 / s2;
        CHECK(v6.x == Approx(36.44803571));
        CHECK(v6.y == Approx(102.14107143));
    }

    SECTION("Scalar division assignment")
    {
        v2 /= s3;
        CHECK(v2.x == Approx(-0.236));
        CHECK(v2.y == Approx(-0.088));

        v3 /= s2;
        CHECK(v3.x == Approx(-2.60714286));
        CHECK(v3.y == Approx(3.82142857));

        v6 /= s2;
        CHECK(v6.x == Approx(36.44803571));
        CHECK(v6.y == Approx(102.14107143));
    }

    SECTION("Negation")
    {
        v1 = -v1;
        CHECK(v1.x == Approx(0.0));
        CHECK(v1.y == Approx(0.0));

        v3 = -v3;
        CHECK(v3.x == Approx(14.6));
        CHECK(v3.y == Approx(-21.4));

        v5 = -v5;
        CHECK(v5.x == Approx(10.6));
        CHECK(v5.y == Approx(41.11));
    }

    SECTION("Combined arithmetic")
    {
        v1 -= v2 * s2 + v3 - v6 / s3 + s1 / v5;

        CHECK(v1.x == Approx(-70.3476));
        CHECK(v1.y == Approx(-251.428));
    }
}

TEST_CASE("Vector2d - length", "[math::Vector2d]")
{
    const Vector2d<double>
        vd1(0.0, 0.0),
        vd2(-12.31, 0.0),
        vd3(0.0, 134.369),
        vd4(5.0, 10.0),
        vd5(-9.3, 4.7),
        vd6(2.005, -19.3);

    const Vector2d<int>
        vi1(0, 0),
        vi2(3, 9),
        vi3(-7, 3),
        vi4(4, -4),
        vi5(153, 209),
        vi6(-391, -227);

    SECTION("Euclidean length")
    {
        CHECK(vd1.getLength() == Approx(0.0));
        CHECK(vd2.getLength() == Approx(12.31));
        CHECK(vd3.getLength() == Approx(134.369));
        CHECK(vd4.getLength() == Approx(11.180339887));
        CHECK(vd5.getLength() == Approx(10.42017274));
        CHECK(vd6.getLength() == Approx(19.40386624));
    }

    SECTION("Euclidean squared length")
    {
        CHECK(vd1.getSqLength() == Approx(0.0));
        CHECK(vd2.getSqLength() == Approx(151.5361));
        CHECK(vd3.getSqLength() == Approx(18055.028161));
        CHECK(vd4.getSqLength() == Approx(124.99999999));
        CHECK(vd5.getSqLength() == Approx(108.57999993));
        CHECK(vd6.getSqLength() == Approx(376.51002506));
    }

    SECTION("Cross-check: euclidean length vs. square length")
    {
        CHECK(vd1.getSqLength() == Approx(vd1.getLength() * vd1.getLength()));
        CHECK(vd2.getSqLength() == Approx(vd2.getLength() * vd2.getLength()));
        CHECK(vd3.getSqLength() == Approx(vd3.getLength() * vd3.getLength()));
        CHECK(vd4.getSqLength() == Approx(vd4.getLength() * vd4.getLength()));
        CHECK(vd5.getSqLength() == Approx(vd5.getLength() * vd5.getLength()));
        CHECK(vd6.getSqLength() == Approx(vd6.getLength() * vd6.getLength()));
    }

    SECTION("Rectilinear length - integer")
    {
        CHECK(vi1.getRectilinearLength() == 0);
        CHECK(vi2.getRectilinearLength() == 12);
        CHECK(vi3.getRectilinearLength() == 10);
        CHECK(vi4.getRectilinearLength() == 8);
        CHECK(vi5.getRectilinearLength() == 362);
        CHECK(vi6.getRectilinearLength() == 618);
    }

    SECTION("Rectilinear length - floating point")
    {
        CHECK(vd1.getRectilinearLength() == Approx(0.0));
        CHECK(vd2.getRectilinearLength() == Approx(12.31));
        CHECK(vd3.getRectilinearLength() == Approx(134.369));
        CHECK(vd4.getRectilinearLength() == Approx(15.0));
        CHECK(vd5.getRectilinearLength() == Approx(14.0));
        CHECK(vd6.getRectilinearLength() == Approx(21.305));
    }
}

TEST_CASE("Vector2d - dot product", "[math::Vector2d]")
{
    const Vector2d<double>
        v1a(3.4, 9.2),
        v1b(9.2, -3.4), // right angles to v1
        v1c(-9.2, 3.4), // right angles to v1
        v2(8.6, 1.9),
        v3(-2.7, 0.1);

    const Vector2d<double>
        v1aUnit = v1a.getNormalised(),
        v1bUnit = v1b.getNormalised(),
        v1cUnit = v1c.getNormalised(),
        v2Unit = v2.getNormalised(),
        v3Unit = v3.getNormalised();

    SECTION("Same vector")
    {
        CHECK(v1aUnit.dot(v1aUnit) == Approx(1.0));
        CHECK(v2Unit.dot(v2Unit) == Approx(1.0));
        CHECK(v3Unit.dot(v3Unit) == Approx(1.0));
    }

    SECTION("Acute angle")
    {
        CHECK(v1a.dot(v2) == Approx(46.72));              // not normalised
        CHECK(v1aUnit.dot(v2Unit) == Approx(0.54083950)); // normalised
    }

    SECTION("Right angle")
    {
        CHECK(v1aUnit.dot(v1bUnit) == Approx(0.0));
        CHECK(v1aUnit.dot(v1cUnit) == Approx(0.0));
    }

    SECTION("Obtuse angle")
    {
        CHECK(v1a.dot(v3) == Approx(-8.26));               // not normalised
        CHECK(v1aUnit.dot(v3Unit) == Approx(-0.31169589)); // normalised
    }

    SECTION("Reverse vector")
    {
        CHECK(v1aUnit.dot(-v1aUnit) == Approx(-1.0));
        CHECK(v2Unit.dot(-v2Unit) == Approx(-1.0));
        CHECK(v3Unit.dot(-v3Unit) == Approx(-1.0));
    }
}

TEST_CASE("Vector2d - projection")
{
    const Vector2d<double>
        v1(0.0, 0.0),
        v2(4.69, 9.71),
        v3(-13.44, 21.8),
        v4(0.11, -12.6);

    SECTION("Scalar projection")
    {
        CHECK(v1.getScalarProjection(v2) == Approx(0.0));
        CHECK(v3.getScalarProjection(v1) == Approx(0.0));
        
        CHECK(v2.getScalarProjection(v3) == Approx(5.80414799));
        CHECK(v3.getScalarProjection(v4) == Approx(-21.91649816));
        CHECK(v4.getScalarProjection(v2) == Approx(-11.29800378));
    }

    SECTION("Vector projection")
    {
        Vector2d<double> v;

        v = v1.getVectorProjection(v2);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(0.0));

        v = v3.getVectorProjection(v1);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(0.0));
        
        v = v2.getVectorProjection(v3);
        CHECK(v.x == Approx(-3.04598437));
        CHECK(v.y == Approx(4.94065918));

        v = v3.getVectorProjection(v4);
        CHECK(v.x == Approx(-0.19132722));
        CHECK(v.y == Approx(21.91566302));

        v = v4.getVectorProjection(v2);
        CHECK(v.x == Approx(-4.91384749));
        CHECK(v.y == Approx(-10.17344544));
    }
}

TEST_CASE("Vector2d - normalisation", "[math::Vector2d]")
{
    SECTION("Normalisation")
    {
        Vector2d<double> v1, v2;

        v1.set(-43.2, 87.6);
        v2 = v1.getNormalised(); // copy
        v1.normalise();          // in-place
        CHECK(v1.x == Approx(-0.44229248));
        CHECK(v1.y == Approx(0.89687087));
        CHECK(v2.x == Approx(v1.x));
        CHECK(v2.y == Approx(v1.y));
        CHECK(v1.getLength() == Approx(1.0));

        v1.set(12.36, 55.9);
        v2 = v1.getNormalised(); // copy
        v1.normalise();          // in-place
        CHECK(v1.x == Approx(0.21589463));
        CHECK(v1.y == Approx(0.97641667));
        CHECK(v2.x == Approx(v1.x));
        CHECK(v2.y == Approx(v1.y));
        CHECK(v1.getLength() == Approx(1.0));
    }
}

TEST_CASE("Vector2d - tangents", "[math::Vector2d]")
{
    const Vector2d<int>
        vi1(15, 26),  vi1_l(-26, 15),  vi1_r(26, -15),
        vi2(-19, 42), vi2_l(-42, -19), vi2_r(42, 19);

    const Vector2d<double>
        vd1(0.339, -33.91),   vd1_l(33.91, 0.339),   vd1_r(-33.91, -0.339),
        vd2(-156.3, -64.002), vd2_l(64.002, -156.3), vd2_r(-64.002, 156.3);

    SECTION("Left - integer")
    {
        Vector2d<int> v;

        v = vi1.getLeftTangent();
        CHECK(v.x == vi1_l.x);
        CHECK(v.y == vi1_l.y);

        v = vi2.getLeftTangent();
        CHECK(v.x == vi2_l.x);
        CHECK(v.y == vi2_l.y);
    }

    SECTION("Left - floating point")
    {
        Vector2d<double> v;

        v = vd1.getLeftTangent();
        CHECK(v.x == Approx(vd1_l.x));
        CHECK(v.y == Approx(vd1_l.y));

        v = vd2.getLeftTangent();
        CHECK(v.x == Approx(vd2_l.x));
        CHECK(v.y == Approx(vd2_l.y));
    }

    SECTION("Right - integer")
    {
        Vector2d<int> v;

        v = vi1.getRightTangent();
        CHECK(v.x == vi1_r.x);
        CHECK(v.y == vi1_r.y);

        v = vi2.getRightTangent();
        CHECK(v.x == vi2_r.x);
        CHECK(v.y == vi2_r.y);
    }

    SECTION("Right - floating point")
    {
        Vector2d<double> v;

        v = vd1.getRightTangent();
        CHECK(v.x == Approx(vd1_r.x));
        CHECK(v.y == Approx(vd1_r.y));

        v = vd2.getRightTangent();
        CHECK(v.x == Approx(vd2_r.x));
        CHECK(v.y == Approx(vd2_r.y));
    }
}

TEST_CASE("Vector2d - distance", "[math::Vector2d]")
{
    const Vector2d<double>
        vd1(0.0, 0.0),          vd2(2.6, -9.1),
        vd3(10.0, 0.0),         vd4(24.94, 0.0),
        vd5(6.0, 0.0),          vd6(-4.22, 0.0),
        vd7(0.0, 1.5),          vd8(0.0, 13.8),
        vd9(0.0, -22.8),        vd10(0.0, -17.391),
        vd11(5.136, 19.64),     vd12(-14.1, 27.3),
        vd13(-57.301, 2.88),    vd14(9.648, -101.9);

    SECTION("Euclidean distance")
    {
        // Zero distance
        CHECK(vd1.getDistance(vd1) == Approx(0.0));
        CHECK(vd2.getDistance(vd2) == Approx(0.0));
        // Axis-aligned
        CHECK(vd3.getDistance(vd4) == Approx(14.94));
        CHECK(vd5.getDistance(vd6) == Approx(10.22));
        CHECK(vd7.getDistance(vd8) == Approx(12.3));
        CHECK(vd9.getDistance(vd10) == Approx(5.409));
        // Arbitrary
        CHECK(vd11.getDistance(vd12) == Approx(20.705055));
        CHECK(vd13.getDistance(vd14) == Approx(124.342338));
    }

    SECTION("Euclidean squared distance")
    {
        // Zero distance
        CHECK(vd1.getSqDistance(vd1) == Approx(0.0));
        CHECK(vd2.getSqDistance(vd2) == Approx(0.0));
        // Axis-aligned
        CHECK(vd3.getSqDistance(vd4) == Approx(223.2036));
        CHECK(vd5.getSqDistance(vd6) == Approx(104.4484));
        CHECK(vd7.getSqDistance(vd8) == Approx(151.29));
        CHECK(vd9.getSqDistance(vd10) == Approx(29.257281));
        // Arbitrary
        CHECK(vd11.getSqDistance(vd12) == Approx(428.69930255));
        CHECK(vd13.getSqDistance(vd14) == Approx(15461.01701931));
    }

    SECTION("Rectilinear distance - integer")
    {
        // Zero distance
        CHECK(Vector2d<int>(0, 0).getRectilinearDistance(Vector2d<int>(0, 0)) == 0);
        CHECK(Vector2d<int>(-54, 1).getRectilinearDistance(Vector2d<int>(-54, 1)) == 0);
        // Axis-aligned
        CHECK(Vector2d<int>(5, 3).getRectilinearDistance(Vector2d<int>(9, 3)) == 4);
        CHECK(Vector2d<int>(-21, 0).getRectilinearDistance(Vector2d<int>(5, 0)) == 26);
        CHECK(Vector2d<int>(-4, 11).getRectilinearDistance(Vector2d<int>(-4, 19)) == 8);
        CHECK(Vector2d<int>(0, 7).getRectilinearDistance(Vector2d<int>(0, -8)) == 15);
        // Arbitrary
        CHECK(Vector2d<int>(15, 6).getRectilinearDistance(Vector2d<int>(3, 21)) == 27);
        CHECK(Vector2d<int>(-2, 46).getRectilinearDistance(Vector2d<int>(13, 63)) == 32);
    }

    SECTION("Rectilinear distance - floating point")
    {
        // Zero distance
        CHECK(vd1.getRectilinearDistance(vd1) == Approx(0.0));
        CHECK(vd2.getRectilinearDistance(vd2) == Approx(0.0));
        // Axis-aligned
        CHECK(vd3.getRectilinearDistance(vd4) == Approx(14.94));
        CHECK(vd5.getRectilinearDistance(vd6) == Approx(10.22));
        CHECK(vd7.getRectilinearDistance(vd8) == Approx(12.3));
        CHECK(vd9.getRectilinearDistance(vd10) == Approx(5.409));
        // Arbitrary
        CHECK(vd11.getRectilinearDistance(vd12) == Approx(26.896));
        CHECK(vd13.getRectilinearDistance(vd14) == Approx(171.729));
    }
}

TEST_CASE("Vector2d - proximity", "[math::Vector2d]")
{
    // TODO: Construct vectors here instead of in the test sections.

    SECTION("Euclidean proximity")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        CHECK(Vector2d<double>(0.0, 0.0).isNear(Vector2d<double>(0.0, 0.0), 0.0));
        CHECK(Vector2d<double>(-5.39, 4.16).isNear(Vector2d<double>(-5.39, 4.16), 0.0));
        CHECK(Vector2d<double>(46.98, -18.6).isNear(Vector2d<double>(46.98, -18.6), 24.1));
        CHECK(Vector2d<double>(46.98, -18.6).isNear(Vector2d<double>(46.98, -18.6), -24.1));

        // In range - constrained to X axis
        CHECK(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), 8.6));
        CHECK(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), -8.6));
        CHECK(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), 34.5));
        CHECK(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), -34.5));
        // In range - constrained to Y axis
        CHECK(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), 15.5));
        CHECK(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), -15.5));
        CHECK(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), 8.1));
        CHECK(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), -8.1));
        // In range - no constraints
        CHECK(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), 13.99));
        CHECK(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), -13.99));
        CHECK(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), 65.88));
        CHECK(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), -65.88));

        // Boundary - constrained to X axis
        CHECK(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), 3.88));
        CHECK(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), -3.88));
        CHECK(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), 19.85));
        CHECK(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), -19.85));
        // Boundary - constrained to Y axis
        CHECK(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), 12.33));
        CHECK(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), -12.33));
        CHECK(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), 4.96));
        CHECK(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), -4.96));
        // Boundary - no constraints
        CHECK(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), 5.57));
        CHECK(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), -5.57));
        CHECK(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), 49.42));
        CHECK(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), -49.42));

        // Out of range - constrained to X axis
        CHECK_FALSE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), 1.48));
        CHECK_FALSE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), -1.48));
        CHECK_FALSE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), 18.98));
        CHECK_FALSE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), -18.98));
        // Out of range - constrained to Y axis
        CHECK_FALSE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), 7.6));
        CHECK_FALSE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), -7.6));
        CHECK_FALSE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), 4.67));
        CHECK_FALSE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), -4.67));
        // Out of range - no constraints
        CHECK_FALSE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), 1.901));
        CHECK_FALSE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), -1.901));
        CHECK_FALSE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), 46.112));
        CHECK_FALSE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), -46.112));
    }

    SECTION("Rectilinear proximity - integer")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        CHECK(Vector2d<int>(0, 0).isNearRectilinear(Vector2d<int>(0, 0), 0));
        CHECK(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(12, -4), 0));
        CHECK(Vector2d<int>(-9, 25).isNearRectilinear(Vector2d<int>(-9, 25), 2));
        CHECK(Vector2d<int>(-9, 25).isNearRectilinear(Vector2d<int>(-9, 25), -2));

        // In range - constrained to X axis
        CHECK(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), 4));
        CHECK(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), -4));
        CHECK(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), 14));
        CHECK(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), -14));
        // In range - constrained to Y axis
        CHECK(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), 10));
        CHECK(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), -10));
        CHECK(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), 9));
        CHECK(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), -9));
        // In range - no constraints
        CHECK(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), 23));
        CHECK(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), -23));
        CHECK(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), 11));
        CHECK(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), -11));

        // Boundary - constrained to X axis
        CHECK(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), 2));
        CHECK(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), -2));
        CHECK(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), 9));
        CHECK(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), -9));
        // Boundary - constrained to Y axis
        CHECK(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), 5));
        CHECK(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), -5));
        CHECK(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), 8));
        CHECK(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), -8));
        // Boundary - no constraints
        CHECK(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), 18));
        CHECK(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), -18));
        CHECK(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), 8));
        CHECK(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), -8));

        // Out of range - constrained to X axis
        CHECK_FALSE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), 1));
        CHECK_FALSE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), -1));
        CHECK_FALSE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), 6));
        CHECK_FALSE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), -6));
        // Out of range - constrained to Y axis
        CHECK_FALSE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), 2));
        CHECK_FALSE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), -2));
        CHECK_FALSE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), 5));
        CHECK_FALSE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), -5));
        // Out of range - no constraints
        CHECK_FALSE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), 15));
        CHECK_FALSE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), -15));
        CHECK_FALSE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), 3));
        CHECK_FALSE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), -3));
    }

    SECTION("Rectilinear proximity - floating point")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        CHECK(Vector2d<double>(0.0, 0.0).isNearRectilinear(Vector2d<double>(0.0, 0.0), 0.0));
        CHECK(Vector2d<double>(45.11, -20.9).isNearRectilinear(Vector2d<double>(45.11, -20.9), 0.0));
        CHECK(Vector2d<double>(-2.23, 0.6).isNearRectilinear(Vector2d<double>(-2.23, 0.6), 3.4));
        CHECK(Vector2d<double>(-2.23, 0.6).isNearRectilinear(Vector2d<double>(-2.23, 0.6), -3.4));

        // In range - constrained to X axis
        CHECK(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), 8.2));
        CHECK(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), -8.2));
        CHECK(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), 10.13));
        CHECK(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), -10.13));
        // In range - constrained to Y axis
        CHECK(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), 6.69));
        CHECK(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), -6.69));
        CHECK(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), 14.26));
        CHECK(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), -14.26));
        // In range - no constraints
        CHECK(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), 2.5));
        CHECK(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), -2.5));
        CHECK(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), 167.76));
        CHECK(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), -167.76));

        // Boundary - constrained to X axis
        CHECK(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), 4.68));
        CHECK(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), -4.68));
        CHECK(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), 4.99));
        CHECK(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), -4.99));
        // Boundary - constrained to Y axis
        CHECK(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), 3.08));
        CHECK(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), -3.08));
        CHECK(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), 8.221));
        CHECK(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), -8.221));
        // Boundary - no constraints
        CHECK(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), 1.22));
        CHECK(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), -1.22));
        CHECK(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), 150.182));
        CHECK(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), -150.182));

        // Out of range - constrained to X axis
        CHECK_FALSE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), 4.1));
        CHECK_FALSE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), -4.1));
        CHECK_FALSE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), 3.08));
        CHECK_FALSE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), -3.08));
        // Out of range - constrained to Y axis
        CHECK_FALSE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), 2.4));
        CHECK_FALSE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), -2.4));
        CHECK_FALSE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), 7.93));
        CHECK_FALSE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), -7.93));
        // Out of range - no constraints
        CHECK_FALSE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), 0.44));
        CHECK_FALSE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), -0.44));
        CHECK_FALSE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), 146.39));
        CHECK_FALSE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), -146.39));
    }

    SECTION("Approx equality - integer")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        CHECK(Vector2d<int>(0, 0).isApproxEqual(Vector2d<int>(0, 0), 0));
        CHECK(Vector2d<int>(14, -3).isApproxEqual(Vector2d<int>(14, -3), 0));
        CHECK(Vector2d<int>(-28, 11).isApproxEqual(Vector2d<int>(-28, 11), 5));
        CHECK(Vector2d<int>(-28, 11).isApproxEqual(Vector2d<int>(-28, 11), -5));

        // Both components in range.
        CHECK(Vector2d<int>(19, 11).isApproxEqual(Vector2d<int>(23, 10), 8));
        CHECK(Vector2d<int>(19, 11).isApproxEqual(Vector2d<int>(23, 10), -8));
        CHECK(Vector2d<int>(5, -63).isApproxEqual(Vector2d<int>(-28, -60), 41));
        CHECK(Vector2d<int>(5, -63).isApproxEqual(Vector2d<int>(-28, -60), -41));

        // One in range, one at boundary.
        CHECK(Vector2d<int>(-1, 2).isApproxEqual(Vector2d<int>(22, 10), 23));
        CHECK(Vector2d<int>(-1, 2).isApproxEqual(Vector2d<int>(22, 10), -23));
        CHECK(Vector2d<int>(67, 8).isApproxEqual(Vector2d<int>(61, -5), 13));
        CHECK(Vector2d<int>(67, 8).isApproxEqual(Vector2d<int>(61, -5), -13));

        // Both at boundary.
        CHECK(Vector2d<int>(51, 25).isApproxEqual(Vector2d<int>(58, 32), 7));
        CHECK(Vector2d<int>(51, 25).isApproxEqual(Vector2d<int>(58, 32), -7));
        CHECK(Vector2d<int>(-1, 9).isApproxEqual(Vector2d<int>(-5, 5), 4));
        CHECK(Vector2d<int>(-1, 9).isApproxEqual(Vector2d<int>(-5, 5), -4));

        // One out of range.
        CHECK_FALSE(Vector2d<int>(18, 55).isApproxEqual(Vector2d<int>(77, 48), 19));
        CHECK_FALSE(Vector2d<int>(18, 55).isApproxEqual(Vector2d<int>(77, 48), -19));
        CHECK_FALSE(Vector2d<int>(37, 21).isApproxEqual(Vector2d<int>(34, -8), 15));
        CHECK_FALSE(Vector2d<int>(37, 21).isApproxEqual(Vector2d<int>(34, -8), -15));

        // Both out of range.
        CHECK_FALSE(Vector2d<int>(-29, 15).isApproxEqual(Vector2d<int>(-4, 26), 8));
        CHECK_FALSE(Vector2d<int>(-29, 15).isApproxEqual(Vector2d<int>(-4, 26), -8));
        CHECK_FALSE(Vector2d<int>(76, 105).isApproxEqual(Vector2d<int>(2, -1), 51));
        CHECK_FALSE(Vector2d<int>(76, 105).isApproxEqual(Vector2d<int>(2, -1), -51));
    }

    SECTION("Approx equality - floating point")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        CHECK(Vector2d<double>(0.0, 0.0).isApproxEqual(Vector2d<double>(0.0, 0.0), 0.0));
        CHECK(Vector2d<double>(4.56, -1.98).isApproxEqual(Vector2d<double>(4.56, -1.98), 0.0));
        CHECK(Vector2d<double>(19.5, -20.01).isApproxEqual(Vector2d<double>(19.5, -20.01), 9.896));
        CHECK(Vector2d<double>(19.5, -20.01).isApproxEqual(Vector2d<double>(19.5, -20.01), -9.896));

        // Both components in range.
        CHECK(Vector2d<double>(0.2, -0.9).isApproxEqual(Vector2d<double>(0.5, -0.6), 1.2));
        CHECK(Vector2d<double>(0.2, -0.9).isApproxEqual(Vector2d<double>(0.5, -0.6), -1.2));
        CHECK(Vector2d<double>(23.99, 12.23).isApproxEqual(Vector2d<double>(-1.44, 15.5), 30.3));
        CHECK(Vector2d<double>(23.99, 12.23).isApproxEqual(Vector2d<double>(-1.44, 15.5), -30.3));

        // One in range, one at boundary.
        CHECK(Vector2d<double>(15.9, 20.1).isApproxEqual(Vector2d<double>(21.4, 19.66), 5.52));
        CHECK(Vector2d<double>(15.9, 20.1).isApproxEqual(Vector2d<double>(21.4, 19.66), -5.52));
        CHECK(Vector2d<double>(-1.4, -5.6).isApproxEqual(Vector2d<double>(-4.4, 3.8), 9.42));
        CHECK(Vector2d<double>(-1.4, -5.6).isApproxEqual(Vector2d<double>(-4.4, 3.8), -9.42));

        // Both at boundary.
        CHECK(Vector2d<double>(99.22, 26.51).isApproxEqual(Vector2d<double>(110.5, 37.79), 11.3));
        CHECK(Vector2d<double>(99.22, 26.51).isApproxEqual(Vector2d<double>(110.5, 37.79), -11.3));
        CHECK(Vector2d<double>(4.6, -12.11).isApproxEqual(Vector2d<double>(-1.23, -6.28), 5.85));
        CHECK(Vector2d<double>(4.6, -12.11).isApproxEqual(Vector2d<double>(-1.23, -6.28), -5.85));

        // One out of range.
        CHECK_FALSE(Vector2d<double>(-0.2, 10.88).isApproxEqual(Vector2d<double>(27.5, 12.47), 6.36));
        CHECK_FALSE(Vector2d<double>(-0.2, 10.88).isApproxEqual(Vector2d<double>(27.5, 12.47), -6.36));
        CHECK_FALSE(Vector2d<double>(8.1, -19.29).isApproxEqual(Vector2d<double>(1.07, -2.6), 11.8));
        CHECK_FALSE(Vector2d<double>(8.1, -19.29).isApproxEqual(Vector2d<double>(1.07, -2.6), -11.8));

        // Both out of range.
        CHECK_FALSE(Vector2d<double>(11.65, 4.591).isApproxEqual(Vector2d<double>(-24.1, 17.08), 3.402));
        CHECK_FALSE(Vector2d<double>(11.65, 4.591).isApproxEqual(Vector2d<double>(-24.1, 17.08), -3.402));
        CHECK_FALSE(Vector2d<double>(38.52, -1.603).isApproxEqual(Vector2d<double>(23.5, -16.2), 12.06));
        CHECK_FALSE(Vector2d<double>(38.52, -1.603).isApproxEqual(Vector2d<double>(23.5, -16.2), -12.06));
    }

}

TEST_CASE("Vector2d - Polar conversions", "[math::Vector2d]")
{
    const Polar<double>
        p1(0.0, 0.0),          p2(5.9, 0.0),         p3(-19.3, 0.0),
        p4(0.0, 7.6),          p5(0.0, -19.2),       p6(3.14159265, 12.6),    p7(-3.14159265, -18.9),
        p8(1.57079633, 5.1),   p9(1.57079633, -3.7), p10(4.71238898, 42.8),   p11(-1.57079633, -55.01),
        p12(-0.78539816, 9.8), p13(5.3361, 4.3),     p14(9.894328, -151.664);

    const Vector2d<double>
        v1(0.0, 0.0),
        v2(146.0, 0.0),  v3(-1.39, 0.0),
        v4(0.0, 24.31),  v5(0.0, -55.7),
        v6(5.36, -5.36), v7(-12.77, 18.32), v8(-71.87, -2.4);

    SECTION("Construction from Polar")
    {
        Vector2d<double> v;

        // Zero magnitude
        v = Vector2d<double>(p1);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(0.0));

        v = Vector2d<double>(p2);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(0.0));

        v = Vector2d<double>(p3);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(0.0));

        // X axis
        v = Vector2d<double>(p4);
        CHECK(v.x == Approx(7.6));
        CHECK(v.y == Approx(0.0));

        v = Vector2d<double>(p5);
        CHECK(v.x == Approx(-19.2));
        CHECK(v.y == Approx(0.0));

        v = Vector2d<double>(p6);
        CHECK(v.x == Approx(-12.6));
        CHECK(v.y == Approx(0.0));

        v = Vector2d<double>(p7);
        CHECK(v.x == Approx(18.9));
        CHECK(v.y == Approx(0.0));

        // Y axis
        v = Vector2d<double>(p8);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(5.1));

        v = Vector2d<double>(p9);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(-3.7));

        v = Vector2d<double>(p10);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(-42.8));

        v = Vector2d<double>(p11);
        CHECK(v.x == Approx(0.0));
        CHECK(v.y == Approx(55.01));

        // Arbitrary directions
        v = Vector2d<double>(p12);
        CHECK(v.x == Approx(6.929646));
        CHECK(v.y == Approx(-6.929646));

        v = Vector2d<double>(p13);
        CHECK(v.x == Approx(2.51142133));
        CHECK(v.y == Approx(-3.49038149));

        v = Vector2d<double>(p14);
        CHECK(v.x == Approx(135.24970542));
        CHECK(v.y == Approx(68.62569547));
    }

    SECTION("Conversion to Polar (modify by reference)")
    {
        Polar<double> p;

        // Zero magnitude
        v1.toPolar(p);
        CHECK(p.angle == Approx(0.0));
        CHECK(p.mag == Approx(0.0));

        // X axis
        v2.toPolar(p);
        CHECK(p.angle == Approx(0.0));
        CHECK(p.mag == Approx(146.0));

        v3.toPolar(p);
        CHECK(p.angle == Approx(3.14159265));
        CHECK(p.mag == Approx(1.39));

        // Y axis
        v4.toPolar(p);
        CHECK(p.angle == Approx(1.57079633));
        CHECK(p.mag == Approx(24.31));

        v5.toPolar(p);
        CHECK(p.angle == Approx(4.71238898));
        CHECK(p.mag == Approx(55.7));

        // Arbitrary directions
        v6.toPolar(p);
        CHECK(p.angle == Approx(5.49778714));
        CHECK(p.mag == Approx(7.58018469));

        v7.toPolar(p);
        CHECK(p.angle == Approx(2.17954130));
        CHECK(p.mag == Approx(22.33148674));

        v8.toPolar(p);
        CHECK(p.angle == Approx(3.17497388));
        CHECK(p.mag == Approx(71.91006119));
    }

    SECTION("Conversion to Polar (return by value)")
    {
        Polar<double> p;

        // Zero magnitude
        p = v1.toPolar();
        CHECK(p.angle == Approx(0.0));
        CHECK(p.mag == Approx(0.0));

        // X axis
        p = v2.toPolar();
        CHECK(p.angle == Approx(0.0));
        CHECK(p.mag == Approx(146.0));

        p = v3.toPolar();
        CHECK(p.angle == Approx(3.14159265));
        CHECK(p.mag == Approx(1.39));

        // Y axis
        p = v4.toPolar();
        CHECK(p.angle == Approx(1.57079633));
        CHECK(p.mag == Approx(24.31));

        p = v5.toPolar();
        CHECK(p.angle == Approx(4.71238898));
        CHECK(p.mag == Approx(55.7));

        // Arbitrary directions
        p = v6.toPolar();
        CHECK(p.angle == Approx(5.49778714));
        CHECK(p.mag == Approx(7.58018469));

        p = v7.toPolar();
        CHECK(p.angle == Approx(2.17954130));
        CHECK(p.mag == Approx(22.33148674));

        p = v8.toPolar();
        CHECK(p.angle == Approx(3.17497388));
        CHECK(p.mag == Approx(71.91006119));
    }
}

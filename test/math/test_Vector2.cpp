#include "../common.h"

using namespace ail::math;

TEST_CASE("Vector2d - construction and assignment", "[Vector2d]")
{
    SECTION("Default construction to 0")
    {
        Vector2d<int> vi;
        REQUIRE(vi.x == 0);
        REQUIRE(vi.y == 0);

        Vector2d<double> vd;
        REQUIRE(vd.x == 0.0);
        REQUIRE(vd.y == 0.0);
    }

    SECTION("Construction - integers")
    {
        Vector2d<int> v1(81, -4);
        REQUIRE(v1.x == 81);
        REQUIRE(v1.y == -4);

        Vector2d<int> v2(-33, 10);
        REQUIRE(v2.x == -33);
        REQUIRE(v2.y == 10);
    }

    SECTION("Construction - floating point")
    {
        Vector2d<double> v1(12.34, -56.78);
        REQUIRE(v1.x == Approx(12.34));
        REQUIRE(v1.y == Approx(-56.78));

        Vector2d<double> v2(-0.38, 0.45);
        REQUIRE(v2.x == Approx(-0.38));
        REQUIRE(v2.y == Approx(0.45));
    }

    SECTION("Uniform initialisation - integer")
    {
        Vector2d<int> v1 {81, -4};
        REQUIRE(v1.x == 81);
        REQUIRE(v1.y == -4);

        Vector2d<int> v2 {-33, 10};
        REQUIRE(v2.x == -33);
        REQUIRE(v2.y == 10);
    }

    SECTION("Uniform initialisation - floating point")
    {
        Vector2d<double> v1 {12.34, -56.78};
        REQUIRE(v1.x == Approx(12.34));
        REQUIRE(v1.y == Approx(-56.78));

        Vector2d<double> v2 {-0.38, 0.45};
        REQUIRE(v2.x == Approx(-0.38));
        REQUIRE(v2.y == Approx(0.45));
    }

    SECTION("Uniform initialisation - wrong size")
    {
        REQUIRE_THROWS(Vector2d<double> {1.25});
        REQUIRE_THROWS((Vector2d<double> {5.96, 4.67, 9.001}));
    }

    SECTION("Copy construction")
    {
        Vector2d<int> vi1(27, -1);
        Vector2d<int> vi2(vi1);
        REQUIRE(vi2.x == 27);
        REQUIRE(vi2.y == -1);

        Vector2d<double> vd1(34.21, 78.56);
        Vector2d<double> vd2(vd1);
        REQUIRE(vd2.x == 34.21);
        REQUIRE(vd2.y == 78.56);
    }

    SECTION("Copy assignment")
    {
        Vector2d<int> vi1(-44, 2);
        Vector2d<int> vi2;
        vi2 = vi1;
        REQUIRE(vi2.x == -44);
        REQUIRE(vi2.y == 2);

        Vector2d<double> vd1(43.21, 87.65);
        Vector2d<double> vd2;
        vd2 = vd1;
        REQUIRE(vd2.x == 43.21);
        REQUIRE(vd2.y == 87.65);
    }

    SECTION("set() modifier")
    {
        Vector2d<int> vi;
        Vector2d<double> vd;

        vi.set(132, 53);
        REQUIRE(vi.x == 132);
        REQUIRE(vi.y == 53);

        vd.set(5.13, -4.98);
        REQUIRE(vd.x == 5.13);
        REQUIRE(vd.y == -4.98);
    }
}

TEST_CASE("Vector2d - comparison operators", "[Vector2d]")
{
    Vector2d<int> vi1(22, -87);
    Vector2d<int> vi2(22, -87);
    Vector2d<int> vi3(66, 15);

    Vector2d<double> vd1(34.5, 23.4);
    Vector2d<double> vd2(34.5, 23.4);
    Vector2d<double> vd3(-12.3, 45.6);

    SECTION("Equality - integers")
    {
        REQUIRE(vi1 == vi1);
        REQUIRE(vi1 == vi2);
        REQUIRE(vi2 == vi1);
        REQUIRE_FALSE(vi1 == vi3);
        REQUIRE_FALSE(vi2 == vi3);
        REQUIRE_FALSE(vi3 == vi1);
        REQUIRE_FALSE(vi3 == vi2);
    }

    SECTION("Equality - floating point")
    {
        REQUIRE(vd1 == vd1);
        REQUIRE(vd1 == vd2);
        REQUIRE(vd2 == vd1);
        REQUIRE_FALSE(vd1 == vd3);
        REQUIRE_FALSE(vd2 == vd3);
        REQUIRE_FALSE(vd3 == vd1);
        REQUIRE_FALSE(vd3 == vd2);
    }

    SECTION("Inequality - integers")
    {
        REQUIRE_FALSE(vi1 != vi1);
        REQUIRE_FALSE(vi1 != vi2);
        REQUIRE_FALSE(vi2 != vi1);
        REQUIRE(vi1 != vi3);
        REQUIRE(vi2 != vi3);
        REQUIRE(vi3 != vi1);
        REQUIRE(vi3 != vi2);
    }

    SECTION("Inequality - floating point")
    {
        REQUIRE_FALSE(vi1 != vi1);
        REQUIRE_FALSE(vi1 != vi2);
        REQUIRE_FALSE(vi2 != vi1);
        REQUIRE(vi1 != vi3);
        REQUIRE(vi2 != vi3);
        REQUIRE(vi3 != vi1);
        REQUIRE(vi3 != vi2);
    }
}

TEST_CASE("Vector2d - basic arithmetic", "[Vector2d]")
{
    // TODO: split into integer and floating point test cases
    // TODO: move vector and scalar declarations out into common variables which are re-used throughout sections

    SECTION("Vector addition")
    {
        Vector2d<int> vi = Vector2d<int>(-4, 9) + Vector2d<int>(16, 13);
        REQUIRE(vi.x == 12);
        REQUIRE(vi.y == 22);

        Vector2d<double> vd = Vector2d<double>(1.2, 3.4) + Vector2d<double>(2.3, 4.5);
        REQUIRE(vd.x == Approx(3.5));
        REQUIRE(vd.y == Approx(7.9));
    }

    SECTION("Vector addition assignment")
    {
        Vector2d<int> vi(22, 1);
        vi += Vector2d<int>(1, -3);
        REQUIRE(vi.x == 23);
        REQUIRE(vi.y == -2);

        Vector2d<double> vd(2.3, 4.5);
        vd += Vector2d<double>(3.4, 5.6);
        REQUIRE(vd.x == Approx(5.7));
        REQUIRE(vd.y == Approx(10.1));
    }

    SECTION("Vector subtraction")
    {
        Vector2d<int> vi = Vector2d<int>(19, -8) - Vector2d<int>(20, -2);
        REQUIRE(vi.x == -1);
        REQUIRE(vi.y == -6);

        Vector2d<double> vd = Vector2d<double>(4.5, 3.2) - Vector2d<double>(3.1, 2.6);
        REQUIRE(vd.x == Approx(1.4));
        REQUIRE(vd.y == Approx(0.6));
    }

    SECTION("Vector subtraction assignment")
    {
        Vector2d<int> vi(44, 26);
        vi -= Vector2d<int>(37, 28);
        REQUIRE(vi.x == 7);
        REQUIRE(vi.y == -2);

        Vector2d<double> vd(6.3, 5.1);
        vd -= Vector2d<double>(5.2, 1.8);
        REQUIRE(vd.x == Approx(1.1));
        REQUIRE(vd.y == Approx(3.3));
    }

    SECTION("Scalar multiplication")
    {
        Vector2d<int> vi;
        Vector2d<double> vd;

        // Vector x scalar
        vi = Vector2d<int>(4, -1) * 5;
        REQUIRE(vi.x == 20);
        REQUIRE(vi.y == -5);

        vd = Vector2d<double>(8.4, 3.3) * 4.5;
        REQUIRE(vd.x == Approx(37.8));
        REQUIRE(vd.y == Approx(14.85));


        // Scalar x vector
        vi = 5 * Vector2d<int>(4, -1);
        REQUIRE(vi.x == 20);
        REQUIRE(vi.y == -5);

        vd = 4.5 * Vector2d<double>(8.4, 3.3);
        REQUIRE(vd.x == Approx(37.8));
        REQUIRE(vd.y == Approx(14.85));
    }

    SECTION("Scalar multiplication assignment")
    {
        Vector2d<int> vi(-6, 14);
        vi *= 7;
        REQUIRE(vi.x == -42);
        REQUIRE(vi.y == 98);

        Vector2d<double> vd(3.9, 9.6);
        vd *= 5.1;
        REQUIRE(vd.x == Approx(19.89));
        REQUIRE(vd.y == Approx(48.96));
    }

    SECTION("Scalar division")
    {
        Vector2d<int> vi;
        Vector2d<double> vd;

        // Vector divided by scalar
        vi = Vector2d<int>(12, 6) / 3;
        REQUIRE(vi.x == 4);
        REQUIRE(vi.y == 2);

        vd = Vector2d<double>(12.3, 6.7) / 2.2;
        REQUIRE(vd.x == Approx(5.59090909));
        REQUIRE(vd.y == Approx(3.04545455));

        // Scalar divided by vector
        vi = 50 / Vector2d<int>(10, 25);
        REQUIRE(vi.x == Approx(5));
        REQUIRE(vi.y == Approx(2));

        vd = 7.2 / Vector2d<double>(8.11, -16.4);
        REQUIRE(vd.x == Approx(0.887792));
        REQUIRE(vd.y == Approx(-0.439024));
    }

    SECTION("Scalar division assignment")
    {
        Vector2d<int> vi(10, 28);
        vi /= 2;
        REQUIRE(vi.x == 5);
        REQUIRE(vi.y == 14);

        Vector2d<double> vd(8.6, 10.7);
        vd /= 3.8;
        REQUIRE(vd.x == Approx(2.26315789));
        REQUIRE(vd.y == Approx(2.81578947));
    }

    SECTION("Combined arithmetic")
    {
        Vector2d<int> vi =
            Vector2d<int>(-3, 0)
            + Vector2d<int>(4, -1) * 5
            - Vector2d<int>(12, 21) / 3;
        REQUIRE(vi.x == 13);
        REQUIRE(vi.y == -12);

        Vector2d<double> vd =
            -156.8 / Vector2d<double>(2.1, -9.6) / 2.0
            + Vector2d<double>(-18.9, 22.1)
            - 8.8 * Vector2d<double>(12.4, 0.5);
        REQUIRE(vd.x == Approx(-165.35333333));
        REQUIRE(vd.y == Approx(25.86666667));
    }

    SECTION("Negation")
    {
        Vector2d<int> vi = -Vector2d<int>(-99, 47);
        REQUIRE(vi.x == 99);
        REQUIRE(vi.y == -47);

        Vector2d<double> vd = -Vector2d<double>(14.6, -8.2);
        REQUIRE(vd.x == -14.6);
        REQUIRE(vd.y == 8.2);
    }
}

TEST_CASE("Vector2d - length", "[Vector2d]")
{
    Vector2d<double> vd1(0.0, 0.0);
    Vector2d<double> vd2(-12.31, 0.0);
    Vector2d<double> vd3(0.0, 134.369);
    Vector2d<double> vd4(5.0, 10.0);
    Vector2d<double> vd5(-9.3, 4.7);
    Vector2d<double> vd6(2.005, -19.3);

    Vector2d<int> vi1(0, 0);
    Vector2d<int> vi2(3, 9);
    Vector2d<int> vi3(-7, 3);
    Vector2d<int> vi4(4, -4);
    Vector2d<int> vi5(153, 209);
    Vector2d<int> vi6(-391, -227);

    SECTION("Euclidean length")
    {
        REQUIRE(vd1.getLength() == Approx(0.0));
        REQUIRE(vd2.getLength() == Approx(12.31));
        REQUIRE(vd3.getLength() == Approx(134.369));
        REQUIRE(vd4.getLength() == Approx(11.180339887));
        REQUIRE(vd5.getLength() == Approx(10.42017274));
        REQUIRE(vd6.getLength() == Approx(19.40386624));
    }

    SECTION("Euclidean squared length")
    {
        REQUIRE(vd1.getSqLength() == Approx(0.0));
        REQUIRE(vd2.getSqLength() == Approx(151.5361));
        REQUIRE(vd3.getSqLength() == Approx(18055.028161));
        REQUIRE(vd4.getSqLength() == Approx(124.99999999));
        REQUIRE(vd5.getSqLength() == Approx(108.57999993));
        REQUIRE(vd6.getSqLength() == Approx(376.51002506));
    }

    SECTION("Cross-check: euclidean length vs. square length")
    {
        REQUIRE(vd1.getSqLength() == Approx(vd1.getLength() * vd1.getLength()));
        REQUIRE(vd2.getSqLength() == Approx(vd2.getLength() * vd2.getLength()));
        REQUIRE(vd3.getSqLength() == Approx(vd3.getLength() * vd3.getLength()));
        REQUIRE(vd4.getSqLength() == Approx(vd4.getLength() * vd4.getLength()));
        REQUIRE(vd5.getSqLength() == Approx(vd5.getLength() * vd5.getLength()));
        REQUIRE(vd6.getSqLength() == Approx(vd6.getLength() * vd6.getLength()));
    }

    SECTION("Rectilinear length - integer")
    {
        REQUIRE(vi1.getRectilinearLength() == 0);
        REQUIRE(vi2.getRectilinearLength() == 12);
        REQUIRE(vi3.getRectilinearLength() == 10);
        REQUIRE(vi4.getRectilinearLength() == 8);
        REQUIRE(vi5.getRectilinearLength() == 362);
        REQUIRE(vi6.getRectilinearLength() == 618);
    }

    SECTION("Rectilinear length - floating point")
    {
        REQUIRE(vd1.getRectilinearLength() == Approx(0.0));
        REQUIRE(vd2.getRectilinearLength() == Approx(12.31));
        REQUIRE(vd3.getRectilinearLength() == Approx(134.369));
        REQUIRE(vd4.getRectilinearLength() == Approx(15.0));
        REQUIRE(vd5.getRectilinearLength() == Approx(14.0));
        REQUIRE(vd6.getRectilinearLength() == Approx(21.305));
    }
}

TEST_CASE("Vector2d - dot product", "[Vector2d]")
{
    Vector2d<double> v1a(3.4, 9.2);
    Vector2d<double> v1b(9.2, -3.4); // right angles to v1
    Vector2d<double> v1c(-9.2, 3.4); // right angles to v1
    Vector2d<double> v2(8.6, 1.9);
    Vector2d<double> v3(-2.7, 0.1);

    Vector2d<double> v1aUnit = v1a.getNormalised();
    Vector2d<double> v1bUnit = v1b.getNormalised();
    Vector2d<double> v1cUnit = v1c.getNormalised();
    Vector2d<double> v2Unit = v2.getNormalised();
    Vector2d<double> v3Unit = v3.getNormalised();

    SECTION("Same vector")
    {
        REQUIRE(v1aUnit.dot(v1aUnit) == Approx(1.0));
        REQUIRE(v2Unit.dot(v2Unit) == Approx(1.0));
        REQUIRE(v3Unit.dot(v3Unit) == Approx(1.0));
    }

    SECTION("Acute angle")
    {
        REQUIRE(v1a.dot(v2) == Approx(46.72));              // not normalised
        REQUIRE(v1aUnit.dot(v2Unit) == Approx(0.54083950)); // normalised
    }

    SECTION("Right angle")
    {
        REQUIRE(v1aUnit.dot(v1bUnit) == Approx(0.0));
        REQUIRE(v1aUnit.dot(v1cUnit) == Approx(0.0));
    }

    SECTION("Obtuse angle")
    {
        REQUIRE(v1a.dot(v3) == Approx(-8.26));               // not normalised
        REQUIRE(v1aUnit.dot(v3Unit) == Approx(-0.31169589)); // normalised
    }

    SECTION("Reverse vector")
    {
        REQUIRE(v1aUnit.dot(-v1aUnit) == Approx(-1.0));
        REQUIRE(v2Unit.dot(-v2Unit) == Approx(-1.0));
        REQUIRE(v3Unit.dot(-v3Unit) == Approx(-1.0));
    }
}

TEST_CASE("Vector2d - projection")
{
    Vector2d<double> v1(0.0, 0.0);
    Vector2d<double> v2(4.69, 9.71);
    Vector2d<double> v3(-13.44, 21.8);
    Vector2d<double> v4(0.11, -12.6);

    SECTION("Scalar projection")
    {
        REQUIRE(v1.getScalarProjection(v2) == Approx(0.0));
        REQUIRE(v3.getScalarProjection(v1) == Approx(0.0));
        
        REQUIRE(v2.getScalarProjection(v3) == Approx(5.80414799));
        REQUIRE(v3.getScalarProjection(v4) == Approx(-21.91649816));
        REQUIRE(v4.getScalarProjection(v2) == Approx(-11.29800378));
    }

    SECTION("Vector projection")
    {
        Vector2d<double> v;

        v = v1.getVectorProjection(v2);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        v = v3.getVectorProjection(v1);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));
        
        v = v2.getVectorProjection(v3);
        REQUIRE(v.x == Approx(-3.04598437));
        REQUIRE(v.y == Approx(4.94065918));

        v = v3.getVectorProjection(v4);
        REQUIRE(v.x == Approx(-0.19132722));
        REQUIRE(v.y == Approx(21.91566302));

        v = v4.getVectorProjection(v2);
        REQUIRE(v.x == Approx(-4.91384749));
        REQUIRE(v.y == Approx(-10.17344544));
    }
}

TEST_CASE("Vector2d - normalisation", "[Vector2d]")
{
    SECTION("Normalisation")
    {
        Vector2d<double> v1, v2;

        v1.set(-43.2, 87.6);
        v2 = v1.getNormalised(); // copy
        v1.normalise();          // in-place
        REQUIRE(v1.x == Approx(-0.44229248));
        REQUIRE(v1.y == Approx(0.89687087));
        REQUIRE(v2.x == Approx(v1.x));
        REQUIRE(v2.y == Approx(v1.y));
        REQUIRE(v1.getLength() == Approx(1.0));

        v1.set(12.36, 55.9);
        v2 = v1.getNormalised(); // copy
        v1.normalise();          // in-place
        REQUIRE(v1.x == Approx(0.21589463));
        REQUIRE(v1.y == Approx(0.97641667));
        REQUIRE(v2.x == Approx(v1.x));
        REQUIRE(v2.y == Approx(v1.y));
        REQUIRE(v1.getLength() == Approx(1.0));
    }
}

TEST_CASE("Vector2d - tangents", "[Vector2d]")
{
    Vector2d<int> vi1(15, 26);
    Vector2d<int> vi1_l(-26, 15);
    Vector2d<int> vi1_r(26, -15);
    
    Vector2d<int> vi2(-19, 42);
    Vector2d<int> vi2_l(-42, -19);
    Vector2d<int> vi2_r(42, 19);

    Vector2d<double> vd1(0.339, -33.91);
    Vector2d<double> vd1_l(33.91, 0.339);
    Vector2d<double> vd1_r(-33.91, -0.339);

    Vector2d<double> vd2(-156.3, -64.002);
    Vector2d<double> vd2_l(64.002, -156.3);
    Vector2d<double> vd2_r(-64.002, 156.3);

    SECTION("Left - integer")
    {
        Vector2d<int> v;

        v = vi1.getLeftTangent();
        REQUIRE(v.x == vi1_l.x);
        REQUIRE(v.y == vi1_l.y);

        v = vi2.getLeftTangent();
        REQUIRE(v.x == vi2_l.x);
        REQUIRE(v.y == vi2_l.y);
    }

    SECTION("Left - floating point")
    {
        Vector2d<double> v;

        v = vd1.getLeftTangent();
        REQUIRE(v.x == Approx(vd1_l.x));
        REQUIRE(v.y == Approx(vd1_l.y));

        v = vd2.getLeftTangent();
        REQUIRE(v.x == Approx(vd2_l.x));
        REQUIRE(v.y == Approx(vd2_l.y));
    }

    SECTION("Right - integer")
    {
        Vector2d<int> v;

        v = vi1.getRightTangent();
        REQUIRE(v.x == vi1_r.x);
        REQUIRE(v.y == vi1_r.y);

        v = vi2.getRightTangent();
        REQUIRE(v.x == vi2_r.x);
        REQUIRE(v.y == vi2_r.y);
    }

    SECTION("Right - floating point")
    {
        Vector2d<double> v;

        v = vd1.getRightTangent();
        REQUIRE(v.x == Approx(vd1_r.x));
        REQUIRE(v.y == Approx(vd1_r.y));

        v = vd2.getRightTangent();
        REQUIRE(v.x == Approx(vd2_r.x));
        REQUIRE(v.y == Approx(vd2_r.y));
    }
}

TEST_CASE("Vector2d - distance", "[Vector2d]")
{
    Vector2d<double>
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
        REQUIRE(vd1.getDistance(vd1) == Approx(0.0));
        REQUIRE(vd2.getDistance(vd2) == Approx(0.0));
        // Axis-aligned
        REQUIRE(vd3.getDistance(vd4) == Approx(14.94));
        REQUIRE(vd5.getDistance(vd6) == Approx(10.22));
        REQUIRE(vd7.getDistance(vd8) == Approx(12.3));
        REQUIRE(vd9.getDistance(vd10) == Approx(5.409));
        // Arbitrary
        REQUIRE(vd11.getDistance(vd12) == Approx(20.705055));
        REQUIRE(vd13.getDistance(vd14) == Approx(124.342338));
    }

    SECTION("Euclidean squared distance")
    {
        // Zero distance
        REQUIRE(vd1.getSqDistance(vd1) == Approx(0.0));
        REQUIRE(vd2.getSqDistance(vd2) == Approx(0.0));
        // Axis-aligned
        REQUIRE(vd3.getSqDistance(vd4) == Approx(223.2036));
        REQUIRE(vd5.getSqDistance(vd6) == Approx(104.4484));
        REQUIRE(vd7.getSqDistance(vd8) == Approx(151.29));
        REQUIRE(vd9.getSqDistance(vd10) == Approx(29.257281));
        // Arbitrary
        REQUIRE(vd11.getSqDistance(vd12) == Approx(428.69930255));
        REQUIRE(vd13.getSqDistance(vd14) == Approx(15461.01701931));
    }

    SECTION("Rectilinear distance - integer")
    {
        // Zero distance
        REQUIRE(Vector2d<int>(0, 0).getRectilinearDistance(Vector2d<int>(0, 0)) == 0);
        REQUIRE(Vector2d<int>(-54, 1).getRectilinearDistance(Vector2d<int>(-54, 1)) == 0);
        // Axis-aligned
        REQUIRE(Vector2d<int>(5, 3).getRectilinearDistance(Vector2d<int>(9, 3)) == 4);
        REQUIRE(Vector2d<int>(-21, 0).getRectilinearDistance(Vector2d<int>(5, 0)) == 26);
        REQUIRE(Vector2d<int>(-4, 11).getRectilinearDistance(Vector2d<int>(-4, 19)) == 8);
        REQUIRE(Vector2d<int>(0, 7).getRectilinearDistance(Vector2d<int>(0, -8)) == 15);
        // Arbitrary
        REQUIRE(Vector2d<int>(15, 6).getRectilinearDistance(Vector2d<int>(3, 21)) == 27);
        REQUIRE(Vector2d<int>(-2, 46).getRectilinearDistance(Vector2d<int>(13, 63)) == 32);
    }

    SECTION("Rectilinear distance - floating point")
    {
        // Zero distance
        REQUIRE(vd1.getRectilinearDistance(vd1) == Approx(0.0));
        REQUIRE(vd2.getRectilinearDistance(vd2) == Approx(0.0));
        // Axis-aligned
        REQUIRE(vd3.getRectilinearDistance(vd4) == Approx(14.94));
        REQUIRE(vd5.getRectilinearDistance(vd6) == Approx(10.22));
        REQUIRE(vd7.getRectilinearDistance(vd8) == Approx(12.3));
        REQUIRE(vd9.getRectilinearDistance(vd10) == Approx(5.409));
        // Arbitrary
        REQUIRE(vd11.getRectilinearDistance(vd12) == Approx(26.896));
        REQUIRE(vd13.getRectilinearDistance(vd14) == Approx(171.729));
    }
}

TEST_CASE("Vector2d - proximity", "[Vector2d]")
{
    SECTION("Euclidean proximity")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        REQUIRE(Vector2d<double>(0.0, 0.0).isNear(Vector2d<double>(0.0, 0.0), 0.0));
        REQUIRE(Vector2d<double>(-5.39, 4.16).isNear(Vector2d<double>(-5.39, 4.16), 0.0));
        REQUIRE(Vector2d<double>(46.98, -18.6).isNear(Vector2d<double>(46.98, -18.6), 24.1));
        REQUIRE(Vector2d<double>(46.98, -18.6).isNear(Vector2d<double>(46.98, -18.6), -24.1));

        // In range - constrained to X axis
        REQUIRE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), 8.6));
        REQUIRE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), -8.6));
        REQUIRE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), 34.5));
        REQUIRE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), -34.5));
        // In range - constrained to Y axis
        REQUIRE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), 15.5));
        REQUIRE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), -15.5));
        REQUIRE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), 8.1));
        REQUIRE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), -8.1));
        // In range - no constraints
        REQUIRE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), 13.99));
        REQUIRE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), -13.99));
        REQUIRE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), 65.88));
        REQUIRE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), -65.88));

        // Boundary - constrained to X axis
        REQUIRE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), 3.88));
        REQUIRE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), -3.88));
        REQUIRE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), 19.85));
        REQUIRE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), -19.85));
        // Boundary - constrained to Y axis
        REQUIRE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), 12.33));
        REQUIRE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), -12.33));
        REQUIRE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), 4.96));
        REQUIRE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), -4.96));
        // Boundary - no constraints
        REQUIRE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), 5.57));
        REQUIRE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), -5.57));
        REQUIRE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), 49.42));
        REQUIRE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), -49.42));

        // Out of range - constrained to X axis
        REQUIRE_FALSE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), 1.48));
        REQUIRE_FALSE(Vector2d<double>(26.8, 0.0).isNear(Vector2d<double>(22.94, 0.0), -1.48));
        REQUIRE_FALSE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), 18.98));
        REQUIRE_FALSE(Vector2d<double>(-11.97, 0.0).isNear(Vector2d<double>(-31.8, 0.0), -18.98));
        // Out of range - constrained to Y axis
        REQUIRE_FALSE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), 7.6));
        REQUIRE_FALSE(Vector2d<double>(0.0, -9.7).isNear(Vector2d<double>(0.0, -22.01), -7.6));
        REQUIRE_FALSE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), 4.67));
        REQUIRE_FALSE(Vector2d<double>(0.0, 54.24).isNear(Vector2d<double>(0.0, 49.3), -4.67));
        // Out of range - no constraints
        REQUIRE_FALSE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), 1.901));
        REQUIRE_FALSE(Vector2d<double>(112.44, -33.92).isNear(Vector2d<double>(107.66, -31.101), -1.901));
        REQUIRE_FALSE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), 46.112));
        REQUIRE_FALSE(Vector2d<double>(-4.82, -411.13).isNear(Vector2d<double>(-5.04, -460.53), -46.112));
    }

    SECTION("Rectilinear proximity - integer")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        REQUIRE(Vector2d<int>(0, 0).isNearRectilinear(Vector2d<int>(0, 0), 0));
        REQUIRE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(12, -4), 0));
        REQUIRE(Vector2d<int>(-9, 25).isNearRectilinear(Vector2d<int>(-9, 25), 2));
        REQUIRE(Vector2d<int>(-9, 25).isNearRectilinear(Vector2d<int>(-9, 25), -2));

        // In range - constrained to X axis
        REQUIRE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), 4));
        REQUIRE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), -4));
        REQUIRE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), 14));
        REQUIRE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), -14));
        // In range - constrained to Y axis
        REQUIRE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), 10));
        REQUIRE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), -10));
        REQUIRE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), 9));
        REQUIRE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), -9));
        // In range - no constraints
        REQUIRE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), 23));
        REQUIRE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), -23));
        REQUIRE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), 11));
        REQUIRE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), -11));

        // Boundary - constrained to X axis
        REQUIRE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), 2));
        REQUIRE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), -2));
        REQUIRE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), 9));
        REQUIRE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), -9));
        // Boundary - constrained to Y axis
        REQUIRE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), 5));
        REQUIRE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), -5));
        REQUIRE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), 8));
        REQUIRE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), -8));
        // Boundary - no constraints
        REQUIRE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), 18));
        REQUIRE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), -18));
        REQUIRE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), 8));
        REQUIRE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), -8));

        // Out of range - constrained to X axis
        REQUIRE_FALSE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), 1));
        REQUIRE_FALSE(Vector2d<int>(20, 0).isNearRectilinear(Vector2d<int>(22, 0), -1));
        REQUIRE_FALSE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), 6));
        REQUIRE_FALSE(Vector2d<int>(3, 0).isNearRectilinear(Vector2d<int>(-6, 0), -6));
        // Out of range - constrained to Y axis
        REQUIRE_FALSE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), 2));
        REQUIRE_FALSE(Vector2d<int>(0, 43).isNearRectilinear(Vector2d<int>(0, 38), -2));
        REQUIRE_FALSE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), 5));
        REQUIRE_FALSE(Vector2d<int>(0, -4).isNearRectilinear(Vector2d<int>(0, -12), -5));
        // Out of range - no constraints
        REQUIRE_FALSE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), 15));
        REQUIRE_FALSE(Vector2d<int>(12, -4).isNearRectilinear(Vector2d<int>(3, 5), -15));
        REQUIRE_FALSE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), 3));
        REQUIRE_FALSE(Vector2d<int>(-1, 22).isNearRectilinear(Vector2d<int>(-6, 19), -3));
    }

    SECTION("Rectilinear proximity - floating point")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        REQUIRE(Vector2d<double>(0.0, 0.0).isNearRectilinear(Vector2d<double>(0.0, 0.0), 0.0));
        REQUIRE(Vector2d<double>(45.11, -20.9).isNearRectilinear(Vector2d<double>(45.11, -20.9), 0.0));
        REQUIRE(Vector2d<double>(-2.23, 0.6).isNearRectilinear(Vector2d<double>(-2.23, 0.6), 3.4));
        REQUIRE(Vector2d<double>(-2.23, 0.6).isNearRectilinear(Vector2d<double>(-2.23, 0.6), -3.4));

        // In range - constrained to X axis
        REQUIRE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), 8.2));
        REQUIRE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), -8.2));
        REQUIRE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), 10.13));
        REQUIRE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), -10.13));
        // In range - constrained to Y axis
        REQUIRE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), 6.69));
        REQUIRE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), -6.69));
        REQUIRE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), 14.26));
        REQUIRE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), -14.26));
        // In range - no constraints
        REQUIRE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), 2.5));
        REQUIRE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), -2.5));
        REQUIRE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), 167.76));
        REQUIRE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), -167.76));

        // Boundary - constrained to X axis
        REQUIRE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), 4.68));
        REQUIRE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), -4.68));
        REQUIRE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), 4.99));
        REQUIRE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), -4.99));
        // Boundary - constrained to Y axis
        REQUIRE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), 3.08));
        REQUIRE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), -3.08));
        REQUIRE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), 8.221));
        REQUIRE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), -8.221));
        // Boundary - no constraints
        REQUIRE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), 1.22));
        REQUIRE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), -1.22));
        REQUIRE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), 150.182));
        REQUIRE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), -150.182));

        // Out of range - constrained to X axis
        REQUIRE_FALSE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), 4.1));
        REQUIRE_FALSE(Vector2d<double>(4.46, 0.0).isNearRectilinear(Vector2d<double>(-0.2, 0.0), -4.1));
        REQUIRE_FALSE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), 3.08));
        REQUIRE_FALSE(Vector2d<double>(19.8, 0.0).isNearRectilinear(Vector2d<double>(24.77, 0.0), -3.08));
        // Out of range - constrained to Y axis
        REQUIRE_FALSE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), 2.4));
        REQUIRE_FALSE(Vector2d<double>(0.0, 7.16).isNearRectilinear(Vector2d<double>(0.0, 10.22), -2.4));
        REQUIRE_FALSE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), 7.93));
        REQUIRE_FALSE(Vector2d<double>(0.0, -5.501).isNearRectilinear(Vector2d<double>(0.0, 2.7), -7.93));
        // Out of range - no constraints
        REQUIRE_FALSE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), 0.44));
        REQUIRE_FALSE(Vector2d<double>(0.1, 0.2).isNearRectilinear(Vector2d<double>(0.5, -0.6), -0.44));
        REQUIRE_FALSE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), 146.39));
        REQUIRE_FALSE(Vector2d<double>(-59.312, 33.36).isNearRectilinear(Vector2d<double>(41.11, -16.38), -146.39));
    }

    SECTION("Approx equality - integer")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        REQUIRE(Vector2d<int>(0, 0).isApproxEqual(Vector2d<int>(0, 0), 0));
        REQUIRE(Vector2d<int>(14, -3).isApproxEqual(Vector2d<int>(14, -3), 0));
        REQUIRE(Vector2d<int>(-28, 11).isApproxEqual(Vector2d<int>(-28, 11), 5));
        REQUIRE(Vector2d<int>(-28, 11).isApproxEqual(Vector2d<int>(-28, 11), -5));

        // Both components in range.
        REQUIRE(Vector2d<int>(19, 11).isApproxEqual(Vector2d<int>(23, 10), 8));
        REQUIRE(Vector2d<int>(19, 11).isApproxEqual(Vector2d<int>(23, 10), -8));
        REQUIRE(Vector2d<int>(5, -63).isApproxEqual(Vector2d<int>(-28, -60), 41));
        REQUIRE(Vector2d<int>(5, -63).isApproxEqual(Vector2d<int>(-28, -60), -41));

        // One in range, one at boundary.
        REQUIRE(Vector2d<int>(-1, 2).isApproxEqual(Vector2d<int>(22, 10), 23));
        REQUIRE(Vector2d<int>(-1, 2).isApproxEqual(Vector2d<int>(22, 10), -23));
        REQUIRE(Vector2d<int>(67, 8).isApproxEqual(Vector2d<int>(61, -5), 13));
        REQUIRE(Vector2d<int>(67, 8).isApproxEqual(Vector2d<int>(61, -5), -13));

        // Both at boundary.
        REQUIRE(Vector2d<int>(51, 25).isApproxEqual(Vector2d<int>(58, 32), 7));
        REQUIRE(Vector2d<int>(51, 25).isApproxEqual(Vector2d<int>(58, 32), -7));
        REQUIRE(Vector2d<int>(-1, 9).isApproxEqual(Vector2d<int>(-5, 5), 4));
        REQUIRE(Vector2d<int>(-1, 9).isApproxEqual(Vector2d<int>(-5, 5), -4));

        // One out of range.
        REQUIRE_FALSE(Vector2d<int>(18, 55).isApproxEqual(Vector2d<int>(77, 48), 19));
        REQUIRE_FALSE(Vector2d<int>(18, 55).isApproxEqual(Vector2d<int>(77, 48), -19));
        REQUIRE_FALSE(Vector2d<int>(37, 21).isApproxEqual(Vector2d<int>(34, -8), 15));
        REQUIRE_FALSE(Vector2d<int>(37, 21).isApproxEqual(Vector2d<int>(34, -8), -15));

        // Both out of range.
        REQUIRE_FALSE(Vector2d<int>(-29, 15).isApproxEqual(Vector2d<int>(-4, 26), 8));
        REQUIRE_FALSE(Vector2d<int>(-29, 15).isApproxEqual(Vector2d<int>(-4, 26), -8));
        REQUIRE_FALSE(Vector2d<int>(76, 105).isApproxEqual(Vector2d<int>(2, -1), 51));
        REQUIRE_FALSE(Vector2d<int>(76, 105).isApproxEqual(Vector2d<int>(2, -1), -51));
    }

    SECTION("Approx equality - floating point")
    {
        // Note: The sign of the margin value should make no difference (negative is OK).

        // Exact match
        REQUIRE(Vector2d<double>(0.0, 0.0).isApproxEqual(Vector2d<double>(0.0, 0.0), 0.0));
        REQUIRE(Vector2d<double>(4.56, -1.98).isApproxEqual(Vector2d<double>(4.56, -1.98), 0.0));
        REQUIRE(Vector2d<double>(19.5, -20.01).isApproxEqual(Vector2d<double>(19.5, -20.01), 9.896));
        REQUIRE(Vector2d<double>(19.5, -20.01).isApproxEqual(Vector2d<double>(19.5, -20.01), -9.896));

        // Both components in range.
        REQUIRE(Vector2d<double>(0.2, -0.9).isApproxEqual(Vector2d<double>(0.5, -0.6), 1.2));
        REQUIRE(Vector2d<double>(0.2, -0.9).isApproxEqual(Vector2d<double>(0.5, -0.6), -1.2));
        REQUIRE(Vector2d<double>(23.99, 12.23).isApproxEqual(Vector2d<double>(-1.44, 15.5), 30.3));
        REQUIRE(Vector2d<double>(23.99, 12.23).isApproxEqual(Vector2d<double>(-1.44, 15.5), -30.3));

        // One in range, one at boundary.
        REQUIRE(Vector2d<double>(15.9, 20.1).isApproxEqual(Vector2d<double>(21.4, 19.66), 5.52));
        REQUIRE(Vector2d<double>(15.9, 20.1).isApproxEqual(Vector2d<double>(21.4, 19.66), -5.52));
        REQUIRE(Vector2d<double>(-1.4, -5.6).isApproxEqual(Vector2d<double>(-4.4, 3.8), 9.42));
        REQUIRE(Vector2d<double>(-1.4, -5.6).isApproxEqual(Vector2d<double>(-4.4, 3.8), -9.42));

        // Both at boundary.
        REQUIRE(Vector2d<double>(99.22, 26.51).isApproxEqual(Vector2d<double>(110.5, 37.79), 11.3));
        REQUIRE(Vector2d<double>(99.22, 26.51).isApproxEqual(Vector2d<double>(110.5, 37.79), -11.3));
        REQUIRE(Vector2d<double>(4.6, -12.11).isApproxEqual(Vector2d<double>(-1.23, -6.28), 5.85));
        REQUIRE(Vector2d<double>(4.6, -12.11).isApproxEqual(Vector2d<double>(-1.23, -6.28), -5.85));

        // One out of range.
        REQUIRE_FALSE(Vector2d<double>(-0.2, 10.88).isApproxEqual(Vector2d<double>(27.5, 12.47), 6.36));
        REQUIRE_FALSE(Vector2d<double>(-0.2, 10.88).isApproxEqual(Vector2d<double>(27.5, 12.47), -6.36));
        REQUIRE_FALSE(Vector2d<double>(8.1, -19.29).isApproxEqual(Vector2d<double>(1.07, -2.6), 11.8));
        REQUIRE_FALSE(Vector2d<double>(8.1, -19.29).isApproxEqual(Vector2d<double>(1.07, -2.6), -11.8));

        // Both out of range.
        REQUIRE_FALSE(Vector2d<double>(11.65, 4.591).isApproxEqual(Vector2d<double>(-24.1, 17.08), 3.402));
        REQUIRE_FALSE(Vector2d<double>(11.65, 4.591).isApproxEqual(Vector2d<double>(-24.1, 17.08), -3.402));
        REQUIRE_FALSE(Vector2d<double>(38.52, -1.603).isApproxEqual(Vector2d<double>(23.5, -16.2), 12.06));
        REQUIRE_FALSE(Vector2d<double>(38.52, -1.603).isApproxEqual(Vector2d<double>(23.5, -16.2), -12.06));
    }

}

TEST_CASE("Vector2d - polar conversions", "[Vector2d]")
{
    SECTION("Construction from Polar<>")
    {
        Vector2d<double> v;

        // Zero magnitude
        v = Vector2d<double>(Polar<double>(0.0, 0.0));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        v = Vector2d<double>(Polar<double>(5.9, 0.0));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        v = Vector2d<double>(Polar<double>(-19.3, 0.0));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        // X axis
        v = Vector2d<double>(Polar<double>(0.0, 7.6));
        REQUIRE(v.x == Approx(7.6));
        REQUIRE(v.y == Approx(0.0));

        v = Vector2d<double>(Polar<double>(0.0, -19.2));
        REQUIRE(v.x == Approx(-19.2));
        REQUIRE(v.y == Approx(0.0));

        v = Vector2d<double>(Polar<double>(3.14159265, 12.6));
        REQUIRE(v.x == Approx(-12.6));
        REQUIRE(v.y == Approx(0.0));

        v = Vector2d<double>(Polar<double>(-3.14159265, -18.9));
        REQUIRE(v.x == Approx(18.9));
        REQUIRE(v.y == Approx(0.0));

        // Y axis
        v = Vector2d<double>(Polar<double>(1.57079633, 5.1));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(5.1));

        v = Vector2d<double>(Polar<double>(1.57079633, -3.7));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(-3.7));

        v = Vector2d<double>(Polar<double>(4.71238898, 42.8));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(-42.8));

        v = Vector2d<double>(Polar<double>(-1.57079633, -55.01));
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(55.01));

        // Arbitrary directions
        v = Vector2d<double>(Polar<double>(-0.78539816, 9.8));
        REQUIRE(v.x == Approx(6.929646));
        REQUIRE(v.y == Approx(-6.929646));

        v = Vector2d<double>(Polar<double>(5.3361, 4.3));
        REQUIRE(v.x == Approx(2.51142133));
        REQUIRE(v.y == Approx(-3.49038149));

        v = Vector2d<double>(Polar<double>(9.894328, -151.664));
        REQUIRE(v.x == Approx(135.24970542));
        REQUIRE(v.y == Approx(68.62569547));
    }

    SECTION("Conversion to Polar<> (return by reference)")
    {
        Polar<double> p;

        // Zero magnitude
        Vector2d<double>(0.0, 0.0).toPolar(p);
        REQUIRE(p.angle == Approx(0.0));
        REQUIRE(p.mag == Approx(0.0));

        // X axis
        Vector2d<double>(146.0, 0.0).toPolar(p);
        REQUIRE(p.angle == Approx(0.0));
        REQUIRE(p.mag == Approx(146.0));

        Vector2d<double>(-1.39, 0.0).toPolar(p);
        REQUIRE(p.angle == Approx(3.14159265));
        REQUIRE(p.mag == Approx(1.39));

        // Y axis
        Vector2d<double>(0.0, 24.31).toPolar(p);
        REQUIRE(p.angle == Approx(1.57079633));
        REQUIRE(p.mag == Approx(24.31));

        Vector2d<double>(0.0, -55.7).toPolar(p);
        REQUIRE(p.angle == Approx(4.71238898));
        REQUIRE(p.mag == Approx(55.7));

        // Arbitrary directions
        Vector2d<double>(5.36, -5.36).toPolar(p);
        REQUIRE(p.angle == Approx(5.49778714));
        REQUIRE(p.mag == Approx(7.58018469));

        Vector2d<double>(-12.77, 18.32).toPolar(p);
        REQUIRE(p.angle == Approx(2.17954130));
        REQUIRE(p.mag == Approx(22.33148674));

        Vector2d<double>(-71.87, -2.4).toPolar(p);
        REQUIRE(p.angle == Approx(3.17497388));
        REQUIRE(p.mag == Approx(71.91006119));
    }

    SECTION("Conversion to Polar<> (return by value)")
    {
        Polar<double> p;

        // Zero magnitude
        p = Vector2d<double>(0.0, 0.0).toPolar();
        REQUIRE(p.angle == Approx(0.0));
        REQUIRE(p.mag == Approx(0.0));

        // X axis
        p = Vector2d<double>(146.0, 0.0).toPolar();
        REQUIRE(p.angle == Approx(0.0));
        REQUIRE(p.mag == Approx(146.0));

        p = Vector2d<double>(-1.39, 0.0).toPolar();
        REQUIRE(p.angle == Approx(3.14159265));
        REQUIRE(p.mag == Approx(1.39));

        // Y axis
        p = Vector2d<double>(0.0, 24.31).toPolar();
        REQUIRE(p.angle == Approx(1.57079633));
        REQUIRE(p.mag == Approx(24.31));

        p = Vector2d<double>(0.0, -55.7).toPolar();
        REQUIRE(p.angle == Approx(4.71238898));
        REQUIRE(p.mag == Approx(55.7));

        // Arbitrary directions
        p = Vector2d<double>(5.36, -5.36).toPolar();
        REQUIRE(p.angle == Approx(5.49778714));
        REQUIRE(p.mag == Approx(7.58018469));

        p = Vector2d<double>(-12.77, 18.32).toPolar();
        REQUIRE(p.angle == Approx(2.17954130));
        REQUIRE(p.mag == Approx(22.33148674));

        p = Vector2d<double>(-71.87, -2.4).toPolar();
        REQUIRE(p.angle == Approx(3.17497388));
        REQUIRE(p.mag == Approx(71.91006119));
    }
}

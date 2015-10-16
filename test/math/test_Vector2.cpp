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

    SECTION("Construction with whole numbers")
    {
        Vector2d<int> vi(81, -4);
        REQUIRE(vi.x == 81);
        REQUIRE(vi.y == -4);

        Vector2d<double> vd(12.0, 34.0);
        REQUIRE(vd.x == 12.0);
        REQUIRE(vd.y == 34.0);
    }

    SECTION("Construction with decimal fractions")
    {
        Vector2d<double> v1(12.34, 56.78);
        REQUIRE(v1.x == Approx(12.34));
        REQUIRE(v1.y == Approx(56.78));

        Vector2d<double> v2(-0.38, 0.45);
        REQUIRE(v2.x == Approx(-0.38));
        REQUIRE(v2.y == Approx(0.45));
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

    SECTION("Accessor")
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
    SECTION("Equality")
    {
        Vector2d<int> vi1(22, -87);
        Vector2d<int> vi2(22, -87);
        Vector2d<int> vi3(66, 15);

        REQUIRE(vi1 == vi1);
        REQUIRE(vi1 == vi2);
        REQUIRE(vi2 == vi1);
        REQUIRE_FALSE(vi1 == vi3);
        REQUIRE_FALSE(vi2 == vi3);
        REQUIRE_FALSE(vi3 == vi1);
        REQUIRE_FALSE(vi3 == vi2);

        Vector2d<double> vd1(34.5, 23.4);
        Vector2d<double> vd2(34.5, 23.4);
        Vector2d<double> vd3(-12.3, 45.6);
        
        REQUIRE(vd1 == vd1);
        REQUIRE(vd1 == vd2);
        REQUIRE(vd2 == vd1);
        REQUIRE_FALSE(vd1 == vd3);
        REQUIRE_FALSE(vd2 == vd3);
        REQUIRE_FALSE(vd3 == vd1);
        REQUIRE_FALSE(vd3 == vd2);
    }

    SECTION("Inequality")
    {
        Vector2d<int> vi1(22, -87);
        Vector2d<int> vi2(22, -87);
        Vector2d<int> vi3(66, 15);

        REQUIRE_FALSE(vi1 != vi1);
        REQUIRE_FALSE(vi1 != vi2);
        REQUIRE_FALSE(vi2 != vi1);
        REQUIRE(vi1 != vi3);
        REQUIRE(vi2 != vi3);
        REQUIRE(vi3 != vi1);
        REQUIRE(vi3 != vi2);

        Vector2d<double> vd1(34.5f, 23.4f);
        Vector2d<double> vd2(34.5f, 23.4f);
        Vector2d<double> vd3(12.3f, 45.6f);

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

TEST_CASE("Vector2d - general operations", "[Vector2d]")
{
    SECTION("Magnitude")
    {
        // Magnitude.
        REQUIRE(Vector2d<double>(-12.31, 0.0).getMagnitude() == Approx(12.31));
        REQUIRE(Vector2d<double>(0.0, 134.369).getMagnitude() == Approx(134.369));
        REQUIRE(Vector2d<double>(5.0, 10.0).getMagnitude() == Approx(11.180339887));
        REQUIRE(Vector2d<double>(-9.3, 4.7).getMagnitude() == Approx(10.42017274));
        REQUIRE(Vector2d<double>(2.005, -19.3).getMagnitude() == Approx(19.40386624));

        // Squared magnitude.
        REQUIRE(Vector2d<double>(54.3, 0.0).getSqMagnitude() == Approx(2948.49));
        REQUIRE(Vector2d<double>(0.0, -18.81).getSqMagnitude() == Approx(353.8161));
        REQUIRE(Vector2d<double>(4.0, 3.0).getSqMagnitude() == Approx(25.0));
        REQUIRE(Vector2d<double>(-22.09, 1.1).getSqMagnitude() == Approx(489.1781));
        REQUIRE(Vector2d<double>(8.4, -7.17).getSqMagnitude() == Approx(121.9689));

        // Cross-checking:
        Vector2d<double> v(42.99, -1.07);
        REQUIRE(v.getSqMagnitude() == Approx(v.getMagnitude() * v.getMagnitude()));
    }

    SECTION("Normalisation")
    {
        Vector2d<double> v1, v2;

        v1.set(-43.2, 87.6);
        v2 = v1.getNormalised();
        v1.normalise();
        REQUIRE(v1.x == Approx(-0.44229248));
        REQUIRE(v1.y == Approx(0.89687087));
        REQUIRE(v2.x == Approx(v1.x));
        REQUIRE(v2.y == Approx(v1.y));
        REQUIRE(v1.getMagnitude() == Approx(1.0));

        v1.set(12.36, 55.9);
        v2 = v1.getNormalised();
        v1.normalise();
        REQUIRE(v1.x == Approx(0.21589463));
        REQUIRE(v1.y == Approx(0.97641667));
        REQUIRE(v2.x == Approx(v1.x));
        REQUIRE(v2.y == Approx(v1.y));
        REQUIRE(v1.getMagnitude() == Approx(1.0));
    }

    SECTION("Dot product")
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
        
        // Same vector
        REQUIRE(v1aUnit.dot(v1aUnit) == Approx(1.0));
        // Acute angle
        REQUIRE(v1a.dot(v2) == Approx(46.72));              // not normalised
        REQUIRE(v1aUnit.dot(v2Unit) == Approx(0.54083950)); // normalised
        // Right angle
        REQUIRE(v1aUnit.dot(v1bUnit) == Approx(0.0));
        REQUIRE(v1aUnit.dot(v1cUnit) == Approx(0.0));
        // Obtuse angle
        REQUIRE(v1a.dot(v3) == Approx(-8.26));               // not normalised
        REQUIRE(v1aUnit.dot(v3Unit) == Approx(-0.31169589)); // normalised
        // Reverse vector
        REQUIRE(v1aUnit.dot(-v1aUnit) == Approx(-1.0));
    }

    SECTION("Tangent")
    {
        Vector2d<double> v, vl, vr;

        v.set(8.8, 1.9);
        vl = v.getLeftTangent();
        vr = v.getRightTangent();
        REQUIRE(vl.x == -1.9);
        REQUIRE(vl.y == 8.8);
        REQUIRE(vr.x == 1.9);
        REQUIRE(vr.y == -8.8);
        REQUIRE(v.getNormalised().dot(vl.getNormalised()) == Approx(0.0));
        REQUIRE(v.getNormalised().dot(vr.getNormalised()) == Approx(0.0));
        REQUIRE(vl.getNormalised().dot(vr.getNormalised()) == Approx(-1.0));


        v.set(-16.64, 0.28);
        vl = v.getLeftTangent();
        vr = v.getRightTangent();
        REQUIRE(vl.x == -0.28);
        REQUIRE(vl.y == -16.64);
        REQUIRE(vr.x == 0.28);
        REQUIRE(vr.y == 16.64);
        REQUIRE(v.getNormalised().dot(vl.getNormalised()) == Approx(0.0));
        REQUIRE(v.getNormalised().dot(vr.getNormalised()) == Approx(0.0));
        REQUIRE(vl.getNormalised().dot(vr.getNormalised()) == Approx(-1.0));
    }

    SECTION("Projection")
    {
        // TODO: add more tests here

        Vector2d<double> v1(4.0, 3.0);
        Vector2d<double> v2(2.0, 4.0);

        REQUIRE(v2.getScalarProjection(v1) == Approx(4.0));

        Vector2d<double> v3 = v2.getVectorProjection(v1);
        REQUIRE(v3.x == Approx(3.2));
        REQUIRE(v3.y == Approx(2.4));
    }

    SECTION("Distance")
    {
        // Actual distance
        // Axis-aligned
        REQUIRE(Vector2d<double>(10.0, 0.0).getDistance(Vector2d<double>(24.94, 0.0)) == Approx(14.94));
        REQUIRE(Vector2d<double>(6.0, 0.0).getDistance(Vector2d<double>(-4.22, 0.0)) == Approx(10.22));
        REQUIRE(Vector2d<double>(0.0, 1.5).getDistance(Vector2d<double>(0.0, 13.8)) == Approx(12.3));
        REQUIRE(Vector2d<double>(0.0, -22.8).getDistance(Vector2d<double>(0.0, -17.391)) == Approx(5.409));
        // Arbitrary
        REQUIRE(Vector2d<double>(5.136, 19.64).getDistance(Vector2d<double>(-14.1, 27.3)) == Approx(20.705055));
        REQUIRE(Vector2d<double>(-57.301, 2.88).getDistance(Vector2d<double>(9.648, -101.9)) == Approx(124.342338));

        // Squared distance
        // Axis-aligned
        REQUIRE(Vector2d<double>(10.0, 0.0).getSqDistance(Vector2d<double>(24.94, 0.0)) == Approx(223.2036));
        REQUIRE(Vector2d<double>(6.0, 0.0).getSqDistance(Vector2d<double>(-4.22, 0.0)) == Approx(104.4484));
        REQUIRE(Vector2d<double>(0.0, 1.5).getSqDistance(Vector2d<double>(0.0, 13.8)) == Approx(151.29));
        REQUIRE(Vector2d<double>(0.0, -22.8).getSqDistance(Vector2d<double>(0.0, -17.391)) == Approx(29.257281));
        // Arbitrary
        REQUIRE(Vector2d<double>(5.136, 19.64).getSqDistance(Vector2d<double>(-14.1, 27.3)) == Approx(428.69930255));
        REQUIRE(Vector2d<double>(-57.301, 2.88).getSqDistance(Vector2d<double>(9.648, -101.9)) == Approx(15461.01701931));
    }

    SECTION("Proximity")
    {
        // Exact match
        REQUIRE(Vector2d<double>(0.0, 0.0).isNear(Vector2d<double>(0.0, 0.0), 0.0));
        REQUIRE(Vector2d<double>(-5.39, 4.16).isNear(Vector2d<double>(-5.39, 4.16), 0.0));
        
        // TODO: implement
    }

    SECTION("Approx equality")
    {
        // TODO: implement
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
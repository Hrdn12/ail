#include "../common.h"

using namespace ail::math;

/*
NOTES:
The tests below deliberately only use floating point instantiations of Polar.
The class represents angles as radians so an integer specialisation would be
impractically inaccurate.
*/


TEST_CASE("Polar - construction and assignment", "[math::Polar]")
{
    SECTION("Default construction to 0")
    {
        Polar<double> p;
        REQUIRE(p.angle == 0.0);
        REQUIRE(p.mag == 0.0);
    }

    SECTION("Construction - initialisation parameters")
    {
        Polar<double> p1(2.796, 42.135);
        REQUIRE(p1.angle == Approx(2.796));
        REQUIRE(p1.mag == Approx(42.135));

        Polar<double> p2(-3.1126, -0.6);
        REQUIRE(p2.angle == Approx(-3.1126));
        REQUIRE(p2.mag == Approx(-0.6));
    }

    SECTION("Uniform initialisation")
    {
        Polar<double> p1 {4.101, -12.67};
        REQUIRE(p1.angle == Approx(4.101));
        REQUIRE(p1.mag == Approx(-12.67));

        Polar<double> p2 {-1.19, 5.92};
        REQUIRE(p2.angle == Approx(-1.19));
        REQUIRE(p2.mag == Approx(5.92));
    }

    SECTION("Uniform initialisation - wrong size")
    {
        REQUIRE_THROWS(Polar<double> {1.25});
        REQUIRE_THROWS((Polar<double> {5.96, 4.67, 9.001}));
    }

    SECTION("Copy construction")
    {
        Polar<double> p1(-0.29, 22.75);
        Polar<double> p2(p1);
        REQUIRE(p2.angle == Approx(-0.29));
        REQUIRE(p2.mag == Approx(22.75));
    }

    SECTION("Copy assignment")
    {
        Polar<double> p1(5.3, -4.16);
        Polar<double> p2;
        p2 = p1;
        REQUIRE(p2.angle == Approx(5.3));
        REQUIRE(p2.mag == Approx(-4.16));
    }

    SECTION("set() modifier")
    {
        Polar<double> p;
        p.set(2.8, 8.84);
        REQUIRE(p.angle == Approx(2.8));
        REQUIRE(p.mag == Approx(8.84));
    }
}

TEST_CASE("Polar - comparison operators", "[math::Polar]")
{
    Polar<double>
        p1(11.89, -4.2),
        p2(11.89, -4.2),
        p3(0.44, 6.6);

    SECTION("Equality")
    {
        REQUIRE(p1 == p1);
        REQUIRE(p1 == p2);
        REQUIRE(p2 == p1);
        REQUIRE_FALSE(p1 == p3);
        REQUIRE_FALSE(p3 == p1);
        REQUIRE_FALSE(p2 == p3);
        REQUIRE_FALSE(p3 == p2);
    }

    SECTION("Inequality")
    {
        REQUIRE_FALSE(p1 != p1);
        REQUIRE_FALSE(p1 != p2);
        REQUIRE_FALSE(p2 != p1);
        REQUIRE(p1 != p3);
        REQUIRE(p3 != p1);
        REQUIRE(p2 != p3);
        REQUIRE(p3 != p2);
    }
}

TEST_CASE("Polar - arithmetic", "[math::Polar]")
{
    Polar<double> p1(-0.97, 2.56), p2(7.93, 1.4);

    SECTION("Negation operator")
    {
        p1 = -p1;
        REQUIRE(p1.angle == Approx(-0.97));
        REQUIRE(p1.mag == Approx(-2.56));

        p2 = -p2;
        REQUIRE(p2.angle == Approx(7.93));
        REQUIRE(p2.mag == Approx(-1.4));
    }
}

TEST_CASE("Polar - simplification", "[math::Polar]")
{
    Polar<double>
        p1(1.44, 51.24),
        p2(-2.8, 4.63),
        p3(0.56, -19.77),
        p4(15.493, -11.434);

    SECTION("Simplify in place")
    {
        p1.simplify();
        REQUIRE(p1.angle == Approx(1.44));
        REQUIRE(p1.mag == Approx(51.24));

        p2.simplify();
        REQUIRE(p2.angle == Approx(3.48318531));
        REQUIRE(p2.mag == Approx(4.63));

        p3.simplify();
        REQUIRE(p3.angle == Approx(3.70159265));
        REQUIRE(p3.mag == Approx(19.77));

        p4.simplify();
        REQUIRE(p4.angle == Approx(6.06822204));
        REQUIRE(p4.mag == Approx(11.434));
    }

    SECTION("Simplified copy")
    {
        Polar<double> p;

        p = p1.getSimplified();
        REQUIRE(p.angle == Approx(1.44));
        REQUIRE(p.mag == Approx(51.24));

        p = p2.getSimplified();
        REQUIRE(p.angle == Approx(3.48318531));
        REQUIRE(p.mag == Approx(4.63));

        p = p3.getSimplified();
        REQUIRE(p.angle == Approx(3.70159265));
        REQUIRE(p.mag == Approx(19.77));

        p = p4.getSimplified();
        REQUIRE(p.angle == Approx(6.06822204));
        REQUIRE(p.mag == Approx(11.434));
    }
}

TEST_CASE("Polar - proximity", "[math::Polar]")
{
    Polar<double>
        p1a(0.0, 0.0), p1b(1.469, 0.0), p1c(-8.29, 0.0),
        p2a(2.14, 14.6), p2b(8.42318531, 14.6), p2c(-4.14318531, 14.6), p2d(5.28159265, -14.6), p2e(-1.00159266, -14.6),
        p3a(-4.65, 10.99), p3b(-5.22, 10.99), p3c(-4.14, 10.99), p3d(-4.31, 9.5),
        p4a(1.91, 4.8), p4b(1.91, 4.6), p4c(1.91, 5.9), p4d(2.15, 5.3);

    SECTION("isNear")
    {
        // Exactly equal
        REQUIRE(p1a.isNear(p1a, 0.0));
        REQUIRE(p3b.isNear(p3b, 0.1));

        // Zero magnitude means angle doesn't matter.
        REQUIRE(p1a.isNear(p1b, 0.0));
        REQUIRE(p1a.isNear(p1c, 0.0));
        REQUIRE(p1b.isNear(p1c, 0.0));
        REQUIRE(p1a.isNear(p4a, 4.81));
        REQUIRE_FALSE(p1a.isNear(p4a, 4.79));

        // Equivalent angle.
        REQUIRE(p2a.isNear(p2b, 0.01));
        REQUIRE(p2a.isNear(p2c, 0.01));

        // Negated angle/magnitude.
        REQUIRE(p2a.isNear(p2d, 0.01));
        REQUIRE(p2a.isNear(p2e, 0.01));

        // Same magnitude, different angle.
        REQUIRE(p3a.isNear(p3b, 6.8));
        REQUIRE_FALSE(p3a.isNear(p3b, 5.1));
        REQUIRE(p3a.isNear(p3c, 5.88));
        REQUIRE_FALSE(p3a.isNear(p3c, 4.9));

        // Same angle, different magnitude.
        REQUIRE(p4a.isNear(p4b, 0.21));
        REQUIRE_FALSE(p4a.isNear(p4b, 0.19));
        REQUIRE(p4a.isNear(p4c, 1.11));
        REQUIRE_FALSE(p4a.isNear(p4c, 0.93));

        // Different angle/magnitude.
        REQUIRE(p3a.isNear(p3d, 4.61));
        REQUIRE_FALSE(p3a.isNear(p3d, 3.24));
        REQUIRE(p4a.isNear(p4d, 3.3));
        REQUIRE_FALSE(p4a.isNear(p4d, 1.11));
    }
}

TEST_CASE("Polar - approximate equality", "[math::Polar]")
{
    Polar<double>
        p1(0.0, 0.0),
        p2(1.42, 0.95),
        p3(1.51, 4.301),
        p4(4.003, 1.24),
        p5(-2.69, 12.5),
        p6(-3.8, 11.6);

    // Note: The sign of the margin doesn't matter. Test with both.

    SECTION("Same margin")
    {
        // Exactly equal.
        REQUIRE(p1.isApproxEqual(p1, 0.0));
        REQUIRE(p2.isApproxEqual(p2, 0.1));

        // Comfortably within margin.
        REQUIRE(p1.isApproxEqual(p2, 1.84));
        REQUIRE(p2.isApproxEqual(p3, 5.4));
        REQUIRE(p3.isApproxEqual(p4, 4.6));
        REQUIRE(p4.isApproxEqual(p5, 19.701));
        REQUIRE(p5.isApproxEqual(p6, 2.5));

        // Just inside margin.
        REQUIRE(p1.isApproxEqual(p2, 1.43));
        REQUIRE(p2.isApproxEqual(p3, 3.36));
        REQUIRE(p3.isApproxEqual(p4, 3.07));
        REQUIRE(p4.isApproxEqual(p5, 11.27));
        REQUIRE(p5.isApproxEqual(p6, 1.12));

        // Just outside margin.
        REQUIRE_FALSE(p1.isApproxEqual(p2, 1.41));
        REQUIRE_FALSE(p2.isApproxEqual(p3, 3.34));
        REQUIRE_FALSE(p3.isApproxEqual(p4, 3.05));
        REQUIRE_FALSE(p4.isApproxEqual(p5, 11.25));
        REQUIRE_FALSE(p5.isApproxEqual(p6, 1.1));

        // Comfortably outside margin.
        REQUIRE_FALSE(p1.isApproxEqual(p2, 0.853));
        REQUIRE_FALSE(p2.isApproxEqual(p3, 2.4));
        REQUIRE_FALSE(p3.isApproxEqual(p4, 2.33));
        REQUIRE_FALSE(p4.isApproxEqual(p5, 9.66));
        REQUIRE_FALSE(p5.isApproxEqual(p6, 0.55));

        // Negative margin should work the same as positive.
        REQUIRE(p2.isApproxEqual(p3, -5.4));
        REQUIRE(p2.isApproxEqual(p3, -3.36));
        REQUIRE_FALSE(p2.isApproxEqual(p3, -3.34));
        REQUIRE_FALSE(p2.isApproxEqual(p3, -2.4));
    }

    SECTION("Different margins")
    {
        // Exactly equal.
        REQUIRE(p1.isApproxEqual(p1, 0.0, 0.0));
        REQUIRE(p2.isApproxEqual(p2, 0.05, 0.1));

        // Comfortably within margin.
        REQUIRE(p1.isApproxEqual(p2, 2.19, 1.454));
        REQUIRE(p2.isApproxEqual(p3, 0.93, 6.22));
        REQUIRE(p3.isApproxEqual(p4, 3.6, 4.9));
        REQUIRE(p4.isApproxEqual(p5, 8.3, 13.17));
        REQUIRE(p5.isApproxEqual(p6, 2.5, 2.2));

        // Just inside margin.
        REQUIRE(p1.isApproxEqual(p2, 1.43, 0.96));
        REQUIRE(p2.isApproxEqual(p3, 0.1, 3.361));
        REQUIRE(p3.isApproxEqual(p4, 2.503, 3.071));
        REQUIRE(p4.isApproxEqual(p5, 6.703, 11.27));
        REQUIRE(p5.isApproxEqual(p6, 1.12, 0.91));

        // Just outside margin.
        REQUIRE_FALSE(p1.isApproxEqual(p2, 1.41, 0.94));
        REQUIRE_FALSE(p2.isApproxEqual(p3, 0.08, 3.277));
        REQUIRE_FALSE(p3.isApproxEqual(p4, 2.483, 3.051));
        REQUIRE_FALSE(p4.isApproxEqual(p5, 3.683, 11.25));
        REQUIRE_FALSE(p5.isApproxEqual(p6, 1.1, 0.89));

        // Comfortably outside margin.
        REQUIRE_FALSE(p1.isApproxEqual(p2, 0.98, 0.46));
        REQUIRE_FALSE(p2.isApproxEqual(p3, 0.02, 1.108));
        REQUIRE_FALSE(p3.isApproxEqual(p4, 2.13, 1.76));
        REQUIRE_FALSE(p4.isApproxEqual(p5, 3.19, 9.811));
        REQUIRE_FALSE(p5.isApproxEqual(p6, 0.87, 0.46));

        // Negative margin should work the same as positive.
        REQUIRE(p2.isApproxEqual(p3, -0.93, -6.22));
        REQUIRE(p2.isApproxEqual(p3, -0.1, -3.361));
        REQUIRE_FALSE(p2.isApproxEqual(p3, -0.08, -3.277));
        REQUIRE_FALSE(p2.isApproxEqual(p3, -0.02, -1.108));
    }
}

TEST_CASE("Polar - Vector2d conversions", "[math::Polar]")
{
    const Vector2d<double>
        v1(0.0, 0.0),
        v2(146.0, 0.0),  v3(-1.39, 0.0),
        v4(0.0, 24.31),  v5(0.0, -55.7),
        v6(5.36, -5.36), v7(-12.77, 18.32), v8(-71.87, -2.4);

    const Polar<double>
        p1(0.0, 0.0),          p2(5.9, 0.0),         p3(-19.3, 0.0),
        p4(0.0, 7.6),          p5(0.0, -19.2),       p6(3.14159265, 12.6),    p7(-3.14159265, -18.9),
        p8(1.57079633, 5.1),   p9(1.57079633, -3.7), p10(4.71238898, 42.8),   p11(-1.57079633, -55.01),
        p12(-0.78539816, 9.8), p13(5.3361, 4.3),     p14(9.894328, -151.664);

    SECTION("Construction from Vector2d")
    {
        Polar<double> p;

        // Zero magnitude
        p = Polar<double>(v1);
        REQUIRE(p.angle == Approx(0.0));
        REQUIRE(p.mag == Approx(0.0));

        // X axis
        p = Polar<double>(v2);
        REQUIRE(p.angle == Approx(0.0));
        REQUIRE(p.mag == Approx(146.0));

        p = Polar<double>(v3);
        REQUIRE(p.angle == Approx(3.14159265));
        REQUIRE(p.mag == Approx(1.39));

        // Y axis
        p = Polar<double>(v4);
        REQUIRE(p.angle == Approx(1.57079633));
        REQUIRE(p.mag == Approx(24.31));

        p = Polar<double>(v5);
        REQUIRE(p.angle == Approx(4.71238898));
        REQUIRE(p.mag == Approx(55.7));

        // Arbitrary directions
        p = Polar<double>(v6);
        REQUIRE(p.angle == Approx(5.49778714));
        REQUIRE(p.mag == Approx(7.58018469));

        p = Polar<double>(v7);
        REQUIRE(p.angle == Approx(2.17954130));
        REQUIRE(p.mag == Approx(22.33148674));

        p = Polar<double>(v8);
        REQUIRE(p.angle == Approx(3.17497388));
        REQUIRE(p.mag == Approx(71.91006119));
    }

    SECTION("Conversion to Vector2d (modify by reference)")
    {
        Vector2d<double> v;

        // Zero magnitude
        p1.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        p2.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        p3.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        // X axis
        p4.toVector2d(v);
        REQUIRE(v.x == Approx(7.6));
        REQUIRE(v.y == Approx(0.0));

        p5.toVector2d(v);
        REQUIRE(v.x == Approx(-19.2));
        REQUIRE(v.y == Approx(0.0));

        p6.toVector2d(v);
        REQUIRE(v.x == Approx(-12.6));
        REQUIRE(v.y == Approx(0.0));

        p7.toVector2d(v);
        REQUIRE(v.x == Approx(18.9));
        REQUIRE(v.y == Approx(0.0));

        // Y axis
        p8.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(5.1));

        p9.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(-3.7));

        p10.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(-42.8));

        p11.toVector2d(v);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(55.01));

        // Arbitrary directions
        p12.toVector2d(v);
        REQUIRE(v.x == Approx(6.929646));
        REQUIRE(v.y == Approx(-6.929646));

        p13.toVector2d(v);
        REQUIRE(v.x == Approx(2.51142133));
        REQUIRE(v.y == Approx(-3.49038149));

        p14.toVector2d(v);
        REQUIRE(v.x == Approx(135.24970542));
        REQUIRE(v.y == Approx(68.62569547));
    }

    SECTION("Conversion to Vector2d (return by value)")
    {
        Vector2d<double> v;

        // Zero magnitude
        v = p1.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        v = p2.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        v = p3.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(0.0));

        // X axis
        v = p4.toVector2d();
        REQUIRE(v.x == Approx(7.6));
        REQUIRE(v.y == Approx(0.0));

        v = p5.toVector2d();
        REQUIRE(v.x == Approx(-19.2));
        REQUIRE(v.y == Approx(0.0));

        v = p6.toVector2d();
        REQUIRE(v.x == Approx(-12.6));
        REQUIRE(v.y == Approx(0.0));

        v = p7.toVector2d();
        REQUIRE(v.x == Approx(18.9));
        REQUIRE(v.y == Approx(0.0));

        // Y axis
        v = p8.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(5.1));

        v = p9.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(-3.7));

        v = p10.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(-42.8));

        v = p11.toVector2d();
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(55.01));

        // Arbitrary directions
        v = p12.toVector2d();
        REQUIRE(v.x == Approx(6.929646));
        REQUIRE(v.y == Approx(-6.929646));

        v = p13.toVector2d();
        REQUIRE(v.x == Approx(2.51142133));
        REQUIRE(v.y == Approx(-3.49038149));

        v = p14.toVector2d();
        REQUIRE(v.x == Approx(135.24970542));
        REQUIRE(v.y == Approx(68.62569547));
    }
}

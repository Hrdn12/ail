#include "common.h"

using avidmath::Vector2d;

TEST_CASE("Vector2d - construction and assignment", "[Vector2d]")
{
    SECTION("Default construction to 0")
    {
        Vector2d<double> v;
        REQUIRE(v.x == 0.0);
        REQUIRE(v.y == 0.0);
    }

    SECTION("Construction with whole numbers")
    {
        Vector2d<double> v(12.0, 34.0);
        REQUIRE(v.x == 12.0);
        REQUIRE(v.y == 34.0);
    }

    SECTION("Construction with decimal fractions")
    {
        Vector2d<double> v(12.34, 56.78);
        REQUIRE(v.x == Approx(12.34));
        REQUIRE(v.y == Approx(56.78));
    }

    SECTION("Copy construction")
    {
        Vector2d<double> v1(34.21, 78.56);
        Vector2d<double> v2(v1);
        REQUIRE(v2.x == Approx(34.21));
        REQUIRE(v2.y == Approx(78.56));
    }

    SECTION("Copy assignment")
    {
        Vector2d<double> v1(43.21, 87.65);
        Vector2d<double> v2;
        v2 = v1;
        REQUIRE(v2.x == Approx(43.21));
        REQUIRE(v2.y == Approx(87.65));
    }

    SECTION("Accessor")
    {
        Vector2d<double> v;
        v.set(1.23, 7.89);
        REQUIRE(v.x == Approx(1.23));
        REQUIRE(v.y == Approx(7.89));
    }
}

TEST_CASE("Vector2d - comparison operators", "[Vector2d]")
{
    SECTION("Equality")
    {
        Vector2d<double> v1(34.5f, 23.4f);
        Vector2d<double> v2(34.5f, 23.4f);
        Vector2d<double> v3(12.3f, 45.6f);
        
        REQUIRE(v1 == v2);
        REQUIRE_FALSE(v1 == v3);
    }

    SECTION("Inequality")
    {
        Vector2d<double> v1(34.5f, 23.4f);
        Vector2d<double> v2(34.5f, 23.4f);
        Vector2d<double> v3(12.3f, 45.6f);

        REQUIRE_FALSE(v1 != v2);
        REQUIRE(v1 != v3);
    }
}

TEST_CASE("Vector2d - basic arithmetic", "[Vector2d]")
{
    SECTION("Vector addition")
    {
        Vector2d<double> v = Vector2d<double>(1.2, 3.4) + Vector2d<double>(2.3, 4.5);
        REQUIRE(v.x == Approx(3.5));
        REQUIRE(v.y == Approx(7.9));
    }

    SECTION("Vector addition assignment")
    {
        Vector2d<double> v(2.3, 4.5);
        v += Vector2d<double>(3.4, 5.6);
        REQUIRE(v.x == Approx(5.7));
        REQUIRE(v.y == Approx(10.1));
    }

    SECTION("Vector subtraction")
    {
        Vector2d<double> v = Vector2d<double>(4.5, 3.2) - Vector2d<double>(3.1, 2.6);
        REQUIRE(v.x == Approx(1.4));
        REQUIRE(v.y == Approx(0.6));
    }

    SECTION("Vector subtraction assignment")
    {
        Vector2d<double> v(6.3, 5.1);
        v -= Vector2d<double>(5.2, 1.8);
        REQUIRE(v.x == Approx(1.1));
        REQUIRE(v.y == Approx(3.3));
    }

    SECTION("Scalar multiplication")
    {
        Vector2d<double> v1 = Vector2d<double>(8.4, 3.3) * 4.5;
        // Check the we got the right answer
        REQUIRE(v1.x == Approx(37.8));
        REQUIRE(v1.y == Approx(14.85));
        // Check that it works the other way round too.
        Vector2d<double> v2 = 4.5 * Vector2d<double>(8.4, 3.3);
        REQUIRE(v1.x == Approx(v2.x));
        REQUIRE(v1.y == Approx(v2.y));
    }

    SECTION("Scalar multiplication assignment")
    {
        Vector2d<double> v = Vector2d<double>(3.9, 9.6);
        v *= 5.1;
        REQUIRE(v.x == Approx(19.89));
        REQUIRE(v.y == Approx(48.96));
    }

    SECTION("Scalar division")
    {
        Vector2d<double> v1 = Vector2d<double>(12.3, 6.7) / 2.2;
        // Check the we got the right answer
        REQUIRE(v1.x == Approx(5.59090909));
        REQUIRE(v1.y == Approx(3.04545455));
        // Check that the inverse works
        Vector2d<double> v2 = 2.2 / Vector2d<double>(12.3, 6.7);
        REQUIRE(v1.x == Approx(1.0 / v2.x));
        REQUIRE(v1.y == Approx(1.0 / v2.y));
    }

    SECTION("Scalar division assignment")
    {
        Vector2d<double> v = Vector2d<double>(8.6, 10.7);
        v /= 3.8;
        REQUIRE(v.x == Approx(2.26315789));
        REQUIRE(v.y == Approx(2.81578947));
    }

    SECTION("Negation")
    {
        Vector2d<double> v = -Vector2d<double>(14.6, -8.2);
        REQUIRE(v.x == -14.6);
        REQUIRE(v.y == 8.2);
    }
}

TEST_CASE("Vector2d - operations", "[Vector2d]")
{
    SECTION("Magnitude")
    {
        Vector2d<double> v(5.0, 10.0);
        REQUIRE(v.getMagnitude() == Approx(11.180339887));
    }

    SECTION("Squared magnitude")
    {
        Vector2d<double> v(4.0, 3.0);
        REQUIRE(v.getSqMagnitude() == Approx(25.0));
    }

    SECTION("Normalise in place")
    {
        Vector2d<double> v(-43.2, 87.6);
        v.normalise();
        REQUIRE(v.x == Approx(-0.44229248));
        REQUIRE(v.y == Approx(0.89687087));
    }

    SECTION("Normalised copy")
    {
        Vector2d<double> v1(87.6, -43.2);
        Vector2d<double> v2 = v1.getNormalised();
        REQUIRE(v2.x == Approx(0.89687087));
        REQUIRE(v2.y == Approx(-0.44229248));
    }

    SECTION("Dot product")
    {
        Vector2d<double> v1a(3.4, 9.2);
        Vector2d<double> v1b(9.2, -3.4); // right angles to v1
        Vector2d<double> v1c(-9.2, 3.4); // right angles to v1
        Vector2d<double> v2(8.6, 1.9);

        Vector2d<double> v1aUnit = v1a.getNormalised();
        Vector2d<double> v1bUnit = v1b.getNormalised();
        Vector2d<double> v1cUnit = v1c.getNormalised();
        Vector2d<double> v2Unit = v2.getNormalised();

        // Arbitrary vectors.
        REQUIRE(v1a.dot(v2) == Approx(46.72)); // not normalised
        REQUIRE(v1aUnit.dot(v2Unit) == Approx(0.54084)); // normalised
        // Same vector
        REQUIRE(v1aUnit.dot(v1aUnit) == Approx(1.0));
        // Right angles
        REQUIRE(v1aUnit.dot(v1bUnit) == Approx(0.0));
        REQUIRE(v1aUnit.dot(v1cUnit) == Approx(0.0));
        // Reverse vector
        REQUIRE(v1aUnit.dot(-v1aUnit) == Approx(-1.0));
    }

    SECTION("Right tangent")
    {
        Vector2d<double> v1(8.8, 1.9);
        Vector2d<double> v2 = v1.getRightTangent();
        REQUIRE(v1.dot(v2) == Approx(0.0));
    }

    SECTION("Left tangent")
    {
        Vector2d<double> v1(3.7, 2.4);
        Vector2d<double> v2 = v1.getLeftTangent();
        REQUIRE(v1.dot(v2) == Approx(0.0));
    }

    SECTION("Projection")
    {
        Vector2d<double> v1(4.0, 3.0);
        Vector2d<double> v2(2.0, 4.0);

        REQUIRE(v2.getScalarProjection(v1) == Approx(4.0));

        Vector2d<double> v3 = v2.getVectorProjection(v1);
        REQUIRE(v3.x == Approx(3.2));
        REQUIRE(v3.y == Approx(2.4));
    }
}

TEST_CASE("Vector2d - conversions", "[Vector2d]")
{
    // TODO: construct from Polar
    // TODO: convert to polar (reference and value)
}
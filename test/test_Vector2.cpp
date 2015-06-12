#include "catch.hpp"

#include "../inc/Vector2.h"

using avidmath::Vector2;

TEST_CASE("Vector2 - construction and assignment", "[Vector2]")
{
    SECTION("Default construction to 0")
    {
        Vector2<double> v;
        CHECK(v.x == 0.0);
        CHECK(v.y == 0.0);
    }

    SECTION("Construction with whole numbers")
    {
        Vector2<double> v(12.0, 34.0);
        CHECK(v.x == 12.0);
        CHECK(v.y == 34.0);
    }

    SECTION("Construction with decimal fractions")
    {
        Vector2<double> v(12.34, 56.78);
        CHECK(v.x == Approx(12.34));
        CHECK(v.y == Approx(56.78));
    }

    SECTION("Copy construction")
    {
        Vector2<double> v1(34.21, 78.56);
        Vector2<double> v2(v1);
        CHECK(v2.x == Approx(34.21));
        CHECK(v2.y == Approx(78.56));
    }

    SECTION("Copy assignment")
    {
        Vector2<double> v1(43.21, 87.65);
        Vector2<double> v2;
        v2 = v1;
        CHECK(v2.x == Approx(43.21));
        CHECK(v2.y == Approx(87.65));
    }

    SECTION("Accessor")
    {
        Vector2<double> v;
        v.set(1.23, 7.89);
        CHECK(v.x == Approx(1.23));
        CHECK(v.y == Approx(7.89));
    }
}

TEST_CASE("Equality", "[Vector2]")
{
    // TODO: Equality / inequality
}

TEST_CASE("Vector2 - basic arithmetic", "[Vector2]")
{
    SECTION("Vector addition")
    {
        Vector2<double> v = Vector2<double>(1.2, 3.4) + Vector2<double>(2.3, 4.5);
        CHECK(v.x == Approx(3.5));
        CHECK(v.y == Approx(7.9));
    }

    SECTION("Vector addition assignment")
    {
        Vector2<double> v(2.3, 4.5);
        v += Vector2<double>(3.4, 5.6);
        CHECK(v.x == Approx(5.7));
        CHECK(v.y == Approx(10.1));
    }

    SECTION("Vector subtraction")
    {
        Vector2<double> v = Vector2<double>(4.5, 3.2) - Vector2<double>(3.1, 2.6);
        CHECK(v.x == Approx(1.4));
        CHECK(v.y == Approx(0.6));
    }

    SECTION("Vector subtraction assignment")
    {
        Vector2<double> v(6.3, 5.1);
        v -= Vector2<double>(5.2, 1.8);
        CHECK(v.x == Approx(1.1));
        CHECK(v.y == Approx(3.3));
    }

    SECTION("Scalar multiplication")
    {
        Vector2<double> v1 = Vector2<double>(8.4, 3.3) * 4.5;
        // Check the we got the right answer
        CHECK(v1.x == Approx(37.8));
        CHECK(v1.y == Approx(14.85));
        // Check that it works the other way round too.
        Vector2<double> v2 = 4.5 * Vector2<double>(8.4, 3.3);
        CHECK(v1.x == Approx(v2.x));
        CHECK(v1.y == Approx(v2.y));
    }

    SECTION("Scalar multiplication assignment")
    {
        Vector2<double> v = Vector2<double>(3.9, 9.6);
        v *= 5.1;
        CHECK(v.x == Approx(19.89));
        CHECK(v.y == Approx(48.96));
    }

    SECTION("Scalar division")
    {
        Vector2<double> v1 = Vector2<double>(12.3, 6.7) / 2.2;
        // Check the we got the right answer
        CHECK(v1.x == Approx(5.59090909));
        CHECK(v1.y == Approx(3.04545455));
        // Check that the inverse works
        Vector2<double> v2 = 2.2 / Vector2<double>(12.3, 6.7);
        CHECK(v1.x == Approx(1.0 / v2.x));
        CHECK(v1.y == Approx(1.0 / v2.y));
    }

    SECTION("Scalar division assignment")
    {
        Vector2<double> v = Vector2<double>(8.6, 10.7);
        v *= 3.8;
        CHECK(v.x == Approx(2.26315789));
        CHECK(v.y == Approx(2.81578947));
    }

    SECTION("Negation")
    {
        Vector2<double> v = -Vector2<double>(14.6, -8.2);
        CHECK(v.x == -14.6);
        CHECK(v.y == 8.2);
    }
}

TEST_CASE("Vector2 - operations", "[Vector2]")
{
    SECTION("Magnitude")
    {
        Vector2<double> v(5.0, 10.0);
        CHECK(v.getMagnitude() == Approx(11.180339887));
    }

    SECTION("Squared magnitude")
    {
        Vector2<double> v(4.0, 3.0);
        CHECK(v.getSqMagnitude() == Approx(25.0));
    }

    SECTION("Normalise in place")
    {
        Vector2<double> v(-43.2, 87.6);
        v.normalise();
        CHECK(v.x == Approx(-0.44229248));
        CHECK(v.y == Approx(0.89687087));
    }

    SECTION("Get normalised")
    {
        Vector2<double> v1(87.6, -43.2);
        Vector2<double> v2 = v1.getNormalised();
        CHECK(v2.x == Approx(0.89687087));
        CHECK(v2.y == Approx(-0.44229248));
    }

    SECTION("Dot product")
    {
        Vector2<double> v1(3.4, 9.2);
        Vector2<double> v2(8.6, 1.9);
        CHECK(v1.dot(v2) == 46.72);
    }

    SECTION("Right tangent")
    {
        Vector2<double> v1(8.8, 1.9);
        Vector2<double> v2 = v1.getRightTangent();
        CHECK(v1.dot(v2) == Approx(0.0));
    }

    SECTION("Left tangent")
    {
        Vector2<double> v1(3.7, 2.4);
        Vector2<double> v2 = v1.getLeftTangent();
        CHECK(v1.dot(v2) == Approx(0.0));
    }

    // TODO: Projection length/vector
}


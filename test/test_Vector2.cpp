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

    // vector subtraction / assignment
    // scalar multiplication / assignment
    // scalar division / assignment
    // negation
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

    // dot product
    // right tangent
    // left tangent
}

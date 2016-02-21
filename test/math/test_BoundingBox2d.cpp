/** \file test_BoundingBox2d.cpp
    \brief Unit testing for the BoundingBox2d class.

    Depends on the Catch framework: https://github.com/philsquared/Catch

    Part of the Avid Insight Library (avidinsight.uk/ail).
    Copyright (C) 2015-16 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include "../common.h"

using namespace ail::math;

TEST_CASE("BoundingBox2d - construction and assignment", "[math::BoundingBox2d]")
{
    SECTION("Default construction to 0")
    {
        BoundingBox2d<int> bi;
        CHECK(bi.pos.x == 0);
        CHECK(bi.pos.y == 0);
        CHECK(bi.radius.x == 0);
        CHECK(bi.radius.y == 0);

        BoundingBox2d<int> bd;
        CHECK(bd.pos.x == 0.0);
        CHECK(bd.pos.y == 0.0);
        CHECK(bd.radius.x == 0.0);
        CHECK(bd.radius.y == 0.0);
    }

    SECTION("Construction - integer")
    {
        // Construct using individual components.
        BoundingBox2d<int> b1(-54, 12, 1, -19);
        CHECK(b1.pos.x == -54);
        CHECK(b1.pos.y == 12);
        CHECK(b1.radius.x == 1);
        CHECK(b1.radius.y == -19);

        // Construct using vectors.
        BoundingBox2d<int> b2(Vector2d<int>(23, -7), Vector2d<int>(-55, 3));
        CHECK(b2.pos.x == 23);
        CHECK(b2.pos.y == -7);
        CHECK(b2.radius.x == -55);
        CHECK(b2.radius.y == 3);
    }

    SECTION("Construction - floating point")
    {
        // Construct using individual components.
        BoundingBox2d<double> b1(-24.6, -15.2, 0.6, 5.3);
        CHECK(b1.pos.x == Approx(-24.6));
        CHECK(b1.pos.y == Approx(-15.2));
        CHECK(b1.radius.x == Approx(0.6));
        CHECK(b1.radius.y == Approx(5.3));

        // Construct using vectors.
        BoundingBox2d<double> b2(Vector2d<double>(1.004, -99.39), Vector2d<double>(-4.11, 11.8));
        CHECK(b2.pos.x == Approx(1.004));
        CHECK(b2.pos.y == Approx(-99.39));
        CHECK(b2.radius.x == Approx(-4.11));
        CHECK(b2.radius.y == Approx(11.8));
    }
    
    SECTION("Uniform initialisation - integer")
    {
        // Empty initialiser list initialises everything to 0.
        BoundingBox2d<int> b1 {};
        CHECK(b1.pos.x == 0);
        CHECK(b1.pos.y == 0);
        CHECK(b1.radius.x == 0);
        CHECK(b1.radius.y == 0);

        // Explicit vectors.
        BoundingBox2d<int> b2 { Vector2d<int>(101, 77), Vector2d<int>(-11, 32) };
        CHECK(b2.pos.x == 101);
        CHECK(b2.pos.y == 77);
        CHECK(b2.radius.x == -11);
        CHECK(b2.radius.y == 32);

        // Uniformly initialised vectors.
        BoundingBox2d<int> b3 { {-2, 13}, {9, -41} };
        CHECK(b3.pos.x == -2);
        CHECK(b3.pos.y == 13);
        CHECK(b3.radius.x == 9);
        CHECK(b3.radius.y == -41);
    }

    SECTION("Uniform initialisation - floating point")
    {
        // Empty initialiser list initialises everything to 0.
        BoundingBox2d<double> b1 {};
        CHECK(b1.pos.x == 0.0);
        CHECK(b1.pos.y == 0.0);
        CHECK(b1.radius.x == 0.0);
        CHECK(b1.radius.y == 0.0);

        // Explicit vectors.
        BoundingBox2d<double> b2 { Vector2d<double>(-46.36, 0.052), Vector2d<double>(8.3, -2.09) };
        CHECK(b2.pos.x == Approx(-46.36));
        CHECK(b2.pos.y == Approx(0.052));
        CHECK(b2.radius.x == Approx(8.3));
        CHECK(b2.radius.y == Approx(-2.09));

        // Uniformly initialised vectors.
        BoundingBox2d<double> b3 { {8.7, -1.303}, {16.6, 57.4} };
        CHECK(b3.pos.x == Approx(8.7));
        CHECK(b3.pos.y == Approx(-1.303));
        CHECK(b3.radius.x == Approx(16.6));
        CHECK(b3.radius.y == Approx(57.4));
    }

    SECTION("Uniform initialisation - wrong size")
    {
        CHECK_THROWS(BoundingBox2d<int> { Vector2d<int>() });
        CHECK_THROWS((BoundingBox2d<int> { {1,2}, {3,4}, {5,6} }));

        CHECK_THROWS(BoundingBox2d<double> { Vector2d<double>() });
        CHECK_THROWS((BoundingBox2d<double> { {1.1,2.2}, {3.3,4.4}, {5.5,6.6} }));
    }

    // TODO: Copy construction
    // TODO: Copy assignment
}

// TODO: set() modifiers
// TODO: getCornerX() accessors
// TODO: equality/inequality operators
// TODO: contains/intersects tests


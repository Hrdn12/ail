#include "common.h"

using namespace avidmath;
using namespace avidmath::constants;

TEST_CASE("Angle conversion", "[Angles]")
{
    SECTION("Degrees to other angles")
    {
        // Degrees to Radians
        REQUIRE(degToRad(0.0) ==      Approx(0.0));
        REQUIRE(degToRad(45.0) ==     Approx(0.7853981634));
        REQUIRE(degToRad(-45.0) ==    Approx(-0.7853981634));
        REQUIRE(degToRad(105.97) ==   Approx(1.8495254083));
        REQUIRE(degToRad(-105.97) ==  Approx(-1.8495254083));
        REQUIRE(degToRad(180.0) ==    Approx(3.1415926536));
        REQUIRE(degToRad(-180.0) ==   Approx(-3.1415926536));
        REQUIRE(degToRad(491.224) ==  Approx(8.5734761648));
        REQUIRE(degToRad(-491.224) == Approx(-8.5734761648));

        // Degrees to Gradians
        REQUIRE(degToGrad(0.0) ==      Approx(0.0));
        REQUIRE(degToGrad(45.0) ==     Approx(50.0));
        REQUIRE(degToGrad(-45.0) ==    Approx(-50.0));
        REQUIRE(degToGrad(105.97) ==   Approx(117.74444444));
        REQUIRE(degToGrad(-105.97) ==  Approx(-117.74444444));
        REQUIRE(degToGrad(180.0) ==    Approx(200.0));
        REQUIRE(degToGrad(-180.0) ==   Approx(-200.0));
        REQUIRE(degToGrad(491.224) ==  Approx(545.80444444));
        REQUIRE(degToGrad(-491.224) == Approx(-545.80444444));

        // Degress to Circles
        REQUIRE(degToCir(0.0) ==      Approx(0.0));
        REQUIRE(degToCir(45.0) ==     Approx(0.125));
        REQUIRE(degToCir(-45.0) ==    Approx(-0.125));
        REQUIRE(degToCir(105.97) ==   Approx(0.29436111111));
        REQUIRE(degToCir(-105.97) ==  Approx(-0.29436111111));
        REQUIRE(degToCir(180.0) ==    Approx(0.5));
        REQUIRE(degToCir(-180.0) ==   Approx(-0.5));
        REQUIRE(degToCir(491.224) ==  Approx(1.3645111111));
        REQUIRE(degToCir(-491.224) == Approx(-1.3645111111));
    }

    SECTION("Radians to other angles")
    {
        // Radians to Degrees
        // TODO

        // Radians to Gradians
        // TODO

        // Radians to Circles
        // TODO
    }

    SECTION("Gradians to other angles")
    {
        // Gradians to Degrees
        // TODO

        // Gradians to Radians
        // TODO

        // Gradians to Circles
        // TODO
    }

    SECTION("Circles to other angles")
    {
        // Circles to Degrees
        // TODO

        // Circles to Radians
        // TODO

        // Circles to Gradians
        // TODO
    }

    // other sections: comparisons, numerical utilities
}


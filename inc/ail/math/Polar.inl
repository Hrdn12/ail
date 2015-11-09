#ifndef ail_math_Polar_inl
#define ail_math_Polar_inl

/** \file Polar.inl
    \brief Implementation for 2d polar vector (angle / magnitude).

    Part of ail, the Avid Insight Library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/



#include <cmath>
#include <cassert>
#include <stdexcept>

#include "Polar.h"
#include "Vector2d.h"
#include "Utils.h"
#include "Constants.h"

//--------------
namespace ail {
namespace math {
//--------------

//------------------------------------------------------------------------------
// Construction / destruction.

template <typename T_ty>
Polar<T_ty>::Polar() :
    angle(0), mag(0)
{
}

template <typename T_ty>
Polar<T_ty>::Polar(const T_ty angle, const T_ty mag) :
    angle(angle), mag(mag)
{
}


template <typename T_ty>
Polar<T_ty>::Polar(std::initializer_list<T_ty> args) :
    Polar()
{
    if (args.size() == 0)
        return;

    if (args.size() != 2)
        throw std::invalid_argument("Expected 0 or 2 arguments in initializer list.");

    angle = *args.begin();
    mag = *(args.begin() + 1);
}

template <typename T_ty>
Polar<T_ty>::Polar(const Polar<T_ty> & rhs) :
    angle(rhs.angle), mag(rhs.mag)
{
}

template <typename T_ty>
Polar<T_ty>::Polar(const Vector2d<T_ty> & rhs) :
    Polar()
{
    rhs.toPolar(*this);
}

template <typename T_ty>
Polar<T_ty>::~Polar()
{
}

//------------------------------------------------------------------------------
// Operators.

template <typename T_ty>
Polar<T_ty> & Polar<T_ty>::operator = (const Polar<T_ty> & rhs)
{
    angle = rhs.angle;
    mag = rhs.mag;
    return *this;
}

template <typename T_ty>
bool Polar<T_ty>::operator == (const Polar<T_ty> & rhs) const
{
    return angle == rhs.angle && mag == rhs.mag;
}

template <typename T_ty>
bool Polar<T_ty>::operator != (const Polar<T_ty> & rhs) const
{
    return !(angle == rhs.angle && mag == rhs.mag);
}

template <typename T_ty>
Polar<T_ty> Polar<T_ty>::operator - () const
{
    return Polar<T_ty>(angle, -mag);
}

//------------------------------------------------------------------------------
// Accessors / operations.

template <typename T_ty>
void Polar<T_ty>::set(const T_ty angle, const T_ty mag)
{
    this->angle = angle;
    this->mag = mag;
}

template <typename T_ty>
void Polar<T_ty>::simplify()
{
    // Make sure the magnitude is positive.
    if (mag < T_ty(0)) {
        angle += pi<T_ty>();
        mag *= T_ty(-1);
    }

    // Make sure the angle is positive and is less than a full circle.
    angle = wrap(angle, T_ty(0), pi<T_ty>() * T_ty(2));
}

template <typename T_ty>
Polar<T_ty> Polar<T_ty>::getSimplified() const
{
    Polar<T_ty> output(*this);
    output.simplify();
    return output;
}

template <typename T_ty>
bool Polar<T_ty>::isNear(const Polar<T_ty> & other, const T_ty dist) const
{
    return toVector2d().isNear(other.toVector2d(), dist);
}

template <typename T_ty>
bool Polar<T_ty>::isApproxEqual(const Polar<T_ty> & other, const T_ty margin) const
{
    return
        ail::math::isApproxEqual(angle, other.angle, margin) &&
        ail::math::isApproxEqual(mag, other.mag, margin);
}

template <typename T_ty>
bool Polar<T_ty>::isApproxEqual(const Polar<T_ty> & other, const T_ty angleMargin, const T_ty magMargin) const
{
    return
        ail::math::isApproxEqual(angle, other.angle, angleMargin) &&
        ail::math::isApproxEqual(mag, other.mag, magMargin);
}

//------------------------------------------------------------------------------
// Conversions.

template <typename T_ty>
void Polar<T_ty>::toVector2d(Vector2d<T_ty> & output) const
{
    output.x = mag * std::cos(angle);
    output.y = mag * std::sin(angle);
}

template <typename T_ty>
Vector2d<T_ty> Polar<T_ty>::toVector2d() const
{
    Vector2d<T_ty> output;
    toVector2d(output);
    return output;
}

//--------------
} // math
} // ail
//--------------

#endif //ail_math_Polar_inl

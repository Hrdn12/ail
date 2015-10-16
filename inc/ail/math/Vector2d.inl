#ifndef ail_math_Vector2d_inl
#define ail_math_Vector2d_inl

/** \file Vector2d.inl
    \brief Implementation for a 2d cartesian vector (see Vector2d.h).

    Part of ail, the Avid Insight Library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include <cmath>
#include <cassert>

#include "Vector2d.h"
#include "Polar.h"
#include "Utils.h"

//--------------
namespace ail {
namespace math {
//--------------

//------------------------------------------------------------------------------
// Construction / destruction.

template <typename T_ty>
Vector2d<T_ty>::Vector2d() :
    x(0), y(0)
{
}

template <typename T_ty>
Vector2d<T_ty>::Vector2d(const T_ty tX, const T_ty tY) :
    x(tX), y(tY)
{
}

template <typename T_ty>
Vector2d<T_ty>::Vector2d(const Vector2d<T_ty> & rhs) :
    x(rhs.x), y(rhs.y)
{
}

template <typename T_ty>
Vector2d<T_ty>::Vector2d(const Polar<T_ty> & rhs) :
    Vector2d<T_ty>()
{
    rhs.toVector2d(*this);
}

template <typename T_ty>
Vector2d<T_ty>::~Vector2d()
{
}

//------------------------------------------------------------------------------
// Operators.

template <typename T_ty>
Vector2d<T_ty> & Vector2d<T_ty>::operator = (const Vector2d<T_ty> & rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

template <typename T_ty>
bool Vector2d<T_ty>::operator == (const Vector2d<T_ty> & rhs) const
{
    return x == rhs.x && y == rhs.y;
}

template <typename T_ty>
bool Vector2d<T_ty>::operator != (const Vector2d<T_ty> & rhs) const
{
    return !(x == rhs.x && y == rhs.y);
}

template <typename T_ty>
Vector2d<T_ty> & Vector2d<T_ty>::operator += (const Vector2d<T_ty> & rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

template <typename T_ty>
Vector2d<T_ty> & Vector2d<T_ty>::operator -= (const Vector2d<T_ty> & rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

template <typename T_ty>
Vector2d<T_ty> & Vector2d<T_ty>::operator *= (const T_ty rhs)
{
    x *= rhs;
    y *= rhs;
    return *this;
}

template <typename T_ty>
Vector2d<T_ty> & Vector2d<T_ty>::operator /= (const T_ty rhs)
{
    assert(rhs != 0);
    x /= rhs;
    y /= rhs;
    return *this;
}

template <typename T_ty>
Vector2d<T_ty> Vector2d<T_ty>::operator - () const
{
    return Vector2d<T_ty>(-x, -y);
}

//------------------------------------------------------------------------------
// Accessors / operations.

template <typename T_ty>
void Vector2d<T_ty>::set(const T_ty tX, const T_ty tY)
{
    x = tX;
    y = tY;
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getLength() const
{
    return std::sqrt((x * x) + (y * y));
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getSqLength() const
{
    return (x*x) + (y*y);
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getRectilinearLength() const
{
    return std::abs(x) + std::abs(y);
}

template <typename T_ty>
void Vector2d<T_ty>::normalise()
{
    const T_ty mag = getLength();
    if (mag != 0) {
        x /= mag;
        y /= mag;
    }
}

template <typename T_ty>
Vector2d<T_ty> Vector2d<T_ty>::getNormalised() const
{
    auto cpy = *this;
    cpy.normalise();
    return cpy;
}

template <typename T_ty>
Vector2d<T_ty> Vector2d<T_ty>::getRightTangent() const
{
    return Vector2d<T_ty>(y, -x);
}

template <typename T_ty>
Vector2d<T_ty> Vector2d<T_ty>::getLeftTangent() const
{
    return Vector2d<T_ty>(-y, x);
}

template <typename T_ty>
T_ty Vector2d<T_ty>::dot(const Vector2d<T_ty> &rhs) const
{
    return (x * rhs.x) + (y * rhs.y);
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getScalarProjection(const Vector2d<T_ty> &rhs) const
{
    const T_ty rhsMag = rhs.getLength();
    if (rhsMag == 0) return 0;
    return dot(rhs) / rhsMag;
}

template <typename T_ty>
Vector2d<T_ty> Vector2d<T_ty>::getVectorProjection(const Vector2d<T_ty> &rhs) const
{
    const T_ty rhsSqMag = rhs.getSqLength();
    if (rhsSqMag == 0) return Vector2d<T_ty>();
    return (dot(rhs) / rhsSqMag) * rhs;
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getDistance(const Vector2d<T_ty> & other) const
{
    return (*this - other).getLength();
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getSqDistance(const Vector2d<T_ty> & other) const
{
    return (*this - other).getSqLength();
}

template <typename T_ty>
T_ty Vector2d<T_ty>::getRectilinearDistance(const Vector2d<T_ty> & other) const
{
    return (*this - other).getRectilinearLength();
}

template <typename T_ty>
bool Vector2d<T_ty>::isNear(const Vector2d<T_ty> & other, const T_ty dist) const
{
    return getSqDistance(other) <= (dist * dist);
}

template <typename T_ty>
bool Vector2d<T_ty>::isNearRectilinear(const Vector2d<T_ty> & other, const T_ty dist) const
{
    return getRectilinearDistance(other) <= (dist * dist);
}

template <typename T_ty>
bool Vector2d<T_ty>::isApproxEqual(const Vector2d<T_ty> & other, const T_ty margin) const
{
    return
        ail::math::isApproxEqual(x, other.x, margin) &&
        ail::math::isApproxEqual(y, other.y, margin);
}

//------------------------------------------------------------------------------
// Conversions.

template <typename T_ty>
void Vector2d<T_ty>::toPolar(Polar<T_ty> & output) const
{
    output.mag = getLength();
    output.angle = static_cast<T_ty>(std::atan2(y, x));
    output.simplify();
}

template <typename T_ty>
Polar<T_ty> Vector2d<T_ty>::toPolar() const
{
    Polar<T_ty> output;
    toPolar(output);
    return output;
}

//------------------------------------------------------------------------------
// Global operators.

/// Adds two cartesian vectors together and returns the result.
template <typename T_ty>
Vector2d<T_ty> operator + (const Vector2d<T_ty> & lhs, const Vector2d<T_ty> & rhs)
{
    Vector2d<T_ty> ans(lhs);
    return ans += rhs;
}

/// Subtracts one cartesian vector (rhs) from another (lhs) and returns the result.
template <typename T_ty>
Vector2d<T_ty> operator - (const Vector2d<T_ty> & lhs, const Vector2d<T_ty> & rhs)
{
    Vector2d<T_ty> ans(lhs);
    return ans -= rhs;
}

/// Multiplies a cartesian vector by a scalar and returns the result.
template <typename T_ty>
Vector2d<T_ty> operator * (const Vector2d<T_ty> & lhs, const T_ty & rhs)
{
    Vector2d<T_ty> ans(lhs);
    return ans *= rhs;
}

/// Multiplies a cartesian vector by a scalar and returns the result.
template <typename T_ty>
Vector2d<T_ty> operator * (const T_ty & lhs, const Vector2d<T_ty> & rhs)
{
    Vector2d<T_ty> ans(rhs);
    return ans *= lhs;
}

/// Divides a cartesian vector by a scalar and returns the result.
template <typename T_ty>
Vector2d<T_ty> operator / (const Vector2d<T_ty> & lhs, const T_ty & rhs)
{
    Vector2d<T_ty> ans(lhs);
    return ans /= rhs;
}

/// Divides a scalar by a cartesian vector and returns the result.
template <typename T_ty>
Vector2d<T_ty> operator / (const T_ty & lhs, const Vector2d<T_ty> & rhs)
{
    Vector2d<T_ty> ans(rhs);
    ans.x = lhs / ans.x;
    ans.y = lhs / ans.y;
    return ans;
}

//--------------
} // math
} // ail
//--------------

#endif //ail_math_Vector2d_inl

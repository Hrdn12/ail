#ifndef ail_math_BoundingBox2d_inl
#define ail_math_BoundingBox2d_inl

/** \file BoundingBox2d.h
    \brief Implements a 2d axis aligned bounding box class.

    Part of ail, the Avid Insight Library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include <cassert>
#include <cmath>

#include "BoundingBox2d.h"

//--------------
namespace ail {
namespace math {
//--------------

//------------------------------------------------------------------------------
// Construction / destruction.

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d()
{
}

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & radius) :
    pos(pos), radius(radius)
{
}

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d(std::initializer_list<Vector2d<T_ty>> args) :
    BoundingBox2d()
{
    if (args.size() == 0)
        return;

    if (args.size() != 2)
        throw std::invalid_argument("Expected 0 or 2 arguments in initializer list.");

    pos = *args.begin();
    radius = *(args.begin() + 1);
}

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d(const T_ty posX, const T_ty posY, const T_ty radiusX, const T_ty radiusY) :
    pos(posX, posY), radius(radiusX, radiusY)
{
}

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d(const BoundingBox2d<T_ty> & rhs) :
    pos(rhs.pos), radius(rhs.size)
{
}

template <typename T_ty>
BoundingBox2d<T_ty>::~BoundingBox2d()
{
}

//------------------------------------------------------------------------------
// Operators.

template <typename T_ty>
BoundingBox2d<T_ty> & BoundingBox2d<T_ty>::operator = (const BoundingBox2d<T_ty> & rhs)
{
    pos = rhs.pos;
    radius = rhs.radius;
    return *this;
}

template <typename T_ty>
bool BoundingBox2d<T_ty>::operator == (const BoundingBox2d<T_ty> & rhs) const
{
    return pos == rhs.pos && radius == rhs.radius;
}

template <typename T_ty>
bool BoundingBox2d<T_ty>::operator != (const BoundingBox2d<T_ty> & rhs) const
{
    return !(*this == rhs);
}

//------------------------------------------------------------------------------
// Accessors / operations.

template <typename T_ty>
void BoundingBox2d<T_ty>::set(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & size)
{
    this->pos = pos;
    this->radius = radius;
}

template <typename T_ty>
void BoundingBox2d<T_ty>::set(const T_ty posX, const T_ty posY, const T_ty radiusX, const T_ty radiusY)
{
    pos.set(posX, posY);
    radius.set(radiusX, radiusY);
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX1Y1() const
{
    return pos - radius;
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX2Y2() const
{
    return pos + radius;
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX1Y2() const
{
    return Vector2d<T_ty>(pos.x - radius.x, pos.y + radius.y);
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX2Y1() const
{
    return Vector2d<T_ty>(pos.x + radius.x, pos.y - radius.y);
}

//------------------------------------------------------------------------------
// Tests.

template <typename T_ty>
bool BoundingBox2d<T_ty>::contains(const Vector2d<T_ty> &point) const
{
    return
        point.x >= (pos.x - radius.x) &&
        point.y >= (pos.y - radius.y) &&
        point.x <= (pos.x + radius.x) &&
        point.y <= (pos.y + radius.y);
}

template <typename T_ty>
bool BoundingBox2d<T_ty>::intersects(const BoundingBox2d<T_ty> &rhs) const
{
    return
        std::fabs(pos.x - rhs.pos.x) <= (radius.x + rhs.radius.x) &&
        std::fabs(pos.y - rhs.pos.y) <= (radius.y + rhs.radius.y);
}

//--------------
} // math
} // ail
//--------------

#endif //ail_math_BoundingBox2d_inl

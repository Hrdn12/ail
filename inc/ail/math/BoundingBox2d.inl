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
BoundingBox2d<T_ty>::BoundingBox2d(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & size) :
    pos(pos), size(size)
{
}

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d(const T_ty x, const T_ty y, const T_ty w, const T_ty h) :
    pos(x, y), size(w, h)
{
}

template <typename T_ty>
BoundingBox2d<T_ty>::BoundingBox2d(const BoundingBox2d<T_ty> & rhs) :
    pos(rhs.pos), size(rhs.size)
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
    size = rhs.size;
    return *this;
}

template <typename T_ty>
bool BoundingBox2d<T_ty>::operator == (const BoundingBox2d<T_ty> & rhs) const
{
    return pos == rhs.pos && size == rhs.size;
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
    this->size = size;
}

template <typename T_ty>
void BoundingBox2d<T_ty>::set(const T_ty x, const T_ty y, const T_ty w, const T_ty h)
{
    pos.set(x, y);
    size.set(w, h);
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX1Y1() const
{
    return pos - size;
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX2Y2() const
{
    return pos + size;
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX1Y2() const
{
    return Vector2d<T_ty>(pos.x - size.x, pos.y + size.y);
}

template <typename T_ty>
Vector2d<T_ty> BoundingBox2d<T_ty>::getCornerX2Y1() const
{
    return Vector2d<T_ty>(pos.x + size.x, pos.y - size.y);
}

//------------------------------------------------------------------------------
// Tests.

template <typename T_ty>
bool BoundingBox2d<T_ty>::contains(const Vector2d<T_ty> &point) const
{
    return
        point.x >= (pos.x - size.x) &&
        point.y >= (pos.y - size.y) &&
        point.x <= (pos.x + size.x) &&
        point.y <= (pos.y + size.y);
}

template <typename T_ty>
bool BoundingBox2d<T_ty>::intersects(const BoundingBox2d<T_ty> &rhs) const
{
    return
        std::fabs(pos.x - rhs.pos.x) <= (size.x + rhs.size.x) &&
        std::fabs(pos.y - rhs.pos.y) <= (size.y + rhs.size.y);
}

//--------------
} // math
} // ail
//--------------

#endif //ail_math_BoundingBox2d_inl

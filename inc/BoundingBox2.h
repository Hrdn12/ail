/** \file BoundingBox2.h
    \brief Declares a class representing a 2d axis aligned bounding box.

    Part of the avidmath library (avid-insight.co.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#ifndef avidmath_BoundingBox2_h
#define avidmath_BoundingBox2_h

#include "Vector2.h"

namespace avidmath
{
    /// Represents a 2d axis-aligned bounding box.
    /// The template parameter specifies the underlying value type (typically float or double).
    template <typename T_ty>
    class BoundingBox2
    {
    public:
        //------------------------------------------------------------------------------
        // Construction / destruction.

        /// Constructor - initialises everything to 0.
        BoundingBox2();

        /// Constructor - explicitly initialises the centre and radius (size) of the box.
        BoundingBox2(const Vector2<T_ty> & pos, const Vector2<T_ty> & size);

        /// Constructor - explicitly initialises the centre and radius (size) of the box.
        BoundingBox2(const T_ty x, const T_ty y, const T_ty w, const T_ty h);

        /// Copy constructor
        BoundingBox2(const BoundingBox2<T_ty> & rhs);

        /// Destructor
        ~BoundingBox2();


        //------------------------------------------------------------------------------
        // Operators.

        /// Copy assignment operator.
        const BoundingBox2<T_ty> & operator = (const BoundingBox2<T_ty> & rhs);

        /// Equality test.
        /// Note that this tests for exact equality, which isn't necessarily desirable for floating point types.
        bool operator == (const BoundingBox2<T_ty> & rhs) const;

        /// Equality test.
        /// Note that this tests for lack of exact equality, which isn't necessarily desirable for floating point types.
        bool operator != (const BoundingBox2<T_ty> & rhs) const;


        //------------------------------------------------------------------------------
        // Accessors / operations.

        /// Sets the centre and radius vectors in one call.
        void set(const Vector2<T_ty> & pos, const Vector2<T_ty> & size);

        /// Sets the centre and radius vectors in one call.
        void set(const T_ty x, const T_ty y, const T_ty w, const T_ty h);


        /// Get the position of the -X -Y corner of the box.
        const Vector2<T_ty> getCornerX1Y1() const;

        /// Get the position of the +X +Y corner of the box.
        const Vector2<T_ty> getCornerX2Y2() const;

        /// Get the position of the -X +Y corner of the box.
        const Vector2<T_ty> getCornerX1Y2() const;

        /// Get the position of the +X -Y corner of the box.
        const Vector2<T_ty> getCornerX2Y1() const;


        //------------------------------------------------------------------------------
        // Tests.

        /// Check if this box contains the given point.
        bool contains(const Vector2<T_ty> &point) const;

        /// Check if this box intersects another box.
        bool intersects(const BoundBox2<T_ty> &rhs) const;


        //------------------------------------------------------------------------------
        // Data.

        /// Position of the centre of this box.
        Vector2<T_ty> pos;

        /// The size of the bounding box (distance from the centre to the edge).
        /// Note that this is half the total width/height.
        Vector2<T_ty> size;
    };

    //------------------------------------------------------------------------------
    // Inline definitions.

    template <typename T_ty>
    BoundBox2<T_ty>::BoundingBox2()
    {
    }

    template <typename T_ty>
    BoundBox2<T_ty>::BoundingBox2(const Vector2<T_ty> & pos, const Vector2<T_ty> & size) :
        pos(pos), size(size)
    {
    }

    template <typename T_ty>
    BoundBox2<T_ty>::BoundingBox2(const T_ty x, const T_ty y, const T_ty w, const T_ty h) :
        pos(x, y), size(w, h)
    {
    }

    template <typename T_ty>
    BoundBox2<T_ty>::BoundingBox2(const BoundingBox2<T_ty> & rhs) :
        pos(rhs.pos), size(rhs.size)
    {
    }

    template <typename T_ty>
    BoundBox2<T_ty>::~BoundingBox2()
    {
    }

    template <typename T_ty>
    const BoundingBox2<T_ty> & BoundBox2<T_ty>::operator = (const BoundingBox2<T_ty> & rhs)
    {
        pos = rhs.pos;
        size = rhs.size;
        return *this;
    }

    template <typename T_ty>
    bool BoundBox2<T_ty>::operator == (const BoundingBox2<T_ty> & rhs) const
    {
        return pos == rhs.pos && size == rhs.size;
    }

    template <typename T_ty>
    bool BoundBox2<T_ty>::operator != (const BoundingBox2<T_ty> & rhs) const
    {
        return !(pos == rhs.pos && size == rhs.size);
    }

    template <typename T_ty>
    void BoundBox2<T_ty>::set(const Vector2<T_ty> & pos, const Vector2<T_ty> & size)
    {
        this->pos = pos;
        this->size = size;
    }

    template <typename T_ty>
    void BoundBox2<T_ty>::set(const T_ty x, const T_ty y, const T_ty w, const T_ty h)
    {
        pos.set(x, y);
        size.set(w, h);
    }

    template <typename T_ty>
    const Vector2<T_ty> BoundBox2<T_ty>::getCornerX1Y1() const
    {
        return pos - size;
    }

    template <typename T_ty>
    const Vector2<T_ty> BoundBox2<T_ty>::getCornerX2Y2() const
    {
        return pos + size;
    }

    template <typename T_ty>
    const Vector2<T_ty> BoundBox2<T_ty>::getCornerX1Y2() const
    {
        return Vector2<T_ty>(pos.x - size.x, pos.y + size.y);
    }

    template <typename T_ty>
    const Vector2<T_ty> BoundBox2<T_ty>::getCornerX2Y1() const
    {
        return Vector2<T_ty>(pos.x + size.x, pos.y - size.y);
    }

    template <typename T_ty>
    bool BoundBox2<T_ty>::contains(const Vector2<T_ty> &point) const
    {
        return
            point.x >= (pos.x - size.x) &&
            point.y >= (pos.y - size.y) &&
            point.x <= (pos.x + size.x) &&
            point.y <= (pos.y + size.y);
    }

    template <typename T_ty>
    bool BoundBox2<T_ty>::intersects(const BoundBox2<T_ty> &rhs) const
    {
        return
            std::fabs(pos.x - rhs.pos.x) <= (size.x + rhs.size.x) &&
            std::fabs(pos.y - rhs.pos.y) <= (size.y + rhs.size.y);
    }
}

#endif //avidmath_BoundingBox2_h

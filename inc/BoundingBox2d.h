#ifndef avidmath_BoundingBox2d_h
#define avidmath_BoundingBox2d_h

/** \file BoundingBox2d.h
    \brief Declares a class representing a 2d axis aligned bounding box.

    Part of the avidmath library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include "Vector2d.h"

namespace avidmath
{
    /// Represents a 2d axis-aligned bounding box.
    /// The template parameter specifies the underlying value type (typically float or double).
    template <typename T_ty>
    class BoundingBox2d
    {
    public:
        //------------------------------------------------------------------------------
        // Construction / destruction.

        /// Constructor - initialises everything to 0.
        BoundingBox2d();

        /// Constructor - explicitly initialises the centre and radius (size) of the box.
        BoundingBox2d(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & size);

        /// Constructor - explicitly initialises the centre and radius (size) of the box.
        BoundingBox2d(const T_ty x, const T_ty y, const T_ty w, const T_ty h);

        /// Copy constructor
        BoundingBox2d(const BoundingBox2d<T_ty> & rhs);

        /// Destructor
        ~BoundingBox2d();


        //------------------------------------------------------------------------------
        // Operators.

        /// Copy assignment operator.
        BoundingBox2d<T_ty> & operator = (const BoundingBox2d<T_ty> & rhs);

        /// Equality test.
        /// Note that this tests for exact equality, which isn't necessarily desirable for floating point types.
        bool operator == (const BoundingBox2d<T_ty> & rhs) const;

        /// Equality test.
        /// Note that this tests for lack of exact equality, which isn't necessarily desirable for floating point types.
        bool operator != (const BoundingBox2d<T_ty> & rhs) const;


        //------------------------------------------------------------------------------
        // Accessors / operations.

        /// Sets the centre and radius vectors in one call.
        void set(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & size);

        /// Sets the centre and radius vectors in one call.
        void set(const T_ty x, const T_ty y, const T_ty w, const T_ty h);


        /// Get the position of the -X -Y corner of the box.
        Vector2d<T_ty> getCornerX1Y1() const;

        /// Get the position of the +X +Y corner of the box.
        Vector2d<T_ty> getCornerX2Y2() const;

        /// Get the position of the -X +Y corner of the box.
        Vector2d<T_ty> getCornerX1Y2() const;

        /// Get the position of the +X -Y corner of the box.
        Vector2d<T_ty> getCornerX2Y1() const;


        //------------------------------------------------------------------------------
        // Tests.

        /// Check if this box contains the given point.
        bool contains(const Vector2d<T_ty> &point) const;

        /// Check if this box intersects another box.
        bool intersects(const BoundingBox2d<T_ty> &rhs) const;


        //------------------------------------------------------------------------------
        // Data.

        /// Position of the centre of this box.
        Vector2d<T_ty> pos;

        /// The size of the bounding box (distance from the centre to the edge).
        /// Note that this is half the total width/height.
        Vector2d<T_ty> size;
    };
}

#endif //avidmath_BoundingBox2d_h

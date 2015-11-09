#ifndef ail_math_BoundingBox2d_h
#define ail_math_BoundingBox2d_h

/** \file BoundingBox2d.h
    \brief Declares a class representing a 2d rectangle which is axis-aligned.

    Part of ail, the Avid Insight Library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include <initializer_list>
#include "Vector2d.h"

//--------------
namespace ail {
namespace math {
//--------------

/// Represents a 2d rectangle which is axis-aligned.
/// This is typically used in optimisation algorithms rather than representing
///  actual geometry.
/// Template parameter specifies the underlying value type (e.g. float or double).
template <typename T_ty>
class BoundingBox2d
{
public:
    //------------------------------------------------------------------------------
    // Construction / destruction.

    /// Constructor - initialises everything to 0.
    BoundingBox2d();

    /// Constructor - explicitly initialises the position and size of the box.
    /// pos gives the position of the box's centre.
    /// The x and y components of radius give half the overall width and height.
    BoundingBox2d(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & radius);

    /// Initializer list constructor - expects a pair of vectors.
    /// Order of elements is: position, radius.
    /// If list if empty, values are initialised to 0.
    BoundingBox2d(std::initializer_list<Vector2d<T_ty>> args);

    /// Constructor - explicitly initialises the position and size of the box.
    /// posX and posY give the position of the box's centre.
    /// radiusX and radiusY give half the overall width and height respectively.
    BoundingBox2d(const T_ty posX, const T_ty posY, const T_ty radiusX, const T_ty radiusY);

    /// Copy constructor
    BoundingBox2d(const BoundingBox2d<T_ty> & rhs);

    /// Destructor
    ~BoundingBox2d();


    //------------------------------------------------------------------------------
    // Operators.

    /// Copy assignment operator.
    BoundingBox2d<T_ty> & operator = (const BoundingBox2d<T_ty> & rhs);

    /// Equality test.
    /// Note that this tests for exact equality, which isn't usually desirable for
    ///  floating point types.
    bool operator == (const BoundingBox2d<T_ty> & rhs) const;

    /// Equality test.
    /// Note that this tests for (lack of) exact equality, which isn't usually
    ///  desirable for floating point types.
    bool operator != (const BoundingBox2d<T_ty> & rhs) const;


    //------------------------------------------------------------------------------
    // Accessors / operations.

    /// Sets the position and size in one call.
    /// pos gives the position of the box's centre.
    /// The x and y components of radius give half the overall width and height.
    void set(const Vector2d<T_ty> & pos, const Vector2d<T_ty> & radius);

    /// Sets the position and size in one call.
    /// posX and posY give the position of the box's centre.
    /// radiusX and radiusY give half the overall width and height respectively.
    void set(const T_ty posX, const T_ty posY, const T_ty radiusX, const T_ty radiusY);


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
    bool contains(const Vector2d<T_ty> & point) const;

    /// Check if this box intersects another box.
    bool intersects(const BoundingBox2d<T_ty> & rhs) const;


    //------------------------------------------------------------------------------
    // Data.

    /// Position of the centre of this box.
    Vector2d<T_ty> pos;

    /// The size of the bounding box (distance from the centre to the edge).
    /// Note that this is half the total width/height.
    Vector2d<T_ty> radius;
};

//--------------
} // math
} // ail
//--------------

#endif //ail_math_BoundingBox2d_h

#ifndef ail_math_Polar_h
#define ail_math_Polar_h

/** \file Polar.h
    \brief Declares a 2d polar vector (angle / magnitude). See Polar.inl for implementation.

    Part of ail, the Avid Insight Library (avidinsight.uk/ail).
    Copyright (C) 2015-16 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

//--------------
namespace ail {
namespace math {
//--------------

// Forward declaration to the 2d cartesian vector class. See Vector2.h
template <typename T_ty> class Vector2d;

/// Declares a 2d polar vector (angle / magnitude).
/// In an XY cartesian plane, 0 radians points +X, half pi radians (90 degrees) points +Y.
/// Negative angle and/or magnitude are valid.
/// Template parameter gives the data type for the angle and magnitude.
/// Note that this class uses radians so integer types should be avoided.
template <typename T_ty>
class Polar
{
public:
//------------------------------------------------------------------------------
// Construction / destruction.

    /// Constructor - initialises everything to 0.
    Polar();

    /// Constructor - initialises angle and magnitude.
    /// Angle is measured in radians.
    Polar(const T_ty angle, const T_ty mag);

    /// Constructor - initializer list. Components are ordered: angle, magnitude.
    /// If initialiser list is empty then components are initialised to 0.
    Polar(std::initializer_list<T_ty> args);

    /// Copy constructor.
    Polar(const Polar<T_ty> & rhs);

    /// Convert a cartesian coordinate into polar.
    /// This will use the simplest possible representation of a polar angle,
    ///  i.e. the magnitude will be positive, and the angle will be positive and
    ///  less than 2 pi radians (a full circle).
    explicit Polar(const Vector2d<T_ty> & rhs);

    /// Destructor.
    ~Polar();


//------------------------------------------------------------------------------
// Operators.

    /// Assignment operator.
    Polar<T_ty> & operator = (const Polar<T_ty> & rhs);

    /// Test if this coordinate is exactly equal to another.
    /// Note that this does a simple equality check on the underlying numbers.
    /// It does not check for equivalence, e.g. it will treats 0 radians as being
    ///  not equal to 2 pi radians, even though they are equivalent.
    bool operator == (const Polar<T_ty> & rhs) const;

    /// Test if this coordinate is NOT exactly equal to another.
    /// Note that this does a simple inequality check on the underlying numbers.
    /// It does not check for equivalence, e.g. it will treats 0 radians as being
    ///  not equal to 2 pi radians, even though they are equivalent.
    bool operator != (const Polar<T_ty> & rhs) const;

    /// Negation operator. (Returns a negated copy.)
    /// The returned copy has the magnitude negated. The angle is not changed.
    Polar<T_ty> operator - () const;


//------------------------------------------------------------------------------
// Accessors / operations.

    /// Set the angle and magnitude in one call.
    void set(const T_ty angle, const T_ty mag);

    /// Simplify this coordinate in-place (modifies the current object).
    /// This doesn't change the direction/distance represented by the vector,
    ///  but it ensures the angle is between 0 and two pi, and that the magnitude
    ///  is positive.
    void simplify();

    /// Get a simplified copy of this vector.
    /// The returned polar vector will still represent the same direction/distance
    ///  as this object, but the angle will be between 0 and two pi, and the
    ///  magnitude will be positive.
    Polar<T_ty> getSimplified() const;

    /// Check if this vector represents a point within a certain distance of another.
    /// This effectively converts both to cartesian coordinates and uses
    ///  a Euclidean distance test.
    /// The sign of dist doesn't matter. Its absolute value will be used.
    bool isNear(const Polar<T_ty> & other, const T_ty dist) const;

    /// Check if this vector is approximately equal to another, within a given margin.
    /// Uses the same maring for angle and magnitude.
    /// This does a simple comparison of the components, e.g. it will not detect
    ///  that two pi radians is equivalent to zero radians.
    bool isApproxEqual(const Polar<T_ty> & other, const T_ty margin) const;

    /// Check if this vector is approximately equal to another, within a given margin.
    /// Has separate margins for angle and magnitude.
    /// This does a simple comparison of the components, e.g. it will not detect
    ///  that two pi radians is equivalent to zero radians.
    bool isApproxEqual(const Polar<T_ty> & other, const T_ty angleMargin, const T_ty magMargin) const;


//------------------------------------------------------------------------------
// Conversions.

    /// Convert this polar coordinate to a cartesian coordinate vector.
    void toVector2d(Vector2d<T_ty> & output) const;

    /// Convert this polar coordinate to a cartesian coordinate vector.
    Vector2d<T_ty> toVector2d() const;


//------------------------------------------------------------------------------
// Data.

    /// Angle of this coordinate (radians).
    /// In a cartesian XY plane, 0 radians points +X, half pi radians points +Y.
    T_ty angle;

    /// Magnitude of this coordinate (length of the vector).
    T_ty mag;
};

//--------------
} // math
} // ail
//--------------

#endif //ail_math_Polar_h

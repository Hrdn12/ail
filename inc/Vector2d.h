#ifndef avidmath_Vector2d_h
#define avidmath_Vector2d_h

/** \file Vector2d.h
    \brief Declares a 2d cartesian vector. See Vector2d.inl for implementation.

    Part of the avidmath library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include <string>

namespace avidmath
{
    // Forward declaration to the Polar coordinate class.
    template <typename T_ty> class Polar;

    /** A 2d cartesian vector class.
    Template parameter gives the underlying numerical type, typically float or double.
    */
    template <typename T_ty>
    class Vector2d
    {
    public:
    //------------------------------------------------------------------------------
    // Construction / destruction.

        /// Constructor - initialises everything to 0.
        Vector2d();

        /// Constructor - initialises each component directly.
        Vector2d(const T_ty tX, const T_ty tY);

        /// Copy constructor.
        Vector2d(const Vector2d<T_ty> & rhs);

        /// Convert from a polar coordinate into 2d cartesian vector.
        explicit Vector2d(const Polar<T_ty> & rhs);

        /// Destructor.
        ~Vector2d();


    //------------------------------------------------------------------------------
    // Operators.

        /// Copy assignment operator.
        Vector2d<T_ty> & operator = (const Vector2d<T_ty> & rhs);

        /// Equality test.
        bool operator == (const Vector2d<T_ty> & rhs) const;
        /// Inequality test.
        bool operator != (const Vector2d<T_ty> & rhs) const;

        /// Vector addition assignment
        Vector2d<T_ty> & operator += (const Vector2d<T_ty> & rhs);
        /// Vector subtraction assignment
        Vector2d<T_ty> & operator -= (const Vector2d<T_ty> & rhs);

        /// Scalar multiplication assignment.
        Vector2d<T_ty> & operator *= (const T_ty rhs);
        /// Scalar division assignment.
        Vector2d<T_ty> & operator /= (const T_ty rhs);

        /// Returns a copy of the vector with all components negated.
        Vector2d<T_ty> operator - () const;


    //------------------------------------------------------------------------------
    // Accessors / operations.

        /// Sets both components in one call.
        void set(const T_ty tX, const T_ty tY);

        /// Get the magnitude (length) of this vector
        T_ty getMagnitude() const;

        /// Get the squared magnitude of this vector
        /// This is much faster than getMagnitude() as it avoids a square root.
        /// This can be useful for some comparisons.
        T_ty getSqMagnitude() const;

        /// Normalise this vector in place (makes it a unit vector).
        void normalise();
        /// Get a normalised copy of this vector.
        Vector2d<T_ty> getNormalised() const;

        /// Get the right tangent of this vector
        Vector2d<T_ty> getRightTangent() const;
        /// Get the left tangent of this vector
        Vector2d<T_ty> getLeftTangent() const;

        /// Calculate the dot product of this vector with another.
        T_ty dot(const Vector2d<T_ty> & rhs) const;

        /// Get the amount by which this vector projects onto another.
        T_ty getScalarProjection(const Vector2d<T_ty> & rhs) const;

        /// Get a vector describing this vector's projection on another.
        Vector2d<T_ty> getVectorProjection(const Vector2d<T_ty> & rhs) const;

        /// Treating both vectors as positions, get the distance between this vector and another.
        /// Note that this relies on a square root. getSqDistance() is faster and may
        ///  be adequate for many purposes.
        T_ty getDistance(const Vector2d<T_ty> & other) const;

        /// Treating both vectors as positions, get the square of the distance between this vector and another.
        T_ty getSqDistance(const Vector2d<T_ty> & other) const;

        /// Check if this vector represents a position within a certain distance of another.
        /// The comparison uses Euclidean distance, making it more practical for most
        ///  purposes than isApproxEqual().
        bool isNear(const Vector2d<T_ty> & other, const T_ty dist) const;

        /// Check if this vector is approximately equal to another, within a given margin.
        /// This checks each component independently for approximate equality.
        /// The isNear() function may be more useful for most purposes.
        bool isApproxEqual(const Vector2d<T_ty> & other, const T_ty margin) const;


    //------------------------------------------------------------------------------
    // Conversions.

        /// Convert this cartesian coordinate to a polar coordinate.
        /// This will use the simplest possible representation of a polar angle,
        ///  i.e. the magnitude will be positive, and the angle will be positive and
        ///  less than 2 pi radians (a full circle).
        void toPolar(Polar<T_ty> & output) const;

        /// Convert this cartesian coordinate to a polar coordinate.
        /// This will use the simplest possible representation of a polar angle,
        ///  i.e. the magnitude will be positive, and the angle will be positive and
        ///  less than 2 pi radians (a full circle).
        Polar<T_ty> toPolar() const;


    //------------------------------------------------------------------------------
    // Data.

        /// X component of this vector.
        T_ty x;

        /// Y component of this vector.
        T_ty y;
    };

    // Note: Global operators declared/defined in Vector2d.inl

}//namespace avidmath

#endif //avidmath_Vector2d_h

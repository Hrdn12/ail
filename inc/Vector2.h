/** \file Vector2.h
    \brief Declares a 2d cartesian vector.

    Part of the avidmath library (avid-insight.co.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#ifndef avidmath_Vector2_h
#define avidmath_Vector2_h

#include <cmath>
#include <cassert>

namespace avidmath
{

    /** A 2d cartesian vector class.
    Template parameter gives the underlying numerical type, typically float or double.
    */
    template <typename T_ty>
    class Vector2
    {
    public:
        //------------------------------------------------------------------------------
        // Construction / destruction.

        /// Constructor - initialises everything to 0.
        Vector2();

        /// Constructor - initialises each component directly.
        Vector2(const T_ty tX, const T_ty tY);

        /// Copy constructor.
        Vector2(const Vector2<T_ty> & rhs);

        /// Destructor.
        ~Vector2();


        //------------------------------------------------------------------------------
        // Operators.

        /// Copy assignment operator.
        const Vector2<T_ty> & operator = (const Vector2<T_ty> & rhs);

        /// Equality test.
        bool operator == (const Vector2<T_ty> & rhs) const;
        /// Inequality test.
        bool operator != (const Vector2<T_ty> & rhs) const;

        /// Vector addition assignment
        const Vector2<T_ty> & operator += (const Vector2<T_ty> & rhs);
        /// Vector subtraction assignment
        const Vector2<T_ty> & operator -= (const Vector2<T_ty> & rhs);

        /// Scalar multiplication assignment.
        const Vector2<T_ty> & operator *= (const T_ty rhs);
        /// Scalar division assignment.
        const Vector2<T_ty> & operator /= (const T_ty rhs);

        /// Negation
        const Vector2<T_ty> operator - () const;


        //------------------------------------------------------------------------------
        // Accessors / operations.

        /// Sets both components in one call.
        void set(const T_ty tX, const T_ty tY);

        /// Get the manitude (length) of this vector
        const T_ty getMagnitude() const;

        /// Get the squared magnitude of this vector
        /// This is much faster than getMagnitude() as it avoids a square root.
        /// This can be useful for some comparisons.
        const T_ty getSqMagnitude() const;

        /// Normalise this vector in place (makes it a unit vector).
        void normalise();
        /// Get a normalised copy of this vector.
        const Vector2<T_ty> getNormalised() const;

        /// Get the right tangent of this vector
        const Vector2<T_ty> getRightTangent() const;
        /// Get the left tangent of this vector
        const Vector2<T_ty> getLeftTangent() const;

        /// Calculate the dot product of this vector with another.
        T_ty dot(const Vector2<T_ty> &rhs);

        /// Get the amount by which this vector projects onto another.
        T_ty getProjectionLength(const Vector2<T_ty> &rhs) const;

        /// Get a vector describing this vector's projection on another.
        const Vector2<T_ty> getProjectionVector(const Vector2<T_ty> &rhs) const;


        //------------------------------------------------------------------------------
        // Data.

        /// X component of this vector.
        T_ty x;

        /// Y component of this vector.
        T_ty y;
    };

    //------------------------------------------------------------------------------
    // Inline definitions.

    template <typename T_ty>
    Vector2<T_ty>::Vector2() : x(0), y(0)
    {
    }

    template <typename T_ty>
    Vector2<T_ty>::Vector2(const T_ty tX, const T_ty tY) : x(tX), y(tY)
    {
    }

    template <typename T_ty>
    Vector2<T_ty>::Vector2(const Vector2<T_ty> & rhs) : x(rhs.x), y(rhs.y)
    {
    }

    template <typename T_ty>
    Vector2<T_ty>::~Vector2()
    {
    }

    template <typename T_ty>
    const Vector2<T_ty> & Vector2<T_ty>::operator = (const Vector2<T_ty> & rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    template <typename T_ty>
    bool Vector2<T_ty>::operator == (const Vector2<T_ty> & rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }

    template <typename T_ty>
    bool Vector2<T_ty>::operator != (const Vector2<T_ty> & rhs) const
    {
        return !(x == rhs.x && y == rhs.y);
    }

    template <typename T_ty>
    const Vector2<T_ty> & Vector2<T_ty>::operator += (const Vector2<T_ty> & rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    template <typename T_ty>
    const Vector2<T_ty> & Vector2<T_ty>::operator -= (const Vector2<T_ty> & rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    template <typename T_ty>
    const Vector2<T_ty> & Vector2<T_ty>::operator *= (const T_ty rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    template <typename T_ty>
    const Vector2<T_ty> & Vector2<T_ty>::operator /= (const T_ty rhs)
    {
        assert(rhs != 0);
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }

    template <typename T_ty>
    const Vector2<T_ty> Vector2<T_ty>::operator - () const
    {
        return Vector2<T_ty>(-x, -y);
    }

    template <typename T_ty>
    void Vector2<T_ty>::set(const T_ty tX, const T_ty tY)
    {
        x = tX;
        y = tY;
    }

    template <typename T_ty>
    const T_ty Vector2<T_ty>::getMagnitude() const
    {
        return std::sqrt((x * x) + (y * y));
    }

    template <typename T_ty>
    const T_ty Vector2<T_ty>::getSqMagnitude() const
    {
        return (x*x) + (y*y);
    }

    template <typename T_ty>
    void Vector2<T_ty>::normalise()
    {
        const T_ty mag = getMagnitude();
        if (mag != 0) {
            x /= mag;
            y /= mag;
        }
    }

    template <typename T_ty>
    const Vector2<T_ty> Vector2<T_ty>::getNormalised() const
    {
        auto cpy = *this;
        cpy.normalise();
        return cpy;
    }

    template <typename T_ty>
    const Vector2<T_ty> Vector2<T_ty>::getRightTangent() const
    {
        return Vector2<T_ty>(y, -x);
    }

    template <typename T_ty>
    const Vector2<T_ty> Vector2<T_ty>::getLeftTangent() const
    {
        return Vector2<T_ty>(-y, x);
    }

    template <typename T_ty>
    T_ty Vector2<T_ty>::dot(const Vector2<T_ty> &rhs) const
    {
        return (x * rhs.x) + (y * rhs.y);
    }

    template <typename T_ty>
    T_ty Vector2<T_ty>::getProjectionLength(const Vector2<T_ty> &rhs) const
    {
        const T_ty rhsMag = rhs.getMagnitude();
        if (rhsMag == 0) return 0;
        return dot(rhs) / rhsMag;
    }

    template <typename T_ty>
    const Vector2<T_ty> Vector2<T_ty>::getProjectionVector(const Vector2<T_ty> &rhs) const
    {
        const T_ty rhsSqMag = rhs.getSqMagnitude();
        if (rhsSqMag == 0) return Vector2<T_ty>();
        return (dot(rhs) / rhsSqMag) * rhs;
    }

    //------------------------------------------------------------------------------
    // Global operators.

    /// Vector addition.	
	template <typename T_ty>
    const Vector2<T_ty> operator + (const Vector2<T_ty> & lhs, const Vector2<T_ty> & rhs)
    {
        Vector2<T_ty> ans(lhs);
        return ans += rhs;
    }

    /// Vector subtraction.
	template <typename T_ty>
    const Vector2<T_ty> operator - (const Vector2<T_ty> & lhs, const Vector2<T_ty> & rhs)
    {
        Vector2<T_ty> ans(lhs);
        return ans -= rhs;
    }
	
    /// Scalar multiplication.
	template <typename T_ty>
    const Vector2<T_ty> operator * (const Vector2<T_ty> & lhs, const T_ty & rhs)
    {
        Vector2<T_ty> ans(lhs);
        return ans *= rhs;
    }

    /// Scalar multiplication.
	template <typename T_ty>
    const Vector2<T_ty> operator * (const T_ty & lhs, const Vector2<T_ty> & rhs)
    {
        Vector2<T_ty> ans(rhs);
        return ans *= lhs;
    }

    /// Scalar division.
	template <typename T_ty>
    const Vector2<T_ty> operator / (const Vector2<T_ty> & lhs, const T_ty & rhs)
    {
        Vector2<T_ty> ans(lhs);
        return ans /= rhs;
    }

    /// Scalar division.
	template <typename T_ty>
    const Vector2<T_ty> operator / (const T_ty & lhs, const Vector2<T_ty> & rhs)
    {
        Vector2<T_ty> ans(rhs);
        ans.x = lhs / ans.x;
        ans.y = lhs / ans.y;
        return ans;
    }

}

#endif //avidmath_Vector2_h

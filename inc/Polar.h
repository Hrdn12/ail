/** \file Polar.h
    \brief Declares a 2d polar vector (angle / magnitude).

    Part of the avidmath library (avid-insight.co.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#ifndef avidmath_polar_h
#define avidmath_polar_h

#include <cmath>
#include <cassert>
#include "Vector2.h"

namespace avidmath
{
    /// Declares a 2d polar vector (angle / magnitude).
    /// In an XY cartesian plane, 0 radians/degrees points +X, half pi radians (90 degrees) points +Y.
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

        /// Copy constructor.
        Polar(const Polar<T_ty> & rhs);
        
        /// Convert a cartesian coordinate into polar.
        explicit Polar(const Vector2<T_ty> &rhs);

        /// Destructor.
        ~Polar();


    //------------------------------------------------------------------------------
    // Operators.

        /// Assignment operator.
        const Polar<T_ty> & operator = (const Polar<T_ty> & rhs);
        
        /// Equality operator.
        bool operator == (const Polar<T_ty> & rhs) const;
        
        /// Inequality operator.
        bool operator != (const Polar<T_ty> & rhs) const;

        /// Negation operator.
        /// This inverts the magnitude but does not affect the angle.
        const Polar<T_ty> operator - ();

        
    //------------------------------------------------------------------------------
    // Accessors / operations.
    
        /// Set the angle and magnitude in one call.
        void set(const T_ty angle, const T_ty mag);
        
        /// Convert this polar coordinate to a cartesian coordinate vector.
        const Vector2<T_ty> toCartesian() const;
        
        /// Convert a cartesian vector into polar and store it.
        void fromCartesian(const Vector2<T_ty> &crt);
        
        /// Simplify this coordinate in-place (modifies the current object).
        /// This doesn't change the direction/distance represented by the vector,
        ///  but it ensures the angle is between 0 and two pi, and that the magnitude
        ///  is positive.
        void simplify();
        
        /// Get a simplified copy of this vector.
        /// The returned polar vector will still represent the same direction/distance
        ///  as this object, but the angle will be between 0 and two pi, and the
        ///  magnitude will be positive.
        const Polar<T_ty> getSimplified() const;
            

    //------------------------------------------------------------------------------
    // Data.

        /// Angle of this coordinate (radians).
        /// In a cartesian XY plane, 0 radians points +X, half pi radians points +Y.
        T_ty angle;
        
        /// Magnitude of this coordinate (length of the vector).
        T_ty mag;
    };
    
//------------------------------------------------------------------------------
// Inline definitions.

    template <typename T_ty>
    Polar<T_ty>::Polar() : angle(0), mag(0)
    {
    }

    template <typename T_ty>
    Polar<T_ty>::Polar(const T_ty angle, const T_ty mag) : angle(angle), mag(mag)
    {
    }

    template <typename T_ty>
    Polar<T_ty>::Polar(const Polar<T_ty> & rhs) : angle(rhs.angle), mag(rhs.mag)
    {
    }
    
    template <typename T_ty>
    Polar<T_ty>::Polar(const Vector2<T_ty> &rhs) : Polar()
    {
        fromCartesian(rhs);
    }

    template <typename T_ty>
    Polar<T_ty>::~Polar()
    {
    }

    template <typename T_ty>
    const Polar<T_ty> & Polar<T_ty>::operator = (const Polar<T_ty> & rhs)
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
        return !(angel == rhs.angle && mag == rhs.mag);
    }

    template <typename T_ty>
    const Polar<T_ty> Polar<T_ty>::operator - ()
    {
        return Polar<T_ty>(angle, -mag);
    }

    template <typename T_ty>
    void Polar<T_ty>::set(const T_ty angle, const T_ty mag)
    {
        this->angle = angle;
        this->mag = mag;
    }
    
    template <typename T_ty>
    const Vector2<T_ty> Polar<T_ty>::toCartesian() const
    {
        return Vector2<T_ty>(
            mag * std::cos(angle),
            mag * std::sin(angle)
        );
    }
    
    template <typename T_ty>
    void Polar<T_ty>::fromCartesian(const Vector2<T_ty> &crt)
    {
        assert(0); // not implemented yet!
    }
    
    template <typename T_ty>
    void Polar<T_ty>::simplify()
    {
        assert(0); // not implemented yet!
    }
    
    template <typename T_ty>
    const Polar<T_ty> Polar<T_ty>::getSimplified() const
    {
        Polar<T_ty> temp(*this);
        temp.simplify();
        return temp;
    }
}

#endif //avidmath_polar_h

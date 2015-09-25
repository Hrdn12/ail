#ifndef avidmath_Polar_h
#define avidmath_Polar_h

/** \file Polar.h
    \brief Declares a 2d polar vector (angle / magnitude). See Polar.inl for implementation.

    Part of the avidmath library (avid-insight.co.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

namespace avidmath
{
    // Forward declaration to the 2d cartesian vector class. See Vector2.h
    template <typename T_ty> class Vector2d;

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
        explicit Polar(const Vector2d<T_ty> &rhs);

        /// Destructor.
        ~Polar();


    //------------------------------------------------------------------------------
    // Operators.

        /// Assignment operator.
        Polar<T_ty> & operator = (const Polar<T_ty> & rhs);
        
        /// Equality operator.
        bool operator == (const Polar<T_ty> & rhs) const;
        
        /// Inequality operator.
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
}

#endif //avidmath_Polar_h

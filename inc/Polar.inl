#ifndef avidmath_Polar_inl
#define avidmath_Polar_inl

/** \file Polar.inl
    \brief Implementation for 2d polar vector (angle / magnitude).

    Part of the avidmath library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/



#include <cmath>
#include <cassert>

#include "Polar.h"
#include "Vector2d.h"
#include "Utils.h"

namespace avidmath
{
    //------------------------------------------------------------------------------
    // Construction / destruction.

    template <typename T_ty>
    Polar<T_ty>::Polar() :
        angle(0), mag(0)
    {
    }

    template <typename T_ty>
    Polar<T_ty>::Polar(const T_ty angle, const T_ty mag) :
        angle(angle), mag(mag)
    {
    }

    template <typename T_ty>
    Polar<T_ty>::Polar(const Polar<T_ty> & rhs) :
        angle(rhs.angle), mag(rhs.mag)
    {
    }
    
    template <typename T_ty>
    Polar<T_ty>::Polar(const Vector2d<T_ty> & rhs) :
        Polar()
    {
        rhs.toPolar(*this);
    }

    template <typename T_ty>
    Polar<T_ty>::~Polar()
    {
    }

    //------------------------------------------------------------------------------
    // Operators.

    template <typename T_ty>
    Polar<T_ty> & Polar<T_ty>::operator = (const Polar<T_ty> & rhs)
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
    Polar<T_ty> Polar<T_ty>::operator - () const
    {
        return Polar<T_ty>(angle, -mag);
    }

    //------------------------------------------------------------------------------
    // Accessors / operations.

    template <typename T_ty>
    void Polar<T_ty>::set(const T_ty angle, const T_ty mag)
    {
        this->angle = angle;
        this->mag = mag;
    }
    
    template <typename T_ty>
    void Polar<T_ty>::simplify()
    {
        // Make sure the magnitude is positive.
        if (mag < T_ty(0)) {
            angle += constants::pi<T_ty>();
            mag *= T_ty(-1);
        }

        // Make sure the angle is positive and is less than a full circle.
        angle = wrap(angle, T_ty(0), constants::pi<T_ty>() * T_ty(2));
    }
    
    template <typename T_ty>
    Polar<T_ty> Polar<T_ty>::getSimplified() const
    {
        Polar<T_ty> output(*this);
        output.simplify();
        return output;
    }

    //------------------------------------------------------------------------------
    // Conversions.

    template <typename T_ty>
    void Polar<T_ty>::toVector2d(Vector2d<T_ty> & output) const
    {
        output.x = mag * std::cos(angle);
        output.y = mag * std::sin(angle);
    }

    template <typename T_ty>
    Vector2d<T_ty> Polar<T_ty>::toVector2d() const
    {
        Vector2d<T_ty> output;
        toVector2d(output);
        return output;
    }
}

#endif //avidmath_Polar_inl

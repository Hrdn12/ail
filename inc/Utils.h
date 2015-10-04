/** \file Utils.h
    \brief Defines various common maths utilities.

    NOTE: This requires support for C++11 constexpr.
    If you are using Visual Studio, it won't work prior to VS2015.
    
    Part of the avidmath library (avid-insight.co.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#ifndef avidmath_Utils_h
#define avidmath_Utils_h

#include <cmath>
#include <cassert>
#include <type_traits>
#include "Constants.h"

namespace avidmath {
    //-------------------------------------------------------------------------
    // Angle conversions.

    /// Convert an angle from degrees to radians.
    template <typename T_ty>
    inline constexpr T_ty degToRad(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return (angle * constants::pi<T_ty>()) / T_ty(180);
    }
    
    /// Convert an angle from degrees to gradians.
    /// This involves division by 
    template <typename T_ty>
    inline constexpr T_ty degToGrad(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return (angle / T_ty(0.9));
    }
    
    /// Convert an angle from degrees to full turns.
    template <typename T_ty>
    inline constexpr T_ty degToTurn(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return angle / T_ty(360);
    }
    
    
    /// Convert an angle from radians to degrees.
    template <typename T_ty>
    inline constexpr T_ty radToDeg(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return (angle * T_ty(180)) / constants::pi<T_ty>();
    }
    
    /// Convert an angle from radians to gradians.
    template <typename T_ty>
    inline constexpr T_ty radToGrad(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return (angle * T_ty(200)) / constants::pi<T_ty>();
    }
    
    /// Convert an angle from radians to full turns.
    template <typename T_ty>
    inline constexpr T_ty radToTurn(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return angle / (T_ty(2) * constants::pi<T_ty>());
    }
    
    
    /// Convert an angle from gradians to degrees.
    template <typename T_ty>
    inline constexpr T_ty gradToDeg(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return angle * T_ty(0.9);
    }
    
    /// Convert an angle from gradians to radians.
    template <typename T_ty>
    inline constexpr T_ty gradToRad(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return (angle * constants::pi<T_ty>()) / T_ty(200);
    }
    
    /// Convert an angle from gradians to full turns.
    template <typename T_ty>
    inline constexpr T_ty gradToTurn(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return angle / T_ty(400);
    }
    
    
    /// Convert an angle from full turns to degrees.
    template <typename T_ty>
    inline constexpr T_ty turnToDeg(const T_ty angle) { return angle * T_ty(360); }
    
    /// Convert an angle from full turns to radians
    template <typename T_ty>
    inline constexpr T_ty turnToRad(const T_ty angle)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return angle * T_ty(2.0) * constants::pi<T_ty>();
    }
    
    /// Convert an angle from full turns to gradians.
    template <typename T_ty>
    inline constexpr T_ty turnToGrad(const T_ty angle) { return angle * T_ty(400); }
    
    
    //-------------------------------------------------------------------------
    // Comparisons.
    
    /// Check if two values are approximately equal, plus/minus the given margin.
    /// Assumes margin is positive.
    template <typename T_ty>
    inline constexpr bool isApproxEqual(const T_ty lhs, const T_ty rhs, const T_ty margin)
    {
        assert(margin >= 0);
        return diff(lhs, rhs) <= margin;
    }

    /// Check if a value is approximately zero, plus/minus the given margin.
    /// Assumes margin is positive.
    template <typename T_ty>
    inline constexpr bool isApproxZero(const T_ty val, const T_ty margin)
    {
        assert(margin >= 0);
        return (val >= 0 ? val : -val) <= margin;
    }
    
    /// Check if a value is within the range defined by rangeMin and rangeMax.
    /// It doesn't matter which range value is bigger.
    template <typename T_ty>
    inline constexpr bool isInRange(const T_ty val, const T_ty range1, const T_ty range2)
    {
        return
            ((range1 <= val) && (val <= range2)) ||
            ((range2 <= val) && (val <= range1));
    }
    
    
    //-------------------------------------------------------------------------
    // Numerical utilities.

    /// Get the difference between two values. Result is always positive or zero. Handles unsigned types safely.
    template <typename T_ty>
    inline constexpr T_ty diff(const T_ty lhs, const T_ty rhs)
    {
        return (lhs >= rhs) ?
            lhs - rhs :
            rhs - lhs;
    }

    /// Clamp a value to the range defined by rangeMin and rangeMax.
    /// It doesn't matter which range value is bigger.
    template <typename T_ty>
    inline constexpr T_ty clamp(const T_ty val, const T_ty range1, const T_ty range2)
    {
        return (range1 < range2) ?
            ((val < range1) ? range1 : ((val > range2) ? range2 : val)) :
            ((val > range1) ? range1 : ((val < range2) ? range2 : val));
    }

    /// Linearly interpolate between start and end by the given amount. This will extrapolate beyond the original range if necessary.
    template <typename T_ty>
    inline constexpr T_ty lerp(const T_ty amount, const T_ty start, const T_ty end)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return start + (amount * (end - start));
    }

    /// Linearly interpolate between start and end by the given amount, clamping the result to the original range.
    template <typename T_ty>
    inline constexpr T_ty lerpClamp(const T_ty amount, const T_ty start, const T_ty end)
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return clamp(lerp(amount, start, end), start, end);
    }

    // TODO: wrap to range (will need separate implementation for integer vs floating point?)

}//namespace avidmath

#endif //avidmath_Utils_h

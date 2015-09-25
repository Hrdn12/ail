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
#include "Constants.h"

namespace avidmath {
    //-------------------------------------------------------------------------
    // Angle conversions.

    /// Convert an angle from degrees to radians.
    template <typename T_ty>
    inline constexpr T_ty degToRad(const T_ty angle) { return angle * (constants::pi<T_ty>() / T_ty(180)); }
    
    /// Convert an angle from degrees to gradians.
    template <typename T_ty>
    inline constexpr T_ty degToGrad(const T_ty angle) { return angle / T_ty(0.9); }
    
    /// Convert an angle from degrees to full circles.
    template <typename T_ty>
    inline constexpr T_ty degToCir(const T_ty angle) { return angle / T_ty(360); }
    
    
    /// Convert an angle from radians to degrees.
    template <typename T_ty>
    inline constexpr T_ty radToDeg(const T_ty angle) { return angle * (T_ty(180) / constants::pi<T_ty>()); }
    
    /// Convert an angle from radians to gradians.
    template <typename T_ty>
    inline constexpr T_ty radToGrad(const T_ty angle) { return angle * (T_ty(200) / constants::pi<T_ty>()); }
    
    /// Convert an angle from radians to full circles.
    template <typename T_ty>
    inline constexpr T_ty radToCir(const T_ty angle) { return angle / (T_ty(2) * constants:pi<T_ty>()); }
    
    
    /// Convert an angle from gradians to degrees.
    template <typename T_ty>
    inline constexpr T_ty gradToDeg(const T_ty angle) { return angle * T_ty(0.9); }
    
    /// Convert an angle from gradians to radians.
    template <typename T_ty>
    inline constexpr T_ty gradToRad(const T_ty angle) { return angle * (constants::pi<T_ty>() / T_ty(200)); }
    
    /// Convert an angle from gradians to full circles.
    template <typename T_ty>
    inline constexpr T_ty gradToCir(const T_ty angle) { return angle / T_ty(400); }
    
    
    /// Convert an angle from full circles to degrees.
    template <typename T_ty>
    inline constexpr T_ty cirToDeg(const T_ty angle) { return angle * T_ty(360); }
    
    /// Convert an angle from full circles to radians
    template <typename T_ty>
    inline constexpr T_ty cirToRad(const T_ty angle) { return angle * T_ty(2.0) * constants::pi<T_ty>(); }
    
    /// Convert an angle from full circles to gradians.
    template <typename T_ty>
    inline constexpr T_ty cirToGrad(const T_ty angle) { return angle * T_ty(400); }
    
    
    //-------------------------------------------------------------------------
    // Comparisons.
    
    /// Check if two values are approximately equal, plus/minus the given margin.
    /// Assumes margin is positive.
    template <typename T_ty>
    inline constexpr bool isApproxEqual(const T_ty lhs, const T_ty rhs, const T_ty margin)
    {
        return diff(lhs, rhs) <= margin;
    }

    /// Check if a value is approximately zero, plus/minus the given margin.
    /// Assumes margin is positive.
    template <typename T_ty>
    inline constexpr bool isApproxZero(const T_ty val, const T_ty margin)
    {
        return std::abs(val) <= margin;
    }
    
    /// Check if a value is within the range defined by rangeMin and rangeMax.
    /// Assumes rangeMin <= rangeMax.
    template <typename T_ty>
    inline constexpr bool isInRange(const T_ty val, const T_ty rangeMin, const T_ty rangeMax)
    {
        return (rangeMin <= val) && (val <= rangeMax);
    }
    
    
    //-------------------------------------------------------------------------
    // Numerical utilities.
    
    /// Get the difference between two values. Result is always positive or zero. Handles unsigned types safely.
    template <typename T_ty>
    inline constexpr T_ty diff(const T_ty lhs, const T_ty rhs)
    {
        if (lhs >= rhs) return lhs - rhs;
        return rhs - lhs;
    }

    /// Clamp a value to the range defined by rangeMin and rangeMax.
    /// Assumes rangeMin <= rangeMax.
    template <typename T_ty>
    inline constexpr T_ty clamp(const T_ty val, const T_ty rangeMin, const T_ty rangeMax)
    {
        if (val < rangeMin) return rangeMin;
        if (val > rangeMax) return rangeMax;
        return val;
    }

    // TODO: wrap to range
    
    // TODO: clamp to power

    /// Linearly interpolate between two values by the given amount. This will extrapolate beyond the original range if necessary.
    template <typename T_ty>
    inline constexpr T_ty lerp(const T_ty amount, const T_ty rangeMin, const T_ty rangeMax)
    {
        return rangeMin + (amount * (rangeMax - rangeMin));
    }

    /// Linearly interpolate between two values by the given amount, clamping the result to the original range.
    template <typename T_ty>
    inline constexpr T_ty lerpClamp(const T_ty amount, const T_ty rangeMin, const T_ty rangeMax)
    {
        return clamp(lerp(amount, rangeMin, rangeMax), rangeMin, rangeMax);
    }
    

}//namespace avidmath

#endif //avidmath_Utils_h

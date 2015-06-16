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

#include "Constants.h"

namespace avidmath {
    //-------------------------------------------------------------------------
    // Angle conversions.

    /// Convert an angle from degrees to radians.
    template <typename T_ty>
    inline constexpr T_ty degToRad(T_ty angle) { return angle * (constants::pi<T_ty>() / T_ty(180)); }
    
    /// Convert an angle from degrees to gradians.
    template <typename T_ty>
    inline constexpr T_ty degToGrad(T_ty angle) { return angle / T_ty(0.9); }
    
    /// Convert an angle from degrees to full circles.
    template <typename T_ty>
    inline constexpr T_ty degToCir(T_ty angle) { return angle / T_ty(360); }
    
    
    /// Convert an angle from radians to degrees.
    template <typename T_ty>
    inline constexpr T_ty radToDeg(T_ty angle) { return angle * (T_ty(180) / constants::pi<T_ty>()); }
    
    /// Convert an angle from radians to gradians.
    template <typename T_ty>
    inline constexpr T_ty radToGrad(T_ty angle) { return angle * (T_ty(200) / constants::pi<T_ty>()); }
    
    /// Convert an angle from radians to full circles.
    template <typename T_ty>
    inline constexpr T_ty radToCir(T_ty angle) { return angle / (T_ty(2) * constants:pi<T_ty>()); }
    
    
    /// Convert an angle from gradians to degrees.
    template <typename T_ty>
    inline constexpr T_ty gradToDeg(T_ty angle) { return angle * T_ty(0.9); }
    
    /// Convert an angle from gradians to radians.
    template <typename T_ty>
    inline constexpr T_ty gradToRad(T_ty angle) { return angle * (constants::pi<T_ty>() / T_ty(200)); }
    
    /// Convert an angle from gradians to full circles.
    template <typename T_ty>
    inline constexpr T_ty gradToCir(T_ty angle) { return angle / T_ty(400); }
    
    
    /// Convert an angle from full circles to degrees.
    template <typename T_ty>
    inline constexpr T_ty cirToDeg(T_ty angle) { return angle * T_ty(360); }
    
    /// Convert an angle from full circles to radians
    template <typename T_ty>
    inline constexpr T_ty cirToRad(T_ty angle) { return angle * T_ty(2.0) * constants::pi<T_ty>(); }
    
    /// Convert an angle from full circles to gradians.
    template <typename T_ty>
    inline constexpr T_ty cirToGrad(T_ty angle) { return angle * T_ty(400); }
    
    
    //-------------------------------------------------------------------------
    // Comparisons.
    
    // approx zero
    // approx equal
    // is in range
    
    
    //-------------------------------------------------------------------------
    // Numerical utilities.
    
    // clamp to range
    // wrap to range
    // clamp to power
    // interpolate
    

}//namespace avidmath

#endif //avidmath_Utils_h

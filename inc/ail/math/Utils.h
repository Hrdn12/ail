/** \file Utils.h
    \brief Defines various common maths utilities.

    NOTE: This requires support for C++11 constexpr.
    If you are using Visual Studio, it won't work prior to VS2015.
    
    Part of ail, the Avid Insight Library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#ifndef ail_math_Utils_h
#define ail_math_Utils_h

#include <cmath>
#include <cassert>
#include <type_traits>
#include "Constants.h"

//--------------
namespace ail {
namespace math {
//--------------

//-------------------------------------------------------------------------
// Angle conversions.

/// Convert an angle from degrees to radians. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    degToRad(const T_ty angle)
{
    return (angle * pi<T_ty>()) / T_ty(180);
}
    
/// Convert an angle from degrees to gradians. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    degToGrad(const T_ty angle)
{
    return (angle / T_ty(0.9));
}
    
/// Convert an angle from degrees to full turns. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    degToTurn(const T_ty angle)
{
    return angle / T_ty(360);
}
    
    
/// Convert an angle from radians to degrees. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    radToDeg(const T_ty angle)
{
    return (angle * T_ty(180)) / pi<T_ty>();
}
    
/// Convert an angle from radians to gradians. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    radToGrad(const T_ty angle)
{
    return (angle * T_ty(200)) / pi<T_ty>();
}
    
/// Convert an angle from radians to full turns. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    radToTurn(const T_ty angle)
{
    return angle / (T_ty(2) * pi<T_ty>());
}
    
    
/// Convert an angle from gradians to degrees. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    gradToDeg(const T_ty angle)
{
    return angle * T_ty(0.9);
}
    
/// Convert an angle from gradians to radians. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    gradToRad(const T_ty angle)
{
    return (angle * pi<T_ty>()) / T_ty(200);
}
    
/// Convert an angle from gradians to full turns. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    gradToTurn(const T_ty angle)
{
    return angle / T_ty(400);
}
    
    
/// Convert an angle from full turns to degrees.
template <typename T_ty>
inline constexpr T_ty
    turnToDeg(const T_ty angle)
{
    return angle * T_ty(360);
}
    
/// Convert an angle from full turns to radians. Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    turnToRad(const T_ty angle)
{
    return angle * T_ty(2.0) * pi<T_ty>();
}
    
/// Convert an angle from full turns to gradians.
template <typename T_ty>
inline constexpr T_ty
    turnToGrad(const T_ty angle)
{
    return angle * T_ty(400);
}
    
    
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
/// Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    lerp(const T_ty amount, const T_ty start, const T_ty end)
{
    return start + (amount * (end - start));
}

/// Linearly interpolate between start and end by the given amount, clamping the result to the original range.
/// Only valid for floating point types.
template <typename T_ty>
inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty>
    lerpClamp(const T_ty amount, const T_ty start, const T_ty end)
{
    return clamp(lerp(amount, start, end), start, end);
}

/// Wrap a value round to fit within the given range.
/// The wrapping range will be inclusive of rangeMin and exclusive of rangeMax.
/// If rangeMin > rangeMax, they will be swapped.
/// This is useful e.g. for wrapping an angle to the range 0 <= angle < 360 degrees.
/// If rangeMin == rangeMax then rangeMin will be returned.
template <typename T_ty>
inline T_ty wrap(const T_ty val, T_ty rangeMin, T_ty rangeMax)
{
    if (rangeMin == rangeMax) return rangeMin;
    if (rangeMin > rangeMax) std::swap(rangeMin, rangeMax);
    // Avoid calculations if they aren't necessary:
    if (val >= rangeMin && val < rangeMax) return val;

    const auto rem = tmod<T_ty>::mod(val - rangeMin, rangeMax - rangeMin);
    if (rem >= 0) return rem + rangeMin;
    return rem + rangeMax;
}

//--------------
} // math
} // ail
//--------------

#endif //ail_math_Utils_h

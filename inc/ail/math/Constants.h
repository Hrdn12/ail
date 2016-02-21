#ifndef ail_math_Constants_h
#define ail_math_Constants_h

/** \file Constants.h
\brief Defines various mathematical constants.

NOTE: This requires support for C++11 constexpr.
If you are using Visual Studio, it won't work prior to VS2015.

Part of ail, the Avid Insight Library (avidinsight.uk/ail).
Copyright (C) 2015-16 Peter R. Bloomfield.
Released open source under the MIT licence.
*/

#include <cmath>
#include <type_traits>

//--------------
namespace ail {
namespace math {
//--------------

/// Get the value of pi.
/// Template parameter is required to specify the return type.
/// Example:  float val = pi<float>();
/// Only allows floating point types (e.g. float and double). Compilation will fail for any other type.
template <typename T_ty>
inline constexpr typename std::enable_if<std::is_floating_point<T_ty>::value, T_ty>::type pi()
{
    return T_ty(3.141592653589793);
}

//--------------
} // math
} // ail
//--------------


#endif //ail_math_Constants_h

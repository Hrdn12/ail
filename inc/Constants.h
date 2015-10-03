/** \file Constants.h
    \brief Defines various mathematical constants.

    NOTE: This requires support for C++11 constexpr.
    If you are using Visual Studio, it won't work prior to VS2015.
    
    Part of the avidmath library (avid-insight.co.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#ifndef avidmath_Constants_h
#define avidmath_Constants_h

#include <cmath>
#include <type_traits>

namespace avidmath {
namespace constants {
    
    /// Get the value of pi.
    /// Template parameter is required to specify the return type.
    /// Example:  float val = pi<float>();
    template <typename T_ty>
    inline constexpr T_ty pi()
    {
        static_assert(!std::is_integral<T_ty>::value, "This function won't do anything useful with an integer. Use floating point instead.");
        return T_ty(3.141592653589793);
    }

}//namespace constants
}//namespace avidmath


#endif //avidmath_Constants_h

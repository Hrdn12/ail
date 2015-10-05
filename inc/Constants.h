/** \file Constants.h
    \brief Defines various mathematical constants.

    NOTE: This requires support for C++11 constexpr.
    If you are using Visual Studio, it won't work prior to VS2015.
    
    Part of the avidmath library (avidinsight.uk).
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
    /// Only allows floating point types (e.g. float and double). Compilation will fail for any other type.
    template <typename T_ty>
    inline constexpr typename std::enable_if_t<std::is_floating_point<T_ty>::value, T_ty> pi()
    {
        return T_ty(3.141592653589793);
    }

}//namespace constants
}//namespace avidmath


#endif //avidmath_Constants_h

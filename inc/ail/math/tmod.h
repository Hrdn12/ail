#ifndef ail_math_tmod_h
#define ail_math_tmod_h

/** \file tmod.h
    \brief Provides a template for calling a suitable integer or floating point modulus operation. (Intended for internal use by the library.)

    Part of ail, the Avid Insight Library (avidinsight.uk).
    Copyright (C) 2015 Peter R. Bloomfield.
    Released open source under the MIT licence.
*/

#include <type_traits>
#include <cmath>

//--------------
namespace ail {
namespace math {
//--------------
    
/// Templated modulus operation structure.
/// This structure will provide a suitable modulus operation for the given arithmetic type T_ty.
/// The T_isFP template parameter should generally be left at its default value.
/// Integers will use the modulus operator (%). Floating point will use std::fmod.
/// Note that this is an empty generic template. The actual functionality is provided in specialisations below.
/// Example usage: tmod<int>::mod(10, 12)
template <typename T_ty, bool T_isFP = std::is_floating_point<T_ty>::value>
struct tmod;

/// A floating-point specialisation of the template modulus operation structure.
/// Example usage: tmod<float>::mod(24.5f, 19.9f)
template <typename T_ty>
struct tmod<T_ty, true> final
{
    /// Pure virtual to prevent instantiation.
    virtual ~tmod() = 0;

    /// The modulus operation for this structure's type.
    static inline T_ty mod(const T_ty numer, const T_ty denom)
    {
        return std::fmod(numer, denom);
    }
};

/// A floating-point specialisation of the template modulus operation structure.
/// Example usage: tmod<int>::mod(10, 12)
template <typename T_ty>
struct tmod<T_ty, false>
{
    /// Pure virtual to prevent instantiation.
    virtual ~tmod() = 0;

    /// The modulus operation for this structure's type.
    static inline T_ty mod(const T_ty numer, const T_ty denom)
    {
        return numer % denom;
    }
};

//--------------
} // math
} // ail
//--------------

#endif //ail_math_tmod_h

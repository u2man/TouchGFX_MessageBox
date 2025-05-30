/******************************************************************************
* Copyright (c) 2018(-2025) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.25.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

/**
 * @file common/Meta.hpp
 *
 * Declares the touchgfx::meta namespace.
 */
#ifndef TOUCHGFX_META_HPP
#define TOUCHGFX_META_HPP

namespace touchgfx
{
/**
 * Template meta-programming tools are grouped in this namespace
 */
namespace meta
{
/** Nil-type, indicates the end of a TypeList. */
struct Nil
{
};

/**
 * TypeList, used for generating compile-time lists of types.
 *
 * @tparam First Type of the first.
 * @tparam Next  Type of the next.
 */
template <typename First, typename Next>
struct TypeList
{
    typedef First first; ///< The first element in the TypeList
    typedef Next next;   ///< Remainder of the TypeList
};

/**
 * Meta-function, selects the "maximum" type, i.e. the largest type.
 *
 * @tparam T1      Generic type parameter.
 * @tparam T2      Generic type parameter.
 * @tparam choose1 True if sizeof(T1) is larger than sizeof(T2).
 * @param  parameter1 The first parameter.
 */
template <typename T1, typename T2, bool choose1 = (sizeof(T1) > sizeof(T2))>
struct type_max
{
    typedef T1 type; ///< The resulting type (default case: sizeof(T1)>sizeof(T2))
};

/**
 * Specialization for the case where sizeof(T2) >= sizeof(T1).
 *
 * @tparam T1 Generic type parameter.
 * @tparam T2 Generic type parameter.
 */
template <typename T1, typename T2>
struct type_max<T1, T2, false>
{
    typedef T2 type; ///< The resulting type (default case: sizeof(T2)>=sizeof(T1))
};

/**
 * Meta-function signature, selects maximum type from TypeList.
 *
 * @tparam T Generic type parameter.
 */
template <typename T>
struct select_type_maxsize;

/**
 * Specialization to dive into the list (inherits result from type_max).
 *
 * @tparam First Type of the first.
 * @tparam Next  Type of the next.
 */
template <typename First, typename Next>
struct select_type_maxsize<TypeList<First, Next> > : public type_max<First, typename select_type_maxsize<Next>::type>
{
};

/**
 * Specialization for loop termination (when type Nil encountered).
 *
 * @tparam First Type of the first.
 */
template <typename First>
struct select_type_maxsize<TypeList<First, Nil> >
{
    typedef First type;
};

/**
 * Meta-function signature, joins typelist with type (or another typelist).
 *
 * @tparam TList Type of the list.
 * @tparam T     Generic type parameter.
 */
template <typename TList, typename T>
struct list_join;

/** Specialization for termination. */
template <>
struct list_join<Nil, Nil>
{
    typedef Nil result;
};

/**
 * Specialization for "end-of-LHS", with RHS as type.
 *
 * @tparam T Generic type parameter.
 */
template <typename T>
struct list_join<Nil, T>
{
    typedef TypeList<T, Nil> result;
};

/**
 * Specialization for "end-of-LHS", with RHS as a TypeList.
 *
 * @tparam First Type of the first.
 * @tparam Next  Type of the next.
 */
template <typename First, typename Next>
struct list_join<Nil, TypeList<First, Next> >
{
    typedef TypeList<First, Next> result;
};

/**
 * Recursively joins a typelist (LHS) with a type or a type-list (RHS).
 *
 * @tparam First Type of the first.
 * @tparam Next  Type of the next.
 * @tparam T     Generic type parameter.
 */
template <typename First, typename Next, typename T>
struct list_join<TypeList<First, Next>, T>
{
    typedef TypeList<First, typename list_join<Next, T>::result> result;
};

} // namespace meta

} // namespace touchgfx

#endif // TOUCHGFX_META_HPP

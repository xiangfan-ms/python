//  (C) Copyright David Abrahams 2000. Permission to copy, use, modify, sell and
//  distribute this software is granted provided this copyright notice appears
//  in all copies. This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.
//
//  The author gratefully acknowleges the support of Dragon Systems, Inc., in
//  producing this work.
//
//  This file automatically generated by gen_signatures.py for 5 arguments.
#ifndef SIGNATURES_DWA050900_H_
# define SIGNATURES_DWA050900_H_

# include "pyconfig.h"

namespace py { 

namespace detail {
// A stand-in for the built-in void. This one can be passed to functions and
// (under MSVC, which has a bug, be used as a default template type parameter).
struct Void {};
}

// An envelope in which type information can be delivered for the purposes
// of selecting an overloaded from_python() function. This is needed to work
// around MSVC's lack of partial specialiation/ordering. Where normally we'd
// want to form a function call like void f<const T&>(), We instead pass
// Type<const T&> as one of the function parameters to select a particular
// overload.
//
// The Id typedef helps us deal with the lack of partial ordering by generating
// unique types for constructor signatures. In general, Type<T>::Id is Type<T>,
// but Type<Void>::Id is just Void.
template <class T>
struct Type
{
    typedef Type Id;
};

template <>
struct Type<py::detail::Void>
{
    typedef py::detail::Void Id;
};

namespace detail {
// These basically encapsulate a chain of types, , used to make the syntax of
// add(Constructor<T1, ...>()) work. We need to produce a unique type for each number
// of non-default parameters to Constructor<>.  Q: why not use a recursive
// formulation for infinite extensibility? A: MSVC6 seems to choke on constructs
// that involve recursive template nesting.
//
// Signature chaining
template <class T1, class T2, class T3, class T4, class T5>
struct Signature5 {};

template <class T1, class T2, class T3, class T4>
struct Signature4 {};

template <class T1, class T2, class T3, class T4, class X>
inline Signature5<X, T1, T2, T3, T4> prepend(Type<X>, Signature4<T1, T2, T3, T4>)
    { return Signature5<X, T1, T2, T3, T4>(); }

template <class T1, class T2, class T3>
struct Signature3 {};

template <class T1, class T2, class T3, class X>
inline Signature4<X, T1, T2, T3> prepend(Type<X>, Signature3<T1, T2, T3>)
    { return Signature4<X, T1, T2, T3>(); }

template <class T1, class T2>
struct Signature2 {};

template <class T1, class T2, class X>
inline Signature3<X, T1, T2> prepend(Type<X>, Signature2<T1, T2>)
    { return Signature3<X, T1, T2>(); }

template <class T1>
struct Signature1 {};

template <class T1, class X>
inline Signature2<X, T1> prepend(Type<X>, Signature1<T1>)
    { return Signature2<X, T1>(); }

struct Signature0 {};

template <class X>
inline Signature1<X> prepend(Type<X>, Signature0)
    { return Signature1<X>(); }


// This one terminates the chain. Prepending Void to the head of a Void
// signature results in a Void signature again.
inline Signature0 prepend(Void, Signature0) { return Signature0(); }

} // namespace detail

template <class A1 = detail::Void, class A2 = detail::Void, class A3 = detail::Void, class A4 = detail::Void, class A5 = detail::Void>
struct Constructor
{
};

namespace detail {

// Return value extraction:

// This is just another little envelope for carrying a typedef (see Type,
// above). I could have re-used Type, but that has a very specific purpose. I
// thought this would be clearer.
template <class T>
struct ReturnValue { typedef T Type; };

// free functions
template <class R>
ReturnValue<R> return_value(R (*)()) { return ReturnValue<R>(); }

template <class R, class A1>
ReturnValue<R> return_value(R (*)(A1)) { return ReturnValue<R>(); }

template <class R, class A1, class A2>
ReturnValue<R> return_value(R (*)(A1, A2)) { return ReturnValue<R>(); }

template <class R, class A1, class A2, class A3>
ReturnValue<R> return_value(R (*)(A1, A2, A3)) { return ReturnValue<R>(); }

template <class R, class A1, class A2, class A3, class A4>
ReturnValue<R> return_value(R (*)(A1, A2, A3, A4)) { return ReturnValue<R>(); }

template <class R, class A1, class A2, class A3, class A4, class A5>
ReturnValue<R> return_value(R (*)(A1, A2, A3, A4, A5)) { return ReturnValue<R>(); }

// TODO(?): handle 'const void'

// member functions
template <class R, class T>
ReturnValue<R> return_value(R (T::*)()) { return ReturnValue<R>(); }

template <class R, class T, class A1>
ReturnValue<R> return_value(R (T::*)(A1)) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2>
ReturnValue<R> return_value(R (T::*)(A1, A2)) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2, class A3>
ReturnValue<R> return_value(R (T::*)(A1, A2, A3)) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2, class A3, class A4>
ReturnValue<R> return_value(R (T::*)(A1, A2, A3, A4)) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2, class A3, class A4, class A5>
ReturnValue<R> return_value(R (T::*)(A1, A2, A3, A4, A5)) { return ReturnValue<R>(); }

template <class R, class T>
ReturnValue<R> return_value(R (T::*)() const) { return ReturnValue<R>(); }

template <class R, class T, class A1>
ReturnValue<R> return_value(R (T::*)(A1) const) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2>
ReturnValue<R> return_value(R (T::*)(A1, A2) const) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2, class A3>
ReturnValue<R> return_value(R (T::*)(A1, A2, A3) const) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2, class A3, class A4>
ReturnValue<R> return_value(R (T::*)(A1, A2, A3, A4) const) { return ReturnValue<R>(); }

template <class R, class T, class A1, class A2, class A3, class A4, class A5>
ReturnValue<R> return_value(R (T::*)(A1, A2, A3, A4, A5) const) { return ReturnValue<R>(); }

}} // namespace py::detail

#endif

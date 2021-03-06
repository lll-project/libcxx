//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <chrono>

// duration

// template <class Rep1, class Period, class Rep2>
//   duration<typename common_type<Rep1, Rep2>::type, Period>
//   operator%(const duration<Rep1, Period>& d, const Rep2& s)

#include <chrono>
#include <cassert>

int main()
{
    std::chrono::nanoseconds ns(15);
    ns = ns % 6;
    assert(ns.count() == 3);
}

//===----------------------------------------------------------------------===//
//
// ΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚThe LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <complex>

// template<class T>
//   complex<T>
//   cos(const complex<T>& x);

#include <complex>
#include <cassert>

#include "../cases.h"

template <class T>
void
test(const std::complex<T>& c, std::complex<T> x)
{
    assert(cos(c) == x);
}

template <class T>
void
test()
{
    test(std::complex<T>(0, 0), std::complex<T>(1, 0));
}

void test_edges()
{
    typedef std::complex<double> C;
    const double pi = std::atan2(+0., -0.);
    const unsigned N = sizeof(x) / sizeof(x[0]);
    for (unsigned i = 0; i < N; ++i)
    {
        std::complex<double> r = cos(x[i]);
        std::complex<double> t1(-imag(x[i]), real(x[i]));
        std::complex<double> z = cosh(t1);
        if (std::isnan(real(r)))
            assert(std::isnan(real(z)));
        else
        {
            assert(real(r) == real(z));
            assert(std::signbit(real(r)) == std::signbit(real(z)));
        }
        if (std::isnan(imag(r)))
            assert(std::isnan(imag(z)));
        else
        {
            assert(imag(r) == imag(z));
            assert(std::signbit(imag(r)) == std::signbit(imag(z)));
        }
    }
}

int main()
{
    test<float>();
    test<double>();
    test<long double>();
    test_edges();
}

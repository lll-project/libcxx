//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <codecvt>

// template <class Elem, unsigned long Maxcode = 0x10ffff,
//           codecvt_mode Mode = (codecvt_mode)0>
// class codecvt_utf8
//     : public codecvt<Elem, char, mbstate_t>
// {
//     // unspecified
// };

// Not a portable test

#include <codecvt>
#include <cassert>

int outstanding_news = 0;

void* operator new(std::size_t s) throw(std::bad_alloc)
{
    ++outstanding_news;
    return std::malloc(s);
}

void  operator delete(void* p) throw()
{
    if (p)
    {
        --outstanding_news;
        std::free(p);
    }
}

int main()
{
    assert(outstanding_news == 0);
    {
        typedef std::codecvt_utf8<wchar_t> C;
        C c;
        assert(outstanding_news == 0);
    }
    {
        typedef std::codecvt_utf8<wchar_t> C;
        std::locale loc(std::locale::classic(), new C);
        assert(outstanding_news != 0);
    }
    assert(outstanding_news == 0);
}

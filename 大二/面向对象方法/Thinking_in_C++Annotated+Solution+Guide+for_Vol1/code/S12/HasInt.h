//: S12:HasInt.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#ifndef HASINT_H
#define HASINT_H
#include <iosfwd>

class HasInt {
    int n;
public:
    HasInt(int i = 0);
    HasInt& operator++();
    const HasInt operator++(int);
    HasInt& operator--();
    const HasInt operator--(int);
    HasInt operator-() const;
    HasInt& operator+=(const HasInt&);
    HasInt& operator-=(const HasInt&);

    // Global Friends:
    friend std::ostream& operator<<(std::ostream&,
                                    const HasInt&);
    friend HasInt operator+(const HasInt&, const HasInt&);
    friend HasInt operator-(const HasInt&, const HasInt&);
};

inline
HasInt::HasInt(int i) {
    n = i;
}

inline
HasInt HasInt::operator-() const {
    return HasInt(-n);
}

inline
HasInt& HasInt::operator+=(const HasInt& h) {
    n += h.n;
    return *this;
}

inline
HasInt& HasInt::operator-=(const HasInt& h) {
    n -= h.n;
    return *this;
}

inline
HasInt& HasInt::operator++()
{
    ++n;
    return *this;
}

inline
const HasInt HasInt::operator++(int)
{
    const HasInt old = *this;
    ++(*this);  // HasInt::operator++()
    return old;
}                                         

inline
HasInt& HasInt::operator--()
{
    --n;
    return *this;
}

inline
const HasInt HasInt::operator--(int)
{
    const HasInt old = *this;
    --(*this);  // HasInt::operator--()
    return old;
}                                         

// Globals:
inline
HasInt operator+(const HasInt& h1, const HasInt& h2) {
    return HasInt(h1.n + h2.n);
}

inline
HasInt operator-(const HasInt& h1, const HasInt& h2) {
    return HasInt(h1.n - h2.n);
}
#endif
///:~

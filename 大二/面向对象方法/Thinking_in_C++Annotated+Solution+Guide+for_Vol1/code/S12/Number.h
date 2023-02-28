//: S12:Number.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#ifndef NUMBER_H
#define NUMBER_H
#include <cassert>

class Number {
    double val;
public:
    explicit Number(double x = 0.0) {
        val = x;
    }
    Number& operator+=(const Number& n) {
        val += n.val;
        return *this;
    }
    Number& operator-=(const Number& n) {
        val -= n.val;
        return *this;
    }
    Number& operator*=(const Number& n) {
        val *= n.val;
        return *this;
    }
    Number& operator/=(const Number& n) {
        assert(n.val != 0.0);
        val /= n.val;
        return *this;
    }
    operator double() const {
        return val;
    }
    
    friend Number operator+(const Number&,
                            const Number&);
    friend Number operator-(const Number&,
                            const Number&);
    friend Number operator*(const Number&,
                            const Number&);
    friend Number operator/(const Number&,
                            const Number&);
};

inline
Number operator+(const Number& n1, const Number& n2) {
    return Number(n1.val + n2.val);
}

inline
Number operator-(const Number& n1, const Number& n2) {
    return Number(n1.val - n2.val);
}

inline
Number operator*(const Number& n1, const Number& n2) {
    return Number(n1.val * n2.val);
}

inline
Number operator/(const Number& n1, const Number& n2) {
    assert(n2.val != 0.0);
    return Number(n1.val / n2.val);
}
#endif
///:~

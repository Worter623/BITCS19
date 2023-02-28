//: S12:HasInt.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include "HasInt.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const HasInt& h) {
    return os << h.n;
}
///:~

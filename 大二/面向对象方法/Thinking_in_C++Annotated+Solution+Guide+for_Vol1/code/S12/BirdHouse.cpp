//: S12:BirdHouse.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include "BirdHouse.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const BirdHouse& bh) {
    os << '{' << bh.val << ", " << *bh.ptr
       << ", " << bh.ref << '}';
    return os;
}
///:~

//: S12:Bird.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include "Bird.h"
#include <iostream>
#include <sstream>
using namespace std;

int Bird::birdNum = 0;

Bird::Bird() {
    ostringstream os;
    os << "Bird# " << ++birdNum;
    id = os.str();
}

ostream& operator<<(ostream& os, const Bird& b) {
    return os << b.id;
}
///:~

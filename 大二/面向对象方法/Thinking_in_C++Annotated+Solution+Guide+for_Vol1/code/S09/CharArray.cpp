//: S09:CharArray.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include "CharArray.h"
#include <iostream>
using namespace std;

void CharArray::print() const {
    for (int i = 0; i < MAX; ++i)
        cout << data[i];
    cout << endl;
} ///:~

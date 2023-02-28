//: S09:InternalLinkage.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

inline void f() {
    cout << "f() in InternalLinkage.cpp\n";
} ///:~

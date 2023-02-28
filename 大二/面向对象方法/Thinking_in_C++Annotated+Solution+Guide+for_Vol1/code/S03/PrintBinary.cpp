//: S03:PrintBinary.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <climits>
using namespace std;

void printBinary(unsigned char val) {
    for (int i = CHAR_BIT-1; i >= 0; i--)
        cout << "01"[!!(val & (1 << i))];
} ///:~

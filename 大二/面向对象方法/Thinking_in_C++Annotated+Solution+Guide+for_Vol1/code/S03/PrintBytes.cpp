//: S03:PrintBytes.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} PrintBinary
#include <iostream>
#include <cstddef> // For size_t
using namespace std;

void printBinary(unsigned char);

void printBytes(const void *p, size_t n) {
    const unsigned char* pByte =
        reinterpret_cast<const unsigned char*>(p);
    for (size_t i = 0; i < n; ++i)
        printBinary(pByte[i]);
    cout << endl;
}

int main() {
    float x = 128.0;
    printBytes(&x, sizeof x);
}
///:~

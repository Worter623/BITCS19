//: S09:CharArray.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <cstring>  // for memset()

// VC++ doesn't put memset in std
#ifndef _MSC_VER
using std::memset;
#endif

class CharArray {
    enum {MAX = 5};
    char data[5];
public:
    CharArray(char = ' ');
    void print() const;
};

inline CharArray::CharArray(char c) {
    memset(data, c, MAX);
} ///:~

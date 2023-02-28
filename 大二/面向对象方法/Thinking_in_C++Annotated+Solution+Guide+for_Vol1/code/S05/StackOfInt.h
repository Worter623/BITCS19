//: S05:StackOfInt.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <cstddef>  // for size_t
#include <climits>  // for INT_MIN
// VC++ doesn't put size_t in std:
#ifndef _MSC_VER
using std::size_t;
#endif

struct StackImp;    // Incomplete type declaration

struct StackOfInt {
    enum {STKERROR = INT_MIN};
    void init();
    void cleanup();
    int push(int);
    int pop();
    int top();
    size_t size();

private:
    StackImp* pImpl; // The "smile"
};
///:~

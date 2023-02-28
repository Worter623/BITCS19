//: S05:StackOfInt2.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Uses a vector to implement a stack
#include "StackOfInt.h"
#include <vector>
using namespace std;

// Complete the incomplete type StackImp:
// (This could be in a separate header file)
struct StackImp {
    enum {MAXSIZE = 100};
    vector<int> data;
};

void StackOfInt::init() {
    pImpl = new StackImp;
}

int StackOfInt::push(int x) {
    if (pImpl->data.size() == StackImp::MAXSIZE)
        return STKERROR;
    else {
        pImpl->data.push_back(x);
        return x;
    }
}

int StackOfInt::pop() {
    if (pImpl->data.size() == StackImp::MAXSIZE)
        return STKERROR;
    else {
        int x = pImpl->data.back();
        pImpl->data.pop_back();
        return x;
    }
}

int StackOfInt::top() {
    return (pImpl->data.size() == StackImp::MAXSIZE)
        ? STKERROR
        : pImpl->data.back();
}

size_t StackOfInt::size() {
    return pImpl->data.size();
}

void StackOfInt::cleanup() {
    delete pImpl;
}
///:~

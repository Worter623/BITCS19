//: S05:StackOfIntTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} StackOfInt2
#include "StackOfInt.h"
#include <iostream>

int main() {
    using namespace std;
    StackOfInt stk;
    
    stk.init();
    for (int i = 0; i < 5; ++i)
        stk.push(i);
    
    while (stk.size() > 0)
        cout << stk.pop() << endl;
} ///:~

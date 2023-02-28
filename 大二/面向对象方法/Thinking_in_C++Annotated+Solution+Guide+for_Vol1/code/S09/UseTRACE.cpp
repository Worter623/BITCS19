//: S09:UseTRACE.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

#define TRACE(s) cout << #s << endl, s

int main() {
    int x;
    TRACE(x = 7);
    cout << x << endl;
    TRACE(++x);
    cout << x << endl;
}

/* Output:
x = 7
7
++x
8
*/
///:~

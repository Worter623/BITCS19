//: S10:LocalStruct.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstddef> // For size_t

void f() {
    using namespace std;
    struct Int {
        int n;
        Int() : n(0) {}
    };
    
    Int a[3];
    size_t count = sizeof a / sizeof a[0];
    for (size_t i = 0; i < count; ++i)
        cout << a[i].n << ' ';
    cout << endl;
}

int main() {
    f();
}

/* Output:
0 0 0
*/
///:~

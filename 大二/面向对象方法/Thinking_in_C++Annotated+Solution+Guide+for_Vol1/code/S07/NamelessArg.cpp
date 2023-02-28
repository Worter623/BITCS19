//: S07:NamelessArg.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

void twoArgs(int i, float x) {
    cout << "twoArgs(" << i << ", " << x << ")\n";
}

void placeHolder(int i, float) {
    cout << "twoArgs(" << i << ",)\n";
}

int main() {
    twoArgs(1, 2);
    placeHolder(1, 2);
}

/* Output:
twoArgs(1, 2)
twoArgs(1,)
*/
///:~

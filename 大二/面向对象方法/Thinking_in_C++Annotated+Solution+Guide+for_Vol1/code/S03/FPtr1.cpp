//: S03:FPtr1.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

int round(double x) {
    // round to nearest int:
    return static_cast<int>(x + 0.5);
}

int main() {
    using namespace std;
    int (*fp)(double) = round;
    cout << fp(2.5) << endl;   // 3
}
///:~

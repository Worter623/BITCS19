//: S12:NumberTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include "Number.h"

// Macro and display function for convenience:
#define eval(expr) display(#expr, expr)

void display(const char* s, const Number& res) {
    using namespace std;
    cout << s << " = " << res << endl;
}

int main() {
    Number a(1.0), b(2.0);
    eval(a + b);
    eval(a - b);
    eval(a * b);
    eval(a / b);
    eval(a * (a + b) - (b - a) / b);
    a += b;
    eval(a);
    a -= b;
    eval(a);
    a *= b;
    eval(a);
    a /= b;
    eval(a);
}

/* Output:
a + b = 3
a - b = -1
a * b = 2
a / b = 0.5
a * (a + b) - (b - a) / b = 2.5
a = 3
a = 1
a = 2
a = 1
*/
///:~

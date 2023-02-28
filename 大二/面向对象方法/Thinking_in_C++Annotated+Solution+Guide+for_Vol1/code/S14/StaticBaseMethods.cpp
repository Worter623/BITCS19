//: S14:StaticBaseMethods.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Base {
public:
    static void f() {
        cout << "Base::f()\n";
    }
    static void g() {
        cout << "Base::g()\n";
    }
};

class Derived : public Base {
public:
    static void g(int) {
        cout << "Derived::g(int)\n";
    }
};

int main() {
    Derived::f();
    Derived::g(1);
    // Derived::g();   // Error: too few parameters
}

/* Output:
Base::f()
Derived::g(int)
*/
///:~

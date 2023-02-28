//: S15:InheritVirtuals.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Base {
public:
    virtual void f() {
        cout << "Base::f()\n";
    }
    virtual void g() {
        cout << "Base::g()\n";
    }
    virtual void h() {
        cout << "Base::h()\n";
    }
};

class Derived : public Base {
public:
    virtual void f() {
        cout << "Derived::f()\n";
    }
};

int main() {
    Derived d;
    Base* bp = &d;
    bp->f();
    bp->g();
    bp->h();
}

/* Output:
Derived::f()
Base::g()
Base::h()
*/
///:~

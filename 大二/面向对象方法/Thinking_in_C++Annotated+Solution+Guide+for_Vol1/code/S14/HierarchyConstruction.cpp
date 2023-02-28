//: S14:HierarchyConstruction.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;


class A {
public:
    A() {cout << "A::A()\n";}
    ~A() {cout << "A::~A()\n";}
};

class B : public A {
public:
    B() {cout << "B::B()\n";}
    ~B() {cout << "B::~B()\n";}
};

class C : public B {
public:
    C() {cout << "C::C()\n";}
    ~C() {cout << "C::~C()\n";}
};

int main() {
    C c;
}

/* Output:
A::A()
B::B()
C::C()
C::~C()
B::~B()
A::~A()
*/
///:~

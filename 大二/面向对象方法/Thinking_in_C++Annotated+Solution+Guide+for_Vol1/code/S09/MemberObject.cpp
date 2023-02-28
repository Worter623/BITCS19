//: S09:MemberObject.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class A {
public:
    A() {cout << "A()\n";}
};

class B {
    A a;
public:
    B() {cout << "B()\n";}
};

int main() {
    B b;
}

/* Output:
A()
B()
*/
///:~

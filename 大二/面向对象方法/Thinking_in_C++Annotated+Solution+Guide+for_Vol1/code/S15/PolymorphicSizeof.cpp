//: S15:PolymorphicSizeof.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstddef> // For size_t
using namespace std;

class Base {
    int x;
public:
    virtual size_t mySize() const {
        return sizeof *this;
    }
};

class Derived : public Base {
    float y;
public:
    size_t mySize() const {
        return sizeof *this;
    }
};

int main() {
    Base b;
    Derived d;
    cout << "b.mySize() == " << b.mySize() << endl;
    cout << "d.mySize() == " << d.mySize() << endl;
}

/* Output:
b.mySize() == 8
d.mySize() == 12
*/
///:~

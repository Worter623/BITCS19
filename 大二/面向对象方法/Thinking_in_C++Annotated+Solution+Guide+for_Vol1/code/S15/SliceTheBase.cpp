//: S15:SliceTheBase.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Base {
    int x;
};

class Derived : public Base {
    float y;
};

void mySize(Base b) {
    cout << "mySize == " << sizeof b << endl;
}

int main() {
    Base b;
    Derived d;
    cout << "sizeof b == " << sizeof b << endl;
    cout << "sizeof d == " << sizeof d << endl;
    mySize(b);
    mySize(d);
}

/* Output:
sizeof b == 4
sizeof d == 8
mySize == 4
mySize == 4
*/
///:~

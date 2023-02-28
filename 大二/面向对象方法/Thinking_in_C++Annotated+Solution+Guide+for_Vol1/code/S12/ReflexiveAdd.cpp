//: S12:ReflexiveAdd.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

class A {
    int n;
public:
    friend A operator+(const A&, const A&);
    A(int i) {
        n = i;
    }
    int toInt() const {
        return n;
    }
};

class B {
    int n;
public:
    B(int i) {
        n = i;
    }
    operator A() const {
        return A(n);
    }
};

A operator+(const A& a1, const A& a2) {
    return A(a1.n + a2.n);
}

int main() {
    using namespace std;
    A a(1);
    B b(2);
    cout << (a + b).toInt() << endl;
    cout << (b + a).toInt() << endl;
    cout << (a + 3).toInt() << endl;
    cout << (3 + b).toInt() << endl;
}

/* Output:
3
3
4
5
*/
///:~

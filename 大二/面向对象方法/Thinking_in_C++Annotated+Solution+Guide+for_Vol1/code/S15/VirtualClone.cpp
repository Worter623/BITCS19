//: S15:VirtualClone.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{-msc} VC++ doesn't implement the covariant return type
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base(){}
    virtual Base* clone() const {
        return new Base(*this);
    }
    virtual void f() {
        cout << "Base::f()\n";
    }
};

class Derived : public Base {
public:
    virtual Derived* clone() const {
        return new Derived(*this);
    }
    virtual void f() {
        cout << "Derived::f()\n";
    }
};

void invoke_f_and_die(Derived* d) {
    d->f();
    delete d;
}

int main() {
    Derived d;
    Base* d2 = d.clone();
    d2->f();
    delete d2;
    
    invoke_f_and_die(d.clone());
}

/* Output:
Derived::f()
Derived::f()
*/
///:~

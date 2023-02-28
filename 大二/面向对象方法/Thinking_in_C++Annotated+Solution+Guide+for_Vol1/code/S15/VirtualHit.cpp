//: S15:VirtualHit.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <ctime>
using namespace std;

class Base {
public:
    void nonvirt();
    virtual void virt();
};

void Base::nonvirt() {}
void Base::virt() {}

class Derived : public Base {};

double measure(Base* bp, void (Base::* f)()) {
    clock_t start = clock();
    for (int i = 0; i < 10000000L; ++i)
        (bp->*f)();
    clock_t stop = clock();
    return static_cast<double>(stop - start) / CLOCKS_PER_SEC;
}

int main() {
    Derived d;
    cout << measure(&d, &Base::nonvirt) << endl;
    cout << measure(&d, &Base::virt) << endl;
}

/* Output (yours will vary):
.34
.395
*/
///:~

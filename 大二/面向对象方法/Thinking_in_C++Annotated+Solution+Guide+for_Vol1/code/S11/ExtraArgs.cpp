//: S11:ExtraArgs.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class HasPointer {
    double* p;
public:
    HasPointer(double x) {
        p = new double(x);
    }
    HasPointer(const HasPointer& rhs, bool b = true) {
        p = new double(*rhs.p);
        if (b)
            cout << "copied a " << *p << endl;
    }
    ~HasPointer() {
        cout << "~HasPointer()\n";
        delete p;
    }
    void print() {
        cout << *p << endl;
    }
};

void f(HasPointer hp)
{
    hp.print();
}

int main() {
    HasPointer hp1(5);
    f(hp1);
    HasPointer hp2(hp1, false);
}

/* Output:
copied a 5
5
~HasPointer()
~HasPointer()
~HasPointer()
*/
///:~

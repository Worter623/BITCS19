//: S11:ShallowCopy.cpp
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
    HasPointer hp(5);
    f(hp);
}

/* Output:
5
~HasPointer()
~HasPointer()
<access violation error...!!!>
*/
///:~

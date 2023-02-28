//: S11:MemPtr.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class HasDouble {
public:
    double x;
    HasDouble(double x) {
        this->x = x;
    }
    void print() {
        using namespace std;
        cout << x << endl;
    }
};

int main() {
    HasDouble h(3);
    HasDouble* hp = &h;
    
    // Define pointers-to-members:
    double HasDouble::* px = &HasDouble::x;
    void (HasDouble::*pmf)() = &HasDouble::print;
    
    // Call via object:
    cout << h.*px << endl;
    (h.*pmf)();
    
    // Call via pointer-to-object:
    cout << hp->*px << endl;
    (hp->*pmf)();
}

/* Output:
3
3
3
3
*/
///:~

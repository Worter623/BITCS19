//: S05:MapMembers.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Mapped {
    int x;
    
protected:
    int y;

public:
    int z;
    
    void showMap() {
        cout << "x is at " << &x << endl;
        cout << "y is at " << &y << endl;
        cout << "z is at " << &z << endl;
    }
};

int main() {
    Mapped m;
    m.showMap();
}

/* Output:
// Compiler A:
x is at 0065FDF8
y is at 0065FDFC
z is at 0065FE00

// Compiler B:
x is at 0064FDEC
y is at 0064FDF0
z is at 0064FDF4
*/
///:~

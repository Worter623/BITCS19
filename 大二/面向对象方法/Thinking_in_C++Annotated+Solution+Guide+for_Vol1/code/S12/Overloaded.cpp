//: S12:Overloaded.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} HasInt
#include "HasInt.h"
#include <iostream>

int main() {
    using namespace std;

    HasInt x(1), y(2), z, w;
    cout << "x = " << x 
         << ", y = " << y
         << ", z = " << z
         << ", w = " << w
         << endl;
    
    w = ++x + y++ - --z;
    cout << "x = " << x 
         << ", y = " << y
         << ", z = " << z
         << ", w = " << w
         << endl;
    
    w = x - y;
    z = x + y;
    x += y;
    y -= x;
    cout << "x = " << x 
     << ", y = " << y
     << ", z = " << z
     << ", w = " << w
     << endl;
}

/* Output:
x = 1, y = 2, z = 0, w = 0
x = 2, y = 3, z = -1, w = 5 
x = 5, y = -2, z = 5, w = -1
*/
///:~

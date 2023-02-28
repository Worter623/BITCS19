//: S04:Sizeof.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

int main() {
    using namespace std;
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(long double) << endl;
}

/* Output:
1
2
4
4
4
8
8
*/
///:~

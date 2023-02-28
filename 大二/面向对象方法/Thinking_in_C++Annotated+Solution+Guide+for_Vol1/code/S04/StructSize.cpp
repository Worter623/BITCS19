//: S04:StructSize.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

struct DataOnly {
    int x;
};

struct Both {
    int x;
    void setX(int);
    int getX();
};

struct Nothing {
};

int main() {
    using namespace std;
    cout << sizeof(DataOnly) << endl;
    cout << sizeof(Both) << endl;
    cout << sizeof(Nothing) << endl;
}

/* Output:
4
4
1
*/
///:~

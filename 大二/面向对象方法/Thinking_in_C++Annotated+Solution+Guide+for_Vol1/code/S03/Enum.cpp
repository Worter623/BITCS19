//: S03:Enum.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

enum color {
    BLACK,
    RED,
    GREEN,
    BLUE,
    WHITE
};

int main() {
    using namespace std;
    for (int hue = BLACK; hue <= WHITE; ++hue)
        cout << hue << ' ';
}

/* Output:
0 1 2 3 4
*/
///:~

//: S11:CallByRef.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

void nextc(char& c) {
    static char letter = 'a';
    c = letter++;
}

int main() {
    using namespace std;
    char c = 'z';
    cout << "c == " << c << endl;
    nextc(c);
    cout << "c == " << c << endl;
    nextc(c);
    cout << "c == " << c << endl;
}

/* Output:
c == z
c == a
c == b
*/
///:~

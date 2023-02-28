//: S03:StringRef.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
using namespace std;

void stringRef(string& s) {
    s += " come blow";
}

void stringPtr(string* p) {
    p->append(" your horn");
}

int main() {
    string s = "Little Boy Blue";
    stringRef(s);
    stringPtr(&s);
    cout << s << endl;
}

/* Output:
Little Boy Blue come blow your horn
*/
///:~

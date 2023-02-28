//: S03:StringArray.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>

int main() {
    using namespace std;
    string stringArray[] = {"one", "small", "step",
                            "for", "man"};
    const int nStrings = sizeof stringArray
                       / sizeof stringArray[0];
    for (int i = 0; i < nStrings; ++i)
        cout << stringArray[i] << endl;
}

/* Output:
one
small
step
for
man
*/
///:~

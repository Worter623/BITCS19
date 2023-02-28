//: S08:StringLiteral.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

int main() {
    using namespace std;
    char* word = "hello";
    *word = 'j';
    cout << word << endl;
}

/* Output:
jello
*/
///:~

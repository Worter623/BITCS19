//: S04:StringCopy.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstring>
#include <cstddef> // For size_t
using namespace std;

char* copy(char* s1) {
    size_t len = strlen(s1);
    char* s2 = new char[len + 1];
    strcpy(s2, s1);
    return s2;
}
    
int main() {
    char* first = "Read my lips";
    char* second = copy(first);
    cout << "first == \"" << first << "\" at "
         << static_cast<void*>(first) << endl;
    cout << "second == \"" << second << "\" at "
         << static_cast<void*>(second) << endl;
    delete [] second;
}

/* Output:
first == "Read my lips" at 0041914C
second == "Read my lips" at 00673384
*/
///:~

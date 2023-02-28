//: S06:forScope.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

#if NEEDS_FIX
#define for if(0); else for
#endif

int main() {
    using namespace std;
    int i;
    for (i = 0; i < 10; ++i)
        cout << i << ' ';
    cout << endl;
    
    for (int i = 0; i < 10; ++i)
        cout << i << ' ';
    cout << endl;
}

/* Expected output:
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
*/
///:~

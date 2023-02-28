//: S09:UseDEBUG.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
#include <cstddef> // For size_t
using namespace std;

#define DEBUG(x) cout << #x " = " << x << endl

int main(int argc, char* argv[]) {
    if (argc > 1) {
        string s(argv[1]);
        size_t siz = s.size();
        for (size_t n = 0; n < siz; ++n) {
            s = s.erase(siz - n - 1, 1);
            DEBUG(s);
        }
    }
}

/* Sample execution:
> UseDEBUG disappear
s = disappea
s = disappe
s = disapp
s = disap
s = disa
s = dis
s = di
s = d
s = 
*/
///:~

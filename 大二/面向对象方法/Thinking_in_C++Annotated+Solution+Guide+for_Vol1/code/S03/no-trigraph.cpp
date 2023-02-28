//: S03:no-trigraph.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    using namespace std;
    unsigned int n;
    if (argc != 2 || (n = atoi(argv[1])) <= 0)
        return 1;
    cout << ~(n ^ 0xf0f0) << '\n';
    return 0;
}
///:~

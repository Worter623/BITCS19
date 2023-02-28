//: S09:TrackTime.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <ctime>
using namespace std;

void f1() {
    int i = 1;
    float x = i;
    i = static_cast<int>(x);
}

inline void f2() {
    int i = 1;
    float x = i;
    i = static_cast<int>(x);
}

int main() {
    // Time f1:
    clock_t start = clock();
    for (int i = 0; i < 10000000; ++i)
        f1();
    clock_t stop = clock();
    float ticks = stop - start;
    cout << "Time for f1: " << ticks / CLOCKS_PER_SEC << endl;
    
    // Time f1:
    start = clock();
    for (int i = 0; i < 10000000; ++i)
        f2();
    stop = clock();
    ticks = stop - start;
    cout << "Time for f2: " << ticks / CLOCKS_PER_SEC << endl;
}

/* Output: Compiler A
Time for f1: 0.43
Time for f2: 0.165

   Output: Compiler B:
Time for f1: 2.25
Time for f2: 1.87
*/
///:~

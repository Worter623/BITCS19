//: S12:TheBirds.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} Bird BirdHouse
#include "BirdHouse.h"
#include <iostream>

int main() {
    using namespace std;
    Bird a, b, c;
    BirdHouse bh(a, &b, c);
    cout << bh << endl;
}

/* Output:
{Bird# 1, Bird# 2, Bird# 3}
*/
///:~

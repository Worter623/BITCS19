//: S03:MapFloat.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} PrintBinary
#include <iostream>

void printBinary(unsigned char);

int main() {
    using namespace std;
    float x = 128.0;
    unsigned char* p = reinterpret_cast<unsigned char*>(&x);
    for (int i = 0; i < sizeof(float); ++i)
        printBinary(p[i]);
    cout << endl;
}

/* Output:
00000000000000000000000001000011
*/
///:~

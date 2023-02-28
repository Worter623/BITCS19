//: S03:IEEEFloat.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <climits>
using namespace std;

void ieeePrint(float x) {
    unsigned char* p = reinterpret_cast<unsigned char*>(&x);
    int bitno = 0;
        
    for (int i = sizeof(float)-1; i >= 0; --i) {
        for (int j = CHAR_BIT-1; j >= 0; --j, ++bitno) {
            cout << !!(p[i] & (1 << j));
            if (bitno == 0 || bitno == 8)  // IEEE boundaries
                cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    ieeePrint(2.0);
    ieeePrint(6.5);
    ieeePrint(-6.5);
}

/* Output:
0 10000000 00000000000000000000000
0 10000001 10100000000000000000000
1 10000001 10100000000000000000000
*/
///:~

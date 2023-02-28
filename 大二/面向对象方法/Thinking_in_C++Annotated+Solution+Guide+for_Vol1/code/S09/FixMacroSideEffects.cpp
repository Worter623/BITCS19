//: S09:FixMacroSideEffects.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

inline int band(int x) {
    return (x > 5 && x < 10) ? x : 0;
}

int main() {
    using namespace std;
    for(int i = 4; i < 11; i++) {
        int a = i;
        cout << "a = " << a << endl << '\t';
        cout << "band(++a)=" << band(++a) << endl;
        cout << "\t a = " << a << endl;
    }
}
 
/* Output:
a = 4
  band(++a)=0
   a = 5
a = 5
  band(++a)=6
   a = 6
a = 6
  band(++a)=7
   a = 7
a = 7
  band(++a)=8
   a = 8
a = 8
  band(++a)=9
   a = 9
a = 9
  band(++a)=0
   a = 10
a = 10
  band(++a)=0
   a = 11
*/
///:~

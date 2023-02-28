//: S07:DefaultArgs.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class DefaultArgs {
public:
    void f(int i = 0, int j = 0, int k = 0) {
        cout << "{" << i << ", " << j << ", " << k << "}\n";
    }
};

int main() {
    DefaultArgs a;
    a.f();
    a.f(1);
    a.f(1, 2);
    a.f(1, 2, 3);
}

/* Output:
{0, 0, 0}
{1, 0, 0}
{1, 2, 0}
{1, 2, 3}
*/
///:~

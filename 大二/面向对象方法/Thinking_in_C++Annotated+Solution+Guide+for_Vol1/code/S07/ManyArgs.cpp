//: S07:ManyArgs.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class ManyArgs {
public:
    void f() {
        cout << "{}\n";
    }
    void f(int i) {
        cout << "{" << i << "}\n";
    }
    void f(int i, int j) {
        cout << "{" << i << ", " << j << "}\n";
    }
    void f(int i, int j, int k) {
        cout << "{" << i << ", " << j << ", " << k << "}\n";
    }
};

int main() {
    ManyArgs a;
    a.f();
    a.f(1);
    a.f(1, 2);
    a.f(1, 2, 3);
}

/* Output:
{}
{1}
{1, 2}
{1, 2, 3}
*/
///:~

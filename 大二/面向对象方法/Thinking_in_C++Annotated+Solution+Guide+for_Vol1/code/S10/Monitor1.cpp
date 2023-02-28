//: S10:Monitor1.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

class Monitor {
    int count;
public:
    Monitor() {
        count = 0;
    }
    void incident() {
        ++count;
    }
    void print() {
        std::cout << count << " incidents\n";
    }
};

void f() {
    static Monitor m;
    m.incident();
    m.print();
}

int main() {
    using namespace std;
    for (int i = 0; i < 5; ++i)
        f();
}

/* Output:
1 incidents
2 incidents
3 incidents
4 incidents
5 incidents
*/
///:~

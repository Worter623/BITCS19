//: S10:Monitor3.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cassert>

class Monitor1 {
    int count;
public:
    Monitor1() {
        count = 0;
    }
    void incident() {
        ++count;
    }
    void decrement() {
        --count;
    }
    void print() {
        std::cout << count << " incidents\n";
    }
};

class Monitor2 {
    Monitor1* pm;
public:
    Monitor2(Monitor1* p) {
        assert(p);
        pm = p;
        pm->incident();
        pm->print();
    }
    ~Monitor2() {
        assert(pm);
        pm->decrement();
        pm->print();
    }
};

Monitor1 g_mon1;
Monitor2 g_mon2(&g_mon1);

int main() {
}

/* Output:
1 incidents
0 incidents
*/
///:~

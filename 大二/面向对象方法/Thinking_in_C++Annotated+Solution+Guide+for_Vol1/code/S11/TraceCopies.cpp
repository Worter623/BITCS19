//: S11:TraceCopies.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Trace {
    int n;
public:
    Trace(int n) {
        cout << "Trace::Trace(" << n << ")\n";
        this->n = n;
    }
    Trace(const Trace& t) {
        cout << "Trace::Trace(const Trace&)\n";
        n = t.n;
    }
    int getN() const {
        return n;
    }
};

void f(Trace t) {
    cout << "f(" << t.getN() << ")\n";
}

Trace g() {
    Trace t(2);
    return t;
}

Trace h(int n) {
    return n;
}

int main() {
    Trace t1 = 1;
    f(t1);
    Trace t2 = g();
    Trace t3 = h(3);
}

/* Output:

 * Compiler A:
Trace::Trace(1)
Trace::Trace(const Trace&)
f(1)
Trace::Trace(2)
Trace::Trace(const Trace&)
Trace::Trace(const Trace&)
Trace::Trace(3)
Trace::Trace(const Trace&)

 * Compiler B:
Trace::Trace(1)
Trace::Trace(const Trace&)
f(1)
Trace::Trace(2)
Trace::Trace(const Trace&)
Trace::Trace(3)
*/
///:~

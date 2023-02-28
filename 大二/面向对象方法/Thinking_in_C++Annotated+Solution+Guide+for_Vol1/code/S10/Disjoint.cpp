//: S10:Disjoint.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include "MyNames2.h"

namespace MNS = MyNamespace;

void byScope() {
    MNS::f();
}

void byDirective() {
    using namespace MNS;
    g();
}

int main() {
    byScope();
    byDirective();
}

/* Output:
MyNameSpace::f()
MyNameSpace::g()
*/
///:~

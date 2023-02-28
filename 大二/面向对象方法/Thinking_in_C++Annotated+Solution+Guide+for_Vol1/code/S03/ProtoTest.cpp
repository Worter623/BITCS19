//: S03:ProtoTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} Prototypes
#include "Prototypes.h"

int main() {
  f(1);
  g(1.5);
  h('c');
  k();
}

/* Output:
f(1) returning void
g(1.5) returning int
h(c) returning float
k() returning char
*/
///:~

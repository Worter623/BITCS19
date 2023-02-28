//: S03:Prototypes.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Implements functions declared in Prototypes.h
#include <iostream>
using namespace std;

void f(int i) {
  cout << "f(" << i << ") returning void\n";
}


int g(float x) {
  cout << "g(" << x << ") returning int\n";
  return 0;
}

float h(char c) {
  cout << "h(" << c << ") returning float\n";
  return 1.5;
}

char k(void) {   // same as char k()
  cout << "k() returning char\n";
  return 'a';
}
///:~

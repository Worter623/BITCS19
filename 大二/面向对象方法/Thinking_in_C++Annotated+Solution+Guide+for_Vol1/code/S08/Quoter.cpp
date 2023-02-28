//: S08:Quoter.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Quoter {
  mutable int lastquote;
public:
  Quoter();
  int lastQuote() const;
  const char* quote() const;
}; ///:~

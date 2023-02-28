//: S15:PolymorphicWhatAmI.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <typeinfo>
using namespace std;

class Shape {
public:
  enum Id {Circles, Squares}; // The IDs
Shape() {};
  virtual Id whatAmI() = 0;
};
class Circle : public Shape {
public:
  virtual Id whatAmI() {
    return Circles;
  }
};
class Square : public Shape {
public:
  virtual Id whatAmI() {
    return Squares;
  }
};

int main() {
  Circle c;
  Shape* s = &c;

  if(s->whatAmI() == Shape::Circles)
    cout << "It's a circle!" << endl;
  else if(s->whatAmI() == Shape::Squares)
    cout << "It's a square!" << endl;
}

/* Output:
It's a circle!
*/ ///:~

//: S14:Proxy.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Subject {
public:
  virtual void f() = 0;
  virtual void g() = 0;
  virtual void h() = 0;
};

class Proxy : public Subject {
  Subject* pSubject;
public:
  Proxy(Subject* pSubject = 0) {
    this->pSubject = pSubject;
  }
  void setSubject(Subject* pSubject)  {
    this->pSubject = pSubject;
  }
  void f() {
    pSubject->f();
  }
  void g() {
    pSubject->g();
  }
  void h() {
    pSubject->h();
  }
};


class Implementation1 : public Subject {
public:
  void f() {
    cout << "Implementation1::f\n";
  }
  void g() {
    cout << "Implementation1::g\n";
  }
  void h() {
    cout << "Implementation1::h\n";
  }
};

class Implementation2 : public Subject {
public:
  void f() {
    cout << "Implementation2::f\n";
  }
  void g() {
    cout << "Implementation2::g\n";
  }
  void h() {
    cout << "Implementation2::h\n";
  }
};

int main() {
  Implementation1 impl1;
  Proxy proxy(&impl1);
  proxy.f();
  proxy.g();
  proxy.h();

  Implementation2 impl2;
  proxy.setSubject(&impl2);
  proxy.f();
  proxy.g();
  proxy.h();
} ///:~

//: S12:PointerToMemberOperator.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Dog {
public:
  void bark() const { 
    cout << "bark\n";  
  }
  void yip() const { 
    cout << "yip\n";  
  }
  typedef void (Dog::*PMF)(void) const;
  
  class FunctionObject {
    Dog* ptr;
    PMF pmem;
  public:
    FunctionObject(Dog* wp, PMF pmf) 
      : ptr(wp), pmem(pmf) { 
      cout << "FunctionObject constructor\n";
    }
    void operator()() const {
      cout << "FunctionObject::operator()\n";
      (ptr->*pmem)();
    }
  };
  FunctionObject operator->*(PMF pmf) { 
    cout << "operator->*" << endl;
    return FunctionObject(this, pmf);
  }
};
 
int main() {
  Dog w;
  Dog::PMF pmf = &Dog::bark;
  (w->*pmf)();
  pmf = &Dog::yip;
  (w->*pmf)();
}
 
/* Output:
operator->*
FunctionObject constructor
FunctionObject::operator()
bark
operator->*
FunctionObject constructor
FunctionObject::operator()
yip
*/
///:~

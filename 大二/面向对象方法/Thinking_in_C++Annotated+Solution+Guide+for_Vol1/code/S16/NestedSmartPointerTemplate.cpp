//: S16:NestedSmartPointerTemplate.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Obj {
  static int i, j;
public:
  void f() { cout << i++ << endl; }
  void g() { cout << j++ << endl; }
};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

// Container:
template<typename T>
class ObjContainer {
  vector<T*> a;
public:
  void add(T* obj) { a.push_back(obj); }
  class SmartPointer;
  friend class SmartPointer;
  class SmartPointer {
    ObjContainer& oc;
    unsigned int index;
  public:
    SmartPointer(ObjContainer& objc) : oc(objc) {
      index = 0;
    }
    // Return value indicates end of list:
    bool operator++() { // Prefix
      if(index >= oc.a.size()) return false;
      if(oc.a[++index] == 0) return false;
      return true;
    }
    bool operator++(int) { // Postfix
      return operator++(); // Use prefix version
    }
    T* operator->() const {
      assert(oc.a[index] != 0);
      return oc.a[index];
    }
  };
  // Function to produce a smart pointer that 
  // points to the beginning of the ObjContainer:
  SmartPointer begin() { 
    return SmartPointer(*this);
  }
};

int main() {
  const int sz = 10;
  Obj o[sz];
  ObjContainer<Obj> oc;
  for(int i = 0; i < sz; i++)
    oc.add(&o[i]); // Fill it up
  ObjContainer<Obj>::SmartPointer sp = oc.begin();
  do {
    sp->f(); // Pointer dereference operator call
    sp->g();
  } while(++sp);
}

/* Output:
47
11
48
12
49
13
50
14
51
15
52
16
53
17
54
18
55
19
56
20
*/
///:~

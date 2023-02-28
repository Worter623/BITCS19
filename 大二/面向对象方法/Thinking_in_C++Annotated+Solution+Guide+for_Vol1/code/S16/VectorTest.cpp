//: S16:VectorTest.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{L} SelfCounter
#include "SelfCounter.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<SelfCounter> sc;
  for (int i = 0; i < 10; i++)
    sc.push_back(SelfCounter());
  // OK to peek(), result is a temporary:
  for (int k = 0; k < 10; k++) {
      cout << sc.back() << endl;
      sc.pop_back();
  }
}
///:~

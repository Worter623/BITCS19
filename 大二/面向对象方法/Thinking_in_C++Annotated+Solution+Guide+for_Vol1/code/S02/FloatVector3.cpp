//: S02:FloatVector3.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Squares a vector of floats
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Fill and print:
  vector<float> v;
  for (int i = 0; i < 25; ++i)
    v.push_back(i);
  for (int i = 0; i < v.size(); ++i) {
    if (i > 0)
      cout << ' ';
    cout << v[i];
  }

  // Square and print:
  for (int i = 0; i < v.size(); ++i)
    v[i] = v[i] * v[i];
  for (int i = 0; i < v.size(); ++i) {
    if (i > 0)
      cout << ' ';
    cout << v[i];
  }
} ///:~

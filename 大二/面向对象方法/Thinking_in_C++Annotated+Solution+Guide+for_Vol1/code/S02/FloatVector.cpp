//: S02:FloatVector.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Fills a vector of floats
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Fill vector:
  vector<float> v;
  for (int i = 0; i < 25; ++i)
    v.push_back(i + 0.5);

  // Display
  for (int i = 0; i < v.size(); ++i) {
    if (i > 0)
      cout << ' ';
    cout << v[i];
  }
  cout << endl;
}

/* Output:
0.5 1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5 11.5
12.5 13.5 14.5 15.5 16.5 17.5 18.5 19.5 20.5 21.5
22.5 23.5 24.5
*/ ///:~

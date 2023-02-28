//: S03:prime.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//  Tests numbers for primality
#include <iostream>
#include <cmath>    // for sqrt()

int main() {
  using namespace std;
  const int MAX = 100;

  // Print 2 as a prime:
  cout << "2 ";

  for (int i = 3; i <= MAX; i += 2) {
    float val = i; // Produce float value
    int mid = static_cast<int>(sqrt(val));
    int j;
    for (j = 3; j <= mid; j += 2)
      if (i % j == 0)
        break;

    if (j > mid)
      cout << i << ' ';
  }
  cout << endl;
} ///:~

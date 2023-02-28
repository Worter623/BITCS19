//: S02:FloatVector2.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Adds vectors
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<float> v1, v2;
  for (int i = 0; i < 25; ++i) {
    v1.push_back(i);
    v2.push_back(25-i-1);
  }

  // Form sum:
  vector<float> v3;
  for (int i = 0; i < v1.size(); ++i)
    v3.push_back(v1[i] + v2[i]);

  // Display:
  for (int i = 0; i < v1.size(); ++i) {
    cout << v1[i] << " + " << v2[i]
         << " = " << v3[i] << endl;
  }
}

/* Output:
0 + 24 = 24
1 + 23 = 24
2 + 22 = 24
3 + 21 = 24
4 + 20 = 24
5 + 19 = 24
6 + 18 = 24
7 + 17 = 24
8 + 16 = 24
9 + 15 = 24
10 + 14 = 24
11 + 13 = 24
12 + 12 = 24
13 + 11 = 24
14 + 10 = 24
15 + 9 = 24
16 + 8 = 24
17 + 7 = 24
18 + 6 = 24
19 + 5 = 24
20 + 4 = 24
21 + 3 = 24
22 + 2 = 24
23 + 1 = 24
24 + 0 = 24
*/ ///:~

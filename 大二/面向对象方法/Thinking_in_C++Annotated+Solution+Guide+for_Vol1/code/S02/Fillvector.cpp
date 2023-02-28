//: S02:Fillvector.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Copy an entire file into a vector of string
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  vector<string> v;
  ifstream in("Fillvector.cpp");
  string line;
  while(getline(in, line))
    v.push_back(line);

  // Print backwards:
  int nlines = v.size();
  for(int i = 0; i < nlines; i++) {
    int lineno = nlines-i-1;
    cout << lineno << ": " << v[lineno] << endl;
  }
} ///:~

//: S02:Fillvector2.cpp
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
  ifstream in("Fillvector2.cpp");
  string line;
  while(getline(in, line))
    v.push_back(line);
  
  // Put lines into a single string:
  string lines;
  for(int i = 0; i < v.size(); i++)
    lines += v[i] + "\n";
  cout << lines;
} ///:~

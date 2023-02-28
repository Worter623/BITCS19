//: S02:FileView.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Displays a file a line at a time
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream in("FileView.cpp");
  string line;
  while(getline(in, line)) {
    cout << line;  // No endl!
    cin.get();
  }
} ///:~

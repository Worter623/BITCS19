//: S02:Words.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream f("Words.cpp");
  int nwords = 0;
  string word;

  while (f >> word)
    ++nwords;

  cout << "Number of words = " << nwords << endl;
}

/* Output:
Number of words = 42
*/ ///:~

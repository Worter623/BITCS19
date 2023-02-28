//: S02:Words2.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{T} < Area.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  int nwords = 0;
  string word;

  while (cin >> word) {
    ++nwords;
  }

  cout << "Number of words = " << nwords << endl;
}

/* Sample Execution:
c:>words < Area.cpp
Number of words = 41
*/ ///:~

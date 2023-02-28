//: S02:WordCount.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Counts the occurrences of a word
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
  using namespace std;

  // Process command-line arguments:
  if (argc < 3) {
    cerr << "usage: WordCount word file\n";
    return -1;
  }
  string word(argv[1]);
  ifstream file(argv[2]);

  // Count occurrences:
  long wcount = 0;
  string token;
  while (file >> token)
    if (word == token)
      ++wcount;

  // Print result:
  cout << '"' << word << "\" appeared "
       << wcount << " times\n";
} ///:~

//: S02:Area.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{-T} @echo run Area by hand!
#include <iostream>
using namespace std;

int main() {
  const float pi = 3.141592654;
  cout << "Enter the radius: ";
  
  float radius;
  cin >> radius;
  cout << "The area is " << pi * radius * radius << endl;
}

/* Sample Execution:
c:>area
Enter the radius: 12
The area is 452.389
*/ ///:~

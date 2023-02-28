//: S03:AbusingTheLanguage.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Shows what happens when you run off the
// end of an array and other misbehavior.
#include <iostream>
using namespace std;

void print(char* name, int* array, int size) {
  for(int i = 0; i < size; i++)
    cout << name << "[" << i << "] (" 
         << (long)(&array[i]) << ") = " 
         << array[i] << endl;
}

// A preprocessor macro to simplify the printing
// of all the data in main():
#define PRT(A, B, C, D) \
  print(#A, A, sizeof A / sizeof *A); \
  print(#B, B, sizeof B / sizeof *B); \
  cout << #C " (" << (long)(&C) << ") = " \
       << C << endl; \
  print(#D, D, sizeof D / sizeof *D);

int main() {
  int a[] = { 1, 2, 3 };
  int b[] = { 4, 5, 6 };
  char c = 'x';
  int d[] = { 7, 8, 9 };
  PRT(a, b, c, d);
  cout << "Index off the end of a:\n";
  a[3] = 47;
  PRT(a, b, c, d);
  cout << "Index off the end of b:\n";
  b[3] = 27;
  PRT(a, b, c, d);
  cout << "Abuse c with pointers and casts:\n";
  *((double*)&c) = 99.99;
  PRT(a, b, c, d);
} ///:~

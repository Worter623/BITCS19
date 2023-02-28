//: S06:ArrayInit.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstddef> // For size_t
using namespace std;

// Function to print array of doubles:
void printDoubles(double a[] , size_t n) {
    for (size_t i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    double a[5] = {10.0, 20.0};  // pads with 0's
    size_t n = sizeof a / sizeof a[0];
    printDoubles(a, n);
    
    double b[] = {30.0, 40.0, 50.0};
    n = sizeof b / sizeof b[0];
    printDoubles(b, n);
}

/* Output:
10 20 0 0 0
30 40 50
*/
///:~

//: S16:SpecializeReturn.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cassert>
#include <cstddef> // For size_t
using namespace std;

template<typename T>
T Fib(size_t n) {
    const size_t sz = 100;
    static T f[sz];         // Initialized to zero
    
    static size_t nFilled = 2;
    f[0] = f[1] = 1;        // T must be convertible from int
    assert(n < sz);
    
    while (n >= nFilled) {
        cout << "growing to " << n << " (sizeof(T) == "
             << sizeof(T) << ")\n";
        f[nFilled] = f[nFilled-1] + f[nFilled-2];
        nFilled++;
    }
    return f[n];
}

int main() {
    for (size_t x = 9; x > 0; --x)
        cout << "Fib(" << x << ") == " << Fib<double>(x-1)
             << endl;
}

/* Output:
(same as before)
*/
///:~

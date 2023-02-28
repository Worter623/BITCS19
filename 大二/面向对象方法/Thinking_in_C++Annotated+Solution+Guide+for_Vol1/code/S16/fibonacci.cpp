//: S16:fibonacci.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cassert>
#include <cstddef> // For size_t
using namespace std;

template<typename T>
T Fib(const T& n) {
    const size_t sz = 100;
    static T f[sz];         // Initialized to zero
    
    static size_t nFilled = 2;
    f[0] = f[1] = 1;        // T must be convertible from int
    size_t int_n = size_t(n);
    assert(n < sz);
    
    while (int_n >= nFilled) {
        cout << "growing to " << n << " (sizeof(T) == "
             << sizeof(T) << ")\n";
        f[nFilled] = f[nFilled-1] + f[nFilled-2];
        nFilled++;
    }
    return f[int_n];
}

int main() {
    for (double x = 8.0; x >= 0.0; --x)
        cout << "Fib(" << x << ") == " << Fib(x) << endl;
}

/* Output:
growing to 8 (sizeof(T) == 8)
growing to 8 (sizeof(T) == 8)
growing to 8 (sizeof(T) == 8)
growing to 8 (sizeof(T) == 8)
growing to 8 (sizeof(T) == 8)
growing to 8 (sizeof(T) == 8)
growing to 8 (sizeof(T) == 8)
Fib(8) == 34
Fib(7) == 21
Fib(6) == 13
Fib(5) == 8
Fib(4) == 5
Fib(3) == 3
Fib(2) == 2
Fib(1) == 1
Fib(0) == 1
*/
///:~

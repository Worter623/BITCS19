//: S16:TemplateArray.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstddef> // For size_t
using namespace std;

template<typename T, size_t N>
class Array {
    T i[N];
public:
    Array() { memset(i, 0, N*sizeof(*i)); }
    T& operator[](int x) {
        assert(x >= 0 && x < N);
        return i[x];
    }
    // Inline member template definitions
    // (Tends to work with most compilers):
    friend ostream& 
    operator<<(ostream& os, const Array<T, N>& ia) {
        for (int j = 0; j < N; j++) {
            os << ia.i[j];
            if (j != N - 1)
                os << ", ";
        }
        os << endl;
        return os;
    }
    
    friend istream& 
    operator>>(istream& is, Array<T, N>& ia){
        for(int j = 0; j < N; j++)
            is >> ia.i[j];
        return is;
    }
    
    // Declarations for out-of line definitions
    // (Which don't work with many compilers):
    #if 0
    friend ostream&
    operator<<(ostream& os, const Array<T, N>& ia);
    friend istream&
    operator>>(istream& is, Array<T, N>& ia);
    #endif
};

// Out of line definitions:
#if 0
template<typename T, size_t N>
ostream& 
operator<<(ostream& os, const Array<T, N>& ia) {
    for (int j = 0; j < N; j++) {
        os << ia.i[j];
        if (j != N - 1)
            os << ", ";
    }
    os << endl;
    return os;
}

template<typename T, size_t N>
istream& operator>>(istream& is, Array<T, N>& ia){
    for(int j = 0; j < N; j++)
        is >> ia.i[j];
    return is;
}
#endif 

int main() {
    stringstream input("47 34 56 92 103");
    Array<int, 5> I;
    input >> I;
    I[4] = -1; // Use overloaded operator[]
    cout << I;
}
 
/* Output:
47, 34, 56, 92, -1
*/ 
///:~

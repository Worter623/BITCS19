//: S16:SafeVector.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{-msc} VC++ only fakes reinterpret_cast
#include <iostream>
#include <vector>
#include <string>
#include <cstddef> // For size_t
using namespace std;

template<typename T>
class SafeVector : private vector<void*> {
public:
    void push_back(T* s) {
        vector<void*>::push_back(s);
    }
    T*& operator[](size_t n) {
        return reinterpret_cast<T*>
                               (vector<void*>::operator[](n));
    }
    const T* operator[](size_t n) const {
        return reinterpret_cast<const T*> 
                               (vector<void*>::operator[](n));
    }
    using vector<void*>::size;
};

int main() {
    SafeVector<string> v;
    string s1("live"), s2("long"), s3("and"), s4("prosper");
    v.push_back(&s1);
    v.push_back(&s2);
    v.push_back(&s3);
    v.push_back(&s4);
    for (size_t i = 0; i < v.size(); ++i)
        cout << *v[i] << endl;
        
    // void* p = &s1;
    // v.push_back(p);  // error!!!
}

/* Outout:
live
long
and
prosper
*/
///:~

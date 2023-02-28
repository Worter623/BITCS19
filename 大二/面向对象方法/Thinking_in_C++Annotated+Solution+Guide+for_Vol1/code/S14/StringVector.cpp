//: S14:StringVector.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//{-msc} VC++ only fakes reinterpret_cast
#include <iostream>
#include <vector>
#include <string>
#include <cstddef> // For size_t
using namespace std;

class StringVector : public vector<void*> {
public:
    void push_back(string* s) {
        vector<void*>::push_back(s);
    }
    string*& operator[](size_t n) {
        return reinterpret_cast<string*>
                               (vector<void*>::operator[](n));
    }
    const string* operator[](size_t n) const {
        return reinterpret_cast<const string*> 
                               (vector<void*>::operator[](n));
    }
};

int main() {
    StringVector v;
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

/* Output:
live
long
and
prosper
*/
///:~

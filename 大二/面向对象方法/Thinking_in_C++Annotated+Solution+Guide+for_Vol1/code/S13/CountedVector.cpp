//: S13:CountedVector.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <vector>
#include <cstddef> // For size_t
using namespace std;

class Counted {
    int id;
    static int count;
public:
    Counted() : id(count++) {
        cout << "Creating Counted(" << id << ")\n";
    }
    ~Counted() {
        cout << "Destroying Counted(" << id << ")\n";
    }
    void f() {
        cout << "Hi! I'm #" << id << endl;
    }
};

int Counted::count = 0;

int main() {
    vector<Counted*> v;
    for (size_t i = 0; i < 3; ++i)
        v.push_back(new Counted);

    for (size_t i = 0; i < v.size(); ++i)
        v[i]->f();

    for (size_t i = 0; i < v.size(); ++i)
        delete v[i];
}

/* Output:
Creating Counted(0)
Creating Counted(1)
Creating Counted(2)
Hi! I'm #0
Hi! I'm #1
Hi! I'm #2
Destroying Counted(0)
Destroying Counted(1)
Destroying Counted(2)
*/
///:~

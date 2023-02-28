//: S13:PlacementNew.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <sstream>
#include <new>
#include <string>
#include <vector>
#include <cstddef> // For size_t
using namespace std;

class Track {
    static vector<string> allocs;
public:
    static void* operator new(size_t size, const char* file,
                              int line);
    static void display();
};

vector<string> Track::allocs;

void* Track::operator new(size_t size, const char* file,
                          int line) {
    ostringstream os;
    os << file << ", line " << line;
    allocs.push_back(os.str());
    return ::operator new(size);
}

void Track::display() {
    for (size_t i = 0; i < allocs.size(); ++i)
        cout << allocs[i] << endl;
}

// Preprocessor trick:
#define new new (__FILE__, __LINE__)

int main() {
    Track* t1 = new Track;
    Track* t2 = new Track;
    Track* t3 = new Track;
    Track::display();
    delete t3;
    delete t2;
    delete t1;
}

/* Output:
x14.cpp, line 34
x14.cpp, line 35
x14.cpp, line 36
*/
///:~

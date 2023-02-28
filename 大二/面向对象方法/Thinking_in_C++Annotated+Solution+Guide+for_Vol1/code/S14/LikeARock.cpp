//: S14:LikeARock.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <vector>
using namespace std;

class Rock {
public:
    Rock() {
        cout << "Rock()\n";
    }
    Rock(const Rock&) {
        cout << "Rock(const Rock&)\n";
    }
    Rock& operator=(const Rock&) {
        cout << "Rock()\n";
        return *this;
    }
    ~Rock() {cout << "~Rock()\n";}
};
    
int main() {
    vector<Rock> byValue;
    Rock r1, r2, r3;
    byValue.push_back(r1);
    byValue.push_back(r2);
    byValue.push_back(r3);
    cout << "byValue populated\n\n";
    
    vector<Rock*> byPtr;
    byPtr.push_back(&r1);
    byPtr.push_back(&r2);
    byPtr.push_back(&r3);
    cout << "byPtr populated\n\n";
}

/* Output:
Rock()
Rock()
Rock()
Rock(const Rock&)
Rock(const Rock&)
Rock(const Rock&)
byValue populated

byPtr populated

~Rock()
~Rock()
~Rock()
~Rock()
~Rock()
~Rock()
*/
///:~
